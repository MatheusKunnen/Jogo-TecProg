//
//  FailedMenuState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "FailedMenuState.hpp"
#include "StateManager.hpp"

namespace Game { namespace States {

// Constructor & Destructor
FailedMenuState::FailedMenuState(StateManager* handler,GerenciadorGrafico* g_grafico, map<string, int>* supported_keys):
State(handler, g_grafico, supported_keys, states_id::game_menu),
FailedMenu(*g_grafico->getRenderWindow())
{
    initValidKeys();
}

FailedMenuState::~FailedMenuState(){

}

// Init Methods
void FailedMenuState::initValidKeys(){
    try {
        // No valid Keys
    } catch (std::exception e) {
        cerr << "FATAL ERROR: FailedMenuState::initValidkeys: " << e.what() << endl;
    }
}

// Methods
void FailedMenuState::update(const float& dt){
    this->updateMenu(dt);
    
}
    
void FailedMenuState::render(RenderTarget* target){
    if (target == nullptr)
        target = this->g_grafico->getRenderWindow();
    this->renderMenu(target);
    
}

// Menu Methods
void FailedMenuState::onExit(){
    this->manager->addStatePop(2);
}

}};
