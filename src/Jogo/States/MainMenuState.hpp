//
//  MainMenuState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef MainMenuState_hpp
#define MainMenuState_hpp

#include "State.hpp"
#include "../Menus/MainMenu.hpp"

namespace Game { namespace States {

// Usings
using Menus::MainMenu;

class MainMenuState : public State, public MainMenu{
private:
    // Init methods
    void initValidKeys();
    
public:
    // Contructor & Destructor
    MainMenuState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys);
    ~MainMenuState();
    // Methods
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target);
    // Menu Methods
    void onOpenNewGame();
    void onOpenRanking();
    void onOpenConfig();
    void onExit();
};
}};

#endif /* MainMenuState_hpp */
