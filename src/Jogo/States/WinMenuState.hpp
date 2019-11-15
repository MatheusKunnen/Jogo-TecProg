//
//  WinMenuState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef WinMenuState_hpp
#define WinMenuState_hpp

#include "State.hpp"
#include "../Menus/WinMenu.hpp"

namespace Game { namespace States {

// Usings
using Menus::WinMenu;

class WinMenuState : public State, public WinMenu{
private:
    // Init methods
    void initValidKeys();
    
public:
    // Contructor & Destructor
    WinMenuState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys);
    ~WinMenuState();
    
    // Methods
    void updateKeyInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target);
    
    // Menu Methods
    void onExit();
};
}};



#endif /* WinMenuState_hpp */
