//
//  ConfigMenuState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "ConfigMenuState.hpp"
#include "StateManager.hpp"

namespace Game { namespace States {

// Constructor & Destructor
ConfigMenuState::ConfigMenuState(StateManager* handler,GerenciadorGrafico* g_grafico, map<string, int>* supported_keys):
State(handler, g_grafico, supported_keys, states_id::game_menu),
ConfigMenu(*g_grafico->getRenderWindow())
{
    initValidKeys();
}

ConfigMenuState::~ConfigMenuState(){

}

// Init Methods
void ConfigMenuState::initValidKeys(){
    try {
        // No valid Keys
    } catch (std::exception e) {
        cerr << "FATAL ERROR: ConfigMenuState::initValidkeys: " << e.what() << endl;
    }
}

// Methods
void ConfigMenuState::update(const float& dt){
    this->updateMenu(dt);
    
}
    
void ConfigMenuState::render(RenderTarget* target){
    if (target == nullptr)
        target = this->g_grafico->getRenderWindow();
    this->renderMenu(target);
    
}

// Menu Methods
void ConfigMenuState::onExit(){
    this->quit = true;
}

}};
