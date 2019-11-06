//
//  Context.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/4/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Context.hpp"

namespace GUI {

// Constructor & Destructor
Context::Context(RenderWindow& window):
window(&window),
mouse_pos_view(),
mouse_pos_screen(),
mouse_pos_window()
{
    
}

Context::~Context(){
    this->window = nullptr;
}

// Methods
void Context::update(const float& dt){
    this->updateMousePos();
}

void Context::updateMousePos(){
    this->mouse_pos_screen = sf::Mouse::getPosition();
    this->mouse_pos_window = sf::Mouse::getPosition(*window);
    this->mouse_pos_view   = window->mapPixelToCoords(this->mouse_pos_window);
}

// Getters & Setters
const Vector2f& Context::getMousePosView() const {
    return this->mouse_pos_view;
}

RenderWindow* Context::getRenderWindow() const {
    return this->window;
}

}
