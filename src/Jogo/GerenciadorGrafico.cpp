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
main_window(),
main_view()
{
    initWindow();
    initView();
}

GerenciadorGrafico::~GerenciadorGrafico(){

}

// Init methods
void GerenciadorGrafico::initWindow(){
    // Aloca RenderWindow
    this->main_window = new RenderWindow(sf::VideoMode(this->parameters.getWindowWidth(), this->parameters.getWindowHeight(), 32), this->parameters.getWindowTitle(), this->parameters.getStyle());
    // Set max framerate
    main_window->setFramerateLimit(this->parameters.getFrameRateLimit());
}

void GerenciadorGrafico::initView() {
    // Obtem View original do RenderWindow
    this->main_view = this->main_window->getView();
}

// Methods
bool GerenciadorGrafico::moveView(const float &x, const float &y){
    bool status = true;
    // Move a view
    this->main_view.move(x, y);
    // Verifica que a view nao se fique em posicoes negativas
    if (this->main_view.getCenter().x - this->main_window->getSize().x/2 < 0){
        this->main_view.move(this->main_window->getSize().x/2 - this->main_view.getCenter().x, 0);
        status = false;
    }
    if (this->main_view.getCenter().y - this->main_window->getSize().y/2 < 0) {
        this->main_view.move(0, this->main_window->getSize().y/2 - this->main_view.getCenter().y);
        status = false;
    }
    // Passa nova view para a RenderWindow
    this->main_window->setView(this->main_view);
    return status;
}

void GerenciadorGrafico::resetDefaultView(){
    try {
    this->main_view = this->main_window->getDefaultView();
    // Passa nova view para a RenderWindow
    this->main_window->setView(this->main_view);
    } catch (std::exception e){
        cerr << "ERROR: GerenciadorGrafico::resetDefaultView(): " << e.what() << endl;
    }
}

bool GerenciadorGrafico::inView(const Vector2f &position){
    return this->inView(position.x, position.y);
}

bool GerenciadorGrafico::inView(const float &x, const float &y){
    return (this->main_view.getCenter().x - this->main_window->getSize().x/2) < x
    && x < (this->main_view.getCenter().x - this->main_window->getSize().x/2) &&
    (this->main_view.getCenter().y - this->main_window->getSize().y/2) < y
    && y < (this->main_view.getCenter().y - this->main_window->getSize().y/2);
}

// Getters && Setters
RenderWindow* GerenciadorGrafico::getRenderWindow(){
    return this->main_window;
}

const View* GerenciadorGrafico::getView(){
    return &this->main_window->getView();
}
}
