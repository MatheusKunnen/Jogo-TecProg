//
//  MediaEngine.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "GerenciadorGrafico.hpp"
namespace Game {


// Singleton Methods
GerenciadorGrafico* GerenciadorGrafico::main_instance = nullptr;

GerenciadorGrafico* GerenciadorGrafico::getInstance(){
    if (GerenciadorGrafico::main_instance == nullptr)
        GerenciadorGrafico::main_instance = new GerenciadorGrafico();
    return GerenciadorGrafico::main_instance;
}

void GerenciadorGrafico::deleteInstance(){
    delete GerenciadorGrafico::main_instance;
    GerenciadorGrafico::main_instance = nullptr;
}

// Constructor & Destructor
GerenciadorGrafico::GerenciadorGrafico(const string& parameters_file):
parameters(parameters_file),
main_window()
{
    initWindow();
}

GerenciadorGrafico::~GerenciadorGrafico(){

}
// Init methods
void GerenciadorGrafico::initWindow(){
    this->main_window = new RenderWindow(sf::VideoMode(this->parameters.getWindowWidth(), this->parameters.getWindowHeight(), 32), this->parameters.getWindowTitle(), this->parameters.getStyle());
    // Set Window Size
    //this->main_window->setSize(sf::Vector2u(this->parameters.getWindowWidth(), this->parameters.getWindowHeight()));
    // Center Window
    /*auto desktop = sf::VideoMode::getDesktopMode();
    this->main_window->setPosition(sf::Vector2<int>(desktop.width/2 - main_window->getSize().x/2, desktop.height/2 - main_window->getSize().y/2));*/
    // Set max framerate
    main_window->setFramerateLimit(this->parameters.getFrameRateLimit());
}

RenderWindow* GerenciadorGrafico::getRenderWindow(){
    return this->main_window;
}

const View* GerenciadorGrafico::getView(){
    return &this->main_window->getView();
}
}
