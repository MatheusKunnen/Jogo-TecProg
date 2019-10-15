cmake_minimum_required(VERSION 3.14)
project(Jogo_TecProg)

set(CMAKE_CXX_STANDARD 11)

#add_executable(Jogo_TecProg *.cpp)
add_executable(Jogo_TecProg ./cmake-build-debug/CMakeFiles/3.14.5/CompilerIdCXX/CMakeCXXCompilerId.cpp
        ./Jogo/Jogo.cpp
        ./Jogo/MediaEngineParameters.cpp
        ./Jogo/MediaEngine.hpp
        ./Jogo/base_includes.hpp
        ./Jogo/Resources/TexturesHolder.hpp
        ./Jogo/Resources/ResourcesHolder.hpp
        ./Jogo/Resources/TexturesHolder.cpp
        ./Jogo/States/GameState.hpp
        ./Jogo/States/State.cpp
        ./Jogo/States/MainMenuState.cpp
        ./Jogo/States/State.hpp
        ./Jogo/States/MainMenuState.hpp
        ./Jogo/States/GameState.cpp
        ./Jogo/GUI/Button.cpp
        ./Jogo/GUI/base_gui_includes.hpp
        ./Jogo/GUI/Button.hpp
        ./Jogo/Jogo.hpp
        ./Jogo/Entidades/Jogador.hpp
        ./Jogo/Entidades/Entidade.cpp
        ./Jogo/Entidades/Componentes/MoveComponent.cpp
        ./Jogo/Entidades/Componentes/MoveComponent.hpp
        ./Jogo/Entidades/Obstaculo.cpp
        ./Jogo/Entidades/Personagem.hpp
        ./Jogo/Entidades/Inimigo.cpp
        ./Jogo/Entidades/Personagem.cpp
        ./Jogo/Entidades/Inimigo.hpp
        ./Jogo/Entidades/Jogador.cpp
        ./Jogo/Entidades/Entidade.hpp
        ./Jogo/Entidades/Obstaculo.hpp
        ./Jogo/MediaEngineParameters.hpp
        ./Jogo/MediaEngine.cpp
        ./main.cpp

        )
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.4 REQUIRED system window graphics network audio)
#if (SFML_FOUND)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(Jogo_TecProg ${SFML_LIBRARIES})
#endif()
