//
//  RankingMenuState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "RankingMenuState.hpp"

namespace Game { namespace States {

// Constructor & Destructor
RankingMenuState::RankingMenuState(StateManager* handler,GerenciadorGrafico* g_grafico, map<string, int>* supported_keys, ListaRanking& l_ranking):
State(handler, g_grafico, supported_keys, states_id::game_menu),
RankingMenu(*g_grafico->getRenderWindow(), l_ranking)
{
    initValidKeys();
}

RankingMenuState::~RankingMenuState(){

}

// Init Methods
void RankingMenuState::initValidKeys(){
    try {
        // No valid Keys
    } catch (std::exception e) {
        cerr << "FATAL ERROR: RankingMenuState::initValidkeys: " << e.what() << endl;
    }
}

// Methods
void RankingMenuState::update(const float& dt){
    this->updateMenu(dt);
    
}
    
void RankingMenuState::render(RenderTarget* target){
    if (target == nullptr)
        target = this->g_grafico->getRenderWindow();
    this->renderMenu(target);
    
}

// Menu Methods
void RankingMenuState::onExit(){
    this->quit = true;
}

}};
