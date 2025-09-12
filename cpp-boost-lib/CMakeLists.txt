# Versão mínima e nome do projeto.
cmake_minimum_required(VERSION 3.15)
project(MeuProjetoBoost CXX)

# Define o padrão do C++.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dica para o CMake encontrar pacotes no MSYS2.
if(MINGW)
    set(CMAKE_PREFIX_PATH "C:/msys64/ucrt64")
endif()

# Encontra a biblioteca Boost usando o módulo de busca antigo "FindBoost.cmake".
find_package(Boost REQUIRED COMPONENTS asio)

# Mensagem de sucesso para confirmar que funcionou.
message(STATUS "Boost encontrado com sucesso: Versão ${Boost_VERSION_STRING}")

# Cria e vincula o executável.
add_executable(chatsys chat_server.cpp)
target_link_libraries(chatsys PRIVATE 
    Boost::asio
    ws2_32
)