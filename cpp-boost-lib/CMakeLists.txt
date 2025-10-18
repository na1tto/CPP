# Versão mínima e nome do projeto.
cmake_minimum_required(VERSION 3.15)
project(MeuProjetoBoost CXX)

# Define o padrão do C++.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- CONFIGURAÇÃO DE LINKAGEM ESTÁTICA ---
# Embutir as bibliotecas padrão do C++ e do GCC.
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

# Dica para o CMake encontrar pacotes no MSYS2.
if(MINGW)
    set(CMAKE_PREFIX_PATH "C:/msys64/ucrt64")
endif()

# --- ENCONTRAR DEPENDÊNCIAS ---
# Encontra a biblioteca Boost e seus componentes necessários.
find_package(Boost REQUIRED COMPONENTS asio system)

# [CORREÇÃO FINAL] Instrui o CMake a preferir a versão ESTÁTICA da biblioteca Threads.
set(Threads_PREFER_STATIC_LIBS ON)
# Encontra a biblioteca de Threads (necessária para std::thread com MinGW).
find_package(Threads REQUIRED)

# Mensagem de sucesso para confirmar que o Boost foi encontrado.
message(STATUS "Boost encontrado com sucesso: Versão ${Boost_VERSION_STRING}")

# --- CRIAR EXECUTÁVEIS ---
# Define executáveis separados para o servidor e para o cliente.
add_executable(servidor chat_server.cpp)
add_executable(cliente chat_client.cpp)

# --- VINCULAR BIBLIOTECAS ---
# Vincula as bibliotecas necessárias para o SERVIDOR.
target_link_libraries(servidor PRIVATE
    Boost::asio
    Boost::system
    ws2_32            # Biblioteca de Sockets do Windows
    Threads::Threads  # Biblioteca de Threads (agora estática)
)

# Vincula as bibliotecas necessárias para o CLIENTE.
target_link_libraries(cliente PRIVATE
    Boost::asio
    Boost::system
    ws2_32            # Biblioteca de Sockets do Windows
    Threads::Threads  # Biblioteca de Threads (agora estática)
)