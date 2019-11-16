//
//  ConfigMenuState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef ConfigMenuState_hpp
#define ConfigMenuState_hpp

#include "State.hpp"
#include "../Menus/ConfigMenu.hpp"

namespace Game { namespace States {

// Usings
using Menus::ConfigMenu;
using Parametros::ParametrosJogo;

class ConfigMenuState : public State, public ConfigMenu{
private:
    // Init methods
    void initValidKeys();
    
public:
    // Contructor & Destructor
    ConfigMenuState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys, ParametrosJogo* parametros_jogo);
    ~ConfigMenuState();
    
    // Methods
    void updateKeyInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target);
    
    // Menu Methods
    void onExit();
};
}};

#endif /* ConfigMenuState_hpp */
