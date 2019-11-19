//
//  PauseMenuState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef PauseMenuState_hpp
#define PauseMenuState_hpp

#include "State.hpp"
#include "../Menus/PauseMenu.hpp"

namespace Game { namespace States {

// Usings
using Menus::PauseMenu;

class PauseMenuState : public State, public PauseMenu{
private:
    // Init methods
    void initValidKeys();
    
public:
    // Contructor & Destructor
    PauseMenuState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys);
    ~PauseMenuState();
    
    // Methods
    void updateKeyInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target);
    
    // Menu Methods
    void onResumeGame();
    void onExit();
};
}};

#endif /* PauseMenuState_hpp */