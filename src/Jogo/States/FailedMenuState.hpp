//
//  FailedMenuState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef FailedMenuState_hpp
#define FailedMenuState_hpp

#include "State.hpp"
#include "../Menus/FailedMenu.hpp"

namespace Game { namespace States {

// Usings
using Menus::FailedMenu;

class FailedMenuState : public State, public FailedMenu {
private:
    // Init methods
    void initValidKeys();
    
public:
    // Contructor & Destructor
    FailedMenuState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys);
    ~FailedMenuState();
    
    // Methods
    void updateKeyInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target);
    
    // Menu Methods
    void onExit();
};
}};

#endif /* FailedMenuState_hpp */
