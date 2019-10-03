//
//  MediaEngine.cpp
//  SFML-Test
//
//  Created by Matheus Kunnen Ledesma on 10/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "MediaEngine.hpp"
namespace Jogo {

MediaEngine* MediaEngine::main_instance = nullptr;

MediaEngine* MediaEngine::getInstance(){
    if (MediaEngine::main_instance == nullptr)
        MediaEngine::main_instance = new MediaEngine();
    return MediaEngine::main_instance;
}

}
