//
//  FaseMontanhaState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef FaseMontanhaState_hpp
#define FaseMontanhaState_hpp

#include "State.hpp"
#include "../Jogo.hpp"
#include "../Fases/FaseMontanha.hpp"

namespace Game { namespace States {

using Fases::FaseMontanha;

class FaseMontanhaState : public State {
private:
    // Attributes
    FaseMontanha        fase;
    
    // Init Methods
    void initValidKeys();
public:
    // Constructor & Destructor
    FaseMontanhaState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys);
    ~FaseMontanhaState();
    
    // Methods
    void update(const float& dt);
    void updateKeyInput(const float& dt);
    void render(RenderTarget* target);
};
}}
#endif /* FaseMontanhaState_hpp */
