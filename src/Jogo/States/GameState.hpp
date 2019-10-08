//
//  GameState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp
#include "base_includes.hpp"
#include "State.hpp"

namespace Game { namespace States {

class GameState : public State {
private:
    Entidades::Entidade jogador; // DEBUG
    void initValidKeys();
public:
    // Contructor & Destructor
    GameState(RenderWindow* render_window, map<string, int>* supported_keys, stack<State*>* states_stack);
    ~GameState();
    // Methods
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target);
};

}};

#endif /* GameState_hpp */
