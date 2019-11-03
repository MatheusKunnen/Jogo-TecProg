//
//  StateStack.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef StateStack_hpp
#define StateStack_hpp

// Includes
#include "Pilha.hpp"
#include "../States/State.hpp"

namespace Game { namespace TADs {
// Usings
using States::State;

class StateStack {
private:
    Pilha<State>    list_states;
public:
    StateStack();
    ~StateStack();
    // Methods
    void push(State* state);
    State* top() const;
    void pop();
    const bool empty() const;
};

}};

#endif /* StateStack_hpp */
