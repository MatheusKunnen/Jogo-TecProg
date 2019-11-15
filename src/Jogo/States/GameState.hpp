//
//  GameState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

#include "State.hpp"
#include "../Menus/GameMenu.hpp"

namespace Game { namespace States {

// Usings
using Menus::GameMenu;

class GameState : public State, public GameMenu{
private:
    // Init methods
    void initValidKeys();
    
public:
    // Contructor & Destructor
    GameState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys);
    ~GameState();
    
    // Methods
    void updateKeyInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target);
    
    // Menu Methods
    void onStartFaseFloresta();
    void onStartFaseMontanha();
    void onExit();
};
}};

#endif /* GameState_hpp */
