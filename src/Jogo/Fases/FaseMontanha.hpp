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
namespace Game { namespace Fases {
class FaseMontanha : public Fase {
private:
    // Const
    const static string     CONFIG_FILE;
    
    // Init Methods
    void initTextures();
    void initJogadores();
    void initMapa();
public:
    // Constructor & Destructor
    FaseMontanha(GerenciadorGrafico* g_grafico, Jogador* jogador_a, Jogador* jogador_b = nullptr);
    ~FaseMontanha();
    // Methods
    void onKeyInput(Eventos::Tipo tipo);
    void update(const float& dt);
    void render(RenderTarget* target);
    void onInitFase(Jogador* jogador_a, Jogador* jogador_b);
    void onCloseFase();
};

}};

#endif /* FaseMontanha_hpp */
