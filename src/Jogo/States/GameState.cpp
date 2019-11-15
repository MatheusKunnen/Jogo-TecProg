//
//  GameState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "GameState.hpp"
#include "StateManager.hpp"

namespace Game { namespace States {

// Constructor & Destructor
GameState::GameState(StateManager* handler,GerenciadorGrafico* g_grafico, map<string, int>* supported_keys):
State(handler, g_grafico, supported_keys, states_id::game_menu),
GameMenu(*g_grafico->getRenderWindow())
{
    initValidKeys();
}

GameState::~GameState(){

}

// Init Methods
void GameState::initValidKeys(){
    try {
        // No valid Keys
    } catch (std::exception e) {
        cerr << "FATAL ERROR: GameState::initValidkeys: " << e.what() << endl;
    }
}

// Methods
void GameState::update(const float& dt){
    this->updateMenu(dt);
    
}
    
void GameState::render(RenderTarget* target){
    if (target == nullptr)
        target = this->g_grafico->getRenderWindow();
    this->renderMenu(target);
    
}

// Menu Methods
void GameState::onStartFaseFloresta(){
    this->manager->pushTopState(states_id::fase_floresta);
}

void GameState::onStartFaseMontanha(){
    this->manager->pushTopState(states_id::fase_montanha);
}

void GameState::onExit(){
    this->quit = true;
}

}};
