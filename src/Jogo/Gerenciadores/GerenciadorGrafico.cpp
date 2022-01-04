//
//  MediaEngine.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "GerenciadorGrafico.hpp"
namespace Game { namespace Gerenciadores {

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
parametros(parameters_file),
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
    this->main_window = new RenderWindow(sf::VideoMode(this->parametros.getWindowWidth(), this->parametros.getWindowHeight(), 32), this->parametros.getWindowTitle(), this->parametros.getStyle());
    // Set max framerate
    if (this->parametros.getFrameRateLimit() > 0)
        main_window->setFramerateLimit(this->parametros.getFrameRateLimit());
}

void GerenciadorGrafico::initView() {
    // Obtem View original do RenderWindow
    this->main_view = this->main_window->getView();
}

// Private Methods
void GerenciadorGrafico::onViewUpdated() {
    this->main_window->setView(this->main_view);
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
    // Passa nova view para a RenderWindow
    this->onViewUpdated();
    return status;
}

void GerenciadorGrafico::resetDefaultView(){
    try {
        if (this->main_window == nullptr)
            return;
        
        this->main_view = this->main_window->getDefaultView();
        // Passa nova view para a RenderWindow
        this->main_window->setView(this->main_view);
    } catch (std::exception e){
        cerr << "ERROR: GerenciadorGrafico::resetDefaultView(): " << e.what() << endl;
    }
}

// Getters && Setters
RenderWindow* GerenciadorGrafico::getRenderWindow(){
    return this->main_window;
}

const View* GerenciadorGrafico::getView() const {
    return &this->main_window->getView();
}

void GerenciadorGrafico::setViewPosition(const Vector2f& position){
    this->setViewPosition(position.x, position.y);
}

void GerenciadorGrafico::setViewPosition(const float& x, const float& y){
    this->main_view.setCenter(x, y);
    this->onViewUpdated();
}

}}
