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
#include "../Fases/Fase.hpp"

namespace Game {  namespace States {

using Entidades::Personagens::Jogador;
using Fases::Fase;
using Fases::FaseEventHandler;

class FaseState : public State, public FaseEventHandler {
private:
    // Attributes
    Fase&        fase;
    
public:
    FaseState(StateManager* handler, Fase& fase, Jogador* jogador_a, Jogador* jogador_b);
    ~FaseState();
    
    // Methods
    void update(const float& dt);
    void updateKeyInput(const float& dt);
    void render(RenderTarget* target);
    void onWin();
    void onFailed();
    // Methods (FaseEventHandler)
    void onFaseEvent(Fases::Event event_id);
};
}}

#endif /* FaseFlorestaState_hpp */
