//
//  MainMenuState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "MainMenuState.hpp"
#include "StateManager.hpp"
namespace Game { namespace States {

// Constructor & Destructor
MainMenuState::MainMenuState(StateManager* handler,GerenciadorGrafico* g_grafico, map<string, int>* supported_keys):
State(handler, g_grafico, supported_keys, states_id::game),
MainMenu(*g_grafico->getRenderWindow())
{
    initValidKeys();
}

MainMenuState::~MainMenuState(){

}

// Init Methods
void MainMenuState::initValidKeys(){
    try{
        // No valid Keys
    } catch (std::exception e) {
        cerr << "FATAL ERROR: MainMenuState::initValidkeys: " << e.what() << endl;
    }
}

// Methods
void MainMenuState::update(const float& dt){
    this->updateMenu(dt);
    
}
    
void MainMenuState::render(RenderTarget* target){
    if (target == nullptr)
        target = this->g_grafico->getRenderWindow();
    this->renderMenu(target);
    
}

// Menu Methods
void MainMenuState::onOpenNewGame(){
    this->manager->pushState(states_id::game);
}

void MainMenuState::onOpenRanking(){
    this->manager->pushState(states_id::ranking);
}

void MainMenuState::onOpenConfig(){
    this->manager->pushState(states_id::config);
}

void MainMenuState::onExit(){
    this->quit = true;
}

}};
