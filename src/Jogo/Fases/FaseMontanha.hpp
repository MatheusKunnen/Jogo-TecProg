//
//  FaseMontanha.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef FaseMontanha_hpp
#define FaseMontanha_hpp

#include "Fase.hpp"

#include "../Entidades/NarcotraficanteDesmatador.hpp"
#include "../Entidades/Pedra.hpp"

namespace Game { namespace Fases {

using Entidades::Personagens::NarcotraficanteDesmatador;
using Entidades::Obstaculos::Pedra;

class FaseMontanha : public Fase {
private:
    // Const
    const static string     CONFIG_FILE;
    
    // Init Methods
    void initInimigos();
    void initObstaculos();
    void initBoss();
    void onSavedFase();
    
public:
    // Constructor & Destructor
    FaseMontanha(Jogador* jogador_a, Jogador* jogador_b = nullptr);
    ~FaseMontanha();
    
    // Methods
    void onInitFase(Jogador* jogador_a, Jogador* jogador_b, FaseEventHandler* event_handler);
};

}};

#endif /* FaseMontanha_hpp */
