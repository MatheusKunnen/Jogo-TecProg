//
//  State.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "State.hpp"

namespace Game { namespace States {

State::State(RenderWindow* render_window, map<string, int>* supported_keys, stack<State*>* states_stack):
render_window(render_window),
textures(),
states_stack(states_stack),
supported_keys(supported_keys),
used_keys(),
quit(false)
{
    
}

State::~State(){
    this->render_window = nullptr;
}

void State::endState(){
    this->quit = true;
}

void State::updateMousePos(){
    this->mouse_pos_screen = sf::Mouse::getPosition();
    this->mouse_pos_window = sf::Mouse::getPosition(*this->render_window);
    this->mouse_pos_view   = this->render_window->mapPixelToCoords(this->mouse_pos_window);
}

void State::setRenderWindow(RenderWindow* render_window){
    this->render_window = render_window;
}

const RenderWindow* State::getRenderWindow() const{
    return this->render_window;
    
}

const bool& State::isQuitting() const{
    return this->quit;
}

}};
