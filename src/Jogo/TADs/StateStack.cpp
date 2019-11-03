//
//  StateStack.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "StateStack.hpp"

namespace Game { namespace TADs {

StateStack::StateStack():
list_states()
{
    
}

StateStack::~StateStack(){
    this->list_states.clear();
}

// Methods
void StateStack::push(State *state){
    this->list_states.push(state);
}

State* StateStack::top() const {
    return this->list_states.top();
}

void StateStack::pop(){
    this->list_states.pop();
}

const bool StateStack::empty() const {
    return this->list_states.empty();
}
}};

