//
//  FaseFloresta.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef FaseFloresta_hpp
#define FaseFloresta_hpp

#include "Fase.hpp"
#include "../Entidades/Desmatador.hpp"
#include "../Entidades/PlantaVenenosa.hpp"

namespace Game { namespace Fases {

using Entidades::Obstaculos::PlantaVenenosa;
using Entidades::Personagens::Desmatador;

class FaseFloresta : public Fase {
private:
    // Const
    const static string CONFIG_FILE;
    float delay;
    
    // Init Methods
    void initInimigos();
    void initObstaculos();
    void onSavedFase();
    
public:
    // Constructor & Destructor
    FaseFloresta(Jogador* jogador_a, Jogador* jogador_b = nullptr);
    ~FaseFloresta();
    
    // Methods
    void onInitFase(Jogador* jogador_a, Jogador* jogador_b, FaseEventHandler* event_handler);
    
};

}};
#endif /* FaseFloresta_hpp */
