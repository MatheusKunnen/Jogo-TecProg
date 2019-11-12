//
//  FaseFlorestaState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef FaseFlorestaState_hpp
#define FaseFlorestaState_hpp

#include "State.hpp"
#include "../Jogo.hpp"
#include "../Fases/FaseFloresta.hpp"

namespace Game {  namespace States {

using Fases::FaseFloresta;

class FaseFlorestaState : public State {
private:
    FaseFloresta        fase;
    
    // Init Methods
    void initValidKeys();
public:
    FaseFlorestaState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys);
    ~FaseFlorestaState();
    
    // Methods
    void update(const float& dt);
    void updateKeyInput(const float& dt);
    void render(RenderTarget* target);
};
}}

#endif /* FaseFlorestaState_hpp */
