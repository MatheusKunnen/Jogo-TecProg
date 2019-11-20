//
//  State.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "State.hpp"
#include "StateManager.hpp"

namespace Game { namespace States {

State::State(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys, states_id id):
manager(handler),
id(id),
textures(),
supported_keys(supported_keys),
used_keys(),
g_grafico(g_grafico),
quit(false)
{
    this->g_grafico->resetDefaultView();
}

State::~State(){
    this->g_grafico = nullptr;
}

void State::endState(){
    this->quit = true;
}

const bool& State::isQuitting() const{
    return this->quit;
}

}};
