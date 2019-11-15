//
//  WinMenuState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "WinMenuState.hpp"
#include "StateManager.hpp"

namespace Game { namespace States {

// Constructor & Destructor
WinMenuState::WinMenuState(StateManager* handler,GerenciadorGrafico* g_grafico, map<string, int>* supported_keys):
State(handler, g_grafico, supported_keys, states_id::game_menu),
WinMenu(*g_grafico->getRenderWindow())
{
    initValidKeys();
}

WinMenuState::~WinMenuState(){

}

// Init Methods
void WinMenuState::initValidKeys(){
    try {
        // No valid Keys
    } catch (std::exception e) {
        cerr << "FATAL ERROR: WinMenuState::initValidkeys: " << e.what() << endl;
    }
}

// Methods
void WinMenuState::update(const float& dt){
    this->updateMenu(dt);
    
}
    
void WinMenuState::render(RenderTarget* target){
    if (target == nullptr)
        target = this->g_grafico->getRenderWindow();
    this->renderMenu(target);
    
}

// Menu Methods
void WinMenuState::onExit(){
    this->manager->addStatePop(2);
}

}};
