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
namespace Game { namespace Fases {

class FaseFloresta : public Fase {
private:
    // Const
    const static string CONFIG_FILE;
    
    // Init Methods
    void initInimigos();
    void initObstaculos();
public:
    // Constructor & Destructor
    FaseFloresta(GerenciadorGrafico* g_grafico, Jogador* jogador_a, Jogador* jogador_b = nullptr);
    ~FaseFloresta();
    // Methods
    void update(const float& dt);
    void render(RenderTarget* target);
    void onInitFase(Jogador* jogador_a, Jogador* jogador_b, FaseEventHandler* event_handler);
    void onCloseFase();
    
};

}};
#endif /* FaseFloresta_hpp */
