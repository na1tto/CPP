#include <iostream>
#include <boost/asio.hpp>
#include <thread>

using boost::asio::ip::tcp;

void handle_client(tcp::socket socket){
    try{
        char data[1024];
        while (true)
        {
            std::memset(data, 0, sizeof(data));
            boost::system::error_code error;

            // ler a mensagem do client
            size_t length = socket.read_some(boost::asio::buffer(data), error);
            if (error == boost::asio::error::eof)
                break; // connection closed
            else if (error) throw boost::system::system_error(error);

            std::cout << "Cliente: " << data << std::endl;

            // enviar uma resposta
            std::string response;
            std::cout << "You: ";
            std::getline(std::cin, response);
            boost::asio::write(socket, boost::asio::buffer(response), error);
        }
    }
    catch (std::exception &e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main(){
    try{
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));

        std::cout << "Servidor iniciado, esperando pelo cliente..." << std::endl;

        tcp::socket socket(io_context);
        acceptor.accept(socket);
        std::cout << "Cliente conectado!" << std::endl;

        handle_client(std::move(socket));
    }
    catch (std::exception &e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}