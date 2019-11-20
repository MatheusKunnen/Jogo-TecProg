//
//  StateHandler.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef StateHandler_hpp
#define StateHandler_hpp

#include "FaseState.hpp"
#include "../Menus/MainMenu.hpp"
#include "../Menus/GameMenu.hpp"
#include "../Menus/ConfigMenu.hpp"
#include "../Menus/PauseMenu.hpp"
#include "../Menus/EndGameMenu.hpp"
#include "../Menus/MainMenu.hpp"
#include "../Menus/FailedMenu.hpp"
#include "../Menus/WinMenu.hpp"
#include "../Menus/RankingMenu.hpp"

#include "../TADs/StateStack.hpp"

namespace Game { namespace States {

using TADs::StateStack;

class StateManager {
protected:
    StateStack                  states; // Pilha de estados
    
public:
    StateManager();
    ~StateManager();
    virtual void pushTopState(states_id id) = 0;
    virtual void popTopState() = 0;
    virtual void addStatePop(int n_states = 1) = 0;
};
}};

#endif /* StateHandler_hpp */
