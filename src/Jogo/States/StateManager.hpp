//
//  StateHandler.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef StateHandler_hpp
#define StateHandler_hpp

#include "State.hpp"

namespace Game { namespace States {

class StateManager {
public:
    StateManager() { };
    ~StateManager() { };
    virtual void pushTopState(states_id id) = 0;
    virtual void popTopState() = 0;
    virtual void addStatePop(int n_states = 1) = 0;
};
}};

#endif /* StateHandler_hpp */
