#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <vector>

using boost::asio::ip::tcp;

void handle_client(tcp::socket socket) {
    try {
        char data[1024];
        while (true) {
            std::memset(data, 0, sizeof(data));
            boost::system::error_code error;

            size_t length = socket.read_some(boost::asio::buffer(data), error);
            if (error == boost::asio::error::eof) {
                std::cout << "Cliente desconectado." << std::endl;
                break;
            } else if (error) {
                throw boost::system::system_error(error);
            }

            std::cout << "Cliente (" << socket.remote_endpoint() << "): " << data << std::endl;
            
            // Simplesmente ecoa a mensagem de volta para o cliente.
            // Em um chat real, você enviaria para outros clientes.
            std::string response = "Mensagem recebida: ";
            response += data;
            boost::asio::write(socket, boost::asio::buffer(response), error);
        }
    } catch (std::exception& e) {
        std::cerr << "Excecao na thread do cliente: " << e.what() << std::endl;
    }
}

int main() {
    try {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));

        std::cout << "Servidor iniciado na porta 12345, esperando por clientes..." << std::endl;

        while (true) {
            // Cria um novo socket para o próximo cliente.
            tcp::socket socket(io_context);
            // Espera bloqueado até um cliente se conectar.
            acceptor.accept(socket);
            
            std::cout << "Cliente conectado: " << socket.remote_endpoint() << std::endl;

            // Cria uma nova thread para lidar com este cliente e a deixa rodando.
            // O servidor principal volta imediatamente para esperar por outra conexão.
            std::thread(handle_client, std::move(socket)).detach();
        }
    } catch (std::exception& e) {
        std::cerr << "Excecao no servidor: " << e.what() << std::endl;
    }
    return 0;
}