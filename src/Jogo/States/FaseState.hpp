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
#include "Jogo.hpp"
#include "../Fases/Fase.hpp"

namespace Game {  namespace States {

using Fases::Fase;

class FaseState : public State {
private:
    Fase&        fase;
    
    // Init Methods
    void initValidKeys();
public:
    FaseState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys, Fase& fase);
    ~FaseState();
    
    // Methods
    void update(const float& dt);
    void updateKeyInput(const float& dt);
    void render(RenderTarget* target);
};
}}

#endif /* FaseFlorestaState_hpp */
