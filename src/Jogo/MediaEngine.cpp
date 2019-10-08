//
//  MediaEngine.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "MediaEngine.hpp"
namespace Game {


// Singleton Methods
MediaEngine* MediaEngine::main_instance = nullptr;

MediaEngine* MediaEngine::getInstance(){
    if (MediaEngine::main_instance == nullptr)
        MediaEngine::main_instance = new MediaEngine();
    return MediaEngine::main_instance;
}

void MediaEngine::deleteInstance(){
    delete MediaEngine::main_instance;
    MediaEngine::main_instance = nullptr;
}

// Constructor & Destructor
MediaEngine::MediaEngine(const string& parameters_file):
parameters(parameters_file),
main_window()
{
    initWindow();
}

MediaEngine::~MediaEngine(){

}
// Init methods
void MediaEngine::initWindow(){
    this->main_window = new RenderWindow(sf::VideoMode(this->parameters.getWindowWidth(), this->parameters.getWindowHeight()), this->parameters.getWindowTitle());
    // Set Window Size
    this->main_window->setSize(sf::Vector2u(this->parameters.getWindowWidth(), this->parameters.getWindowHeight()));
    // Center Window
    auto desktop = sf::VideoMode::getDesktopMode();
    this->main_window->setPosition(sf::Vector2<int>(desktop.width/2 - main_window->getSize().x/2, desktop.height/2 - main_window->getSize().y/2));
    // Set max framerate
    main_window->setFramerateLimit(60);
}

RenderWindow* MediaEngine::getRenderWindow(){
    return this->main_window;
}

}
