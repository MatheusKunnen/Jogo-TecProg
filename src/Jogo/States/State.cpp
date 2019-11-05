//
//  State.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "State.hpp"

namespace Game { namespace States {

State::State(StateHandler* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys, states_id id):
handler(handler),
id(id),
textures(),
supported_keys(supported_keys),
used_keys(),
g_grafico(g_grafico),
quit(false)
{
    
}

State::~State(){
    this->g_grafico = nullptr;
}

void State::endState(){
    this->quit = true;
}

void State::updateMousePos(){
    this->mouse_pos_screen = sf::Mouse::getPosition();
    this->mouse_pos_window = sf::Mouse::getPosition(*this->g_grafico->getRenderWindow());
    this->mouse_pos_view   = this->g_grafico->getRenderWindow()->mapPixelToCoords(this->mouse_pos_window);
}

const bool& State::isQuitting() const{
    return this->quit;
}

}};
