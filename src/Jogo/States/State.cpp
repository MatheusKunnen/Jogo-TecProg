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

State::State(StateManager* handler, states_id id):
manager(handler),
id(id),
quit(false)
{
    GerenciadorGrafico::getInstance()->resetDefaultView();
}

State::~State(){
    
}

void State::endState(){
    this->quit = true;
}

const bool& State::isQuitting() const{
    return this->quit;
}

}};
