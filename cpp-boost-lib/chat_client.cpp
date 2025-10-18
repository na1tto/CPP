#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <atomic>

using boost::asio::ip::tcp;

// Usamos uma variável atômica para sinalizar quando a conexão deve ser encerrada.
std::atomic<bool> done = false;

// Thread 1: Apenas lê mensagens do servidor e as exibe.
void read_loop(tcp::socket& socket) {
    try {
        char data[1024];
        while (!done) {
            std::memset(data, 0, sizeof(data));
            boost::system::error_code error;

            size_t length = socket.read_some(boost::asio::buffer(data), error);
            
            // Se o servidor fechar a conexão (EOF) ou ocorrer outro erro, encerramos.
            if (error) {
                std::cout << "Conexao perdida com o servidor." << std::endl;
                done = true; // Sinaliza para a outra thread terminar.
                break;
            }

            std::cout << "\rServidor: " << data << std::endl << "Voce: " << std::flush;
        }
    } catch (std::exception& e) {
        if (!done) { // Só mostra o erro se não for um encerramento esperado.
            std::cerr << "Excecao na leitura: " << e.what() << std::endl;
        }
        done = true;
    }
}

// Thread 2: Apenas lê a entrada do teclado e a envia para o servidor.
void write_loop(tcp::socket& socket) {
    try {
        std::string message;
        while (!done) {
            std::getline(std::cin, message);
            if (done) break; // Verifica novamente caso a outra thread tenha encerrado.

            boost::system::error_code error;
            boost::asio::write(socket, boost::asio::buffer(message), error);

            if (error) {
                std::cerr << "Erro ao enviar mensagem: " << error.message() << std::endl;
                done = true; // Sinaliza para a outra thread terminar.
                break;
            }
        }
    } catch (std::exception& e) {
        if (!done) {
            std::cerr << "Excecao na escrita: " << e.what() << std::endl;
        }
        done = true;
    }
}

int main() {
    try {
        std::string hostname, port;

        std::cout << "Insira o hostname do servidor (ex: 0.tcp.ngrok.io): ";
        std::cin >> hostname;
        std::cout << "Insira a porta do servidor (ex: 19384): ";
        std::cin >> port;

        boost::asio::io_context io_context;

        // O Resolver traduz o hostname e a porta em um endpoint conectável.
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(hostname, port);

        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints); // Tenta se conectar a cada endpoint encontrado.

        std::cout << "Conectado ao servidor! Voce pode comecar a digitar." << std::endl;
        std::cout << "Voce: " << std::flush;

        // Inicia as duas threads, uma para ler e outra para escrever.
        std::thread reader_thread(read_loop, std::ref(socket));
        std::thread writer_thread(write_loop, std::ref(socket));
        
        // Espera as threads terminarem.
        reader_thread.join();
        writer_thread.join();

    } catch (std::exception& e) {
        std::cerr << "Excecao no servidor: " << e.what() << std::endl;
    }

    std::cout << "Programa encerrado." << std::endl;
    return 0;
}