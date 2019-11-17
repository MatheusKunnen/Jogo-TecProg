//
//  RankingMenuState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef RankingMenuState_hpp
#define RankingMenuState_hpp

#include "State.hpp"
#include "../Menus/RankingMenu.hpp"

namespace Game { namespace States {

// Usings
using Menus::RankingMenu;
using TADs::ListaRanking;

class RankingMenuState : public State, public RankingMenu {
private:
    // Init methods
    void initValidKeys();
    
public:
    // Contructor & Destructor
    RankingMenuState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys, ListaRanking& l_ranking);
    ~RankingMenuState();
    
    // Methods
    void updateKeyInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target);
    
    // Menu Methods
    void onExit();
};
}};

#endif /* RankingMenuState_hpp */
