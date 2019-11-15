//
//  PauseMenuState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "PauseMenuState.hpp"
#include "StateManager.hpp"

namespace Game { namespace States {

// Constructor & Destructor
PauseMenuState::PauseMenuState(StateManager* handler,GerenciadorGrafico* g_grafico, map<string, int>* supported_keys):
State(handler, g_grafico, supported_keys, states_id::game_menu),
PauseMenu(*g_grafico->getRenderWindow())
{
    initValidKeys();
}

PauseMenuState::~PauseMenuState(){

}

// Init Methods
void PauseMenuState::initValidKeys(){
    try {
        // No valid Keys
    } catch (std::exception e) {
        cerr << "FATAL ERROR: PauseMenuState::initValidkeys: " << e.what() << endl;
    }
}

// Methods
void PauseMenuState::update(const float& dt){
    this->updateMenu(dt);
    
}
    
void PauseMenuState::render(RenderTarget* target){
    if (target == nullptr)
        target = this->g_grafico->getRenderWindow();
    this->renderMenu(target);
    
}

// Menu Methods
void PauseMenuState::onResumeGame(){
    this->quit = true;
}

void PauseMenuState::onExit(){
    this->manager->addStatePop(2);
}

}};
