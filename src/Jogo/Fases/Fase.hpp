//
//  Fase.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Fase_hpp
#define Fase_hpp

#include "../TADs/ListaEntidades.hpp"
#include "../Entidades/Jogador.hpp"
#include "../Entidades/level.hpp"
#include "../GerenciadorGrafico.hpp"
#include "../Parametros/ParametrosFase.hpp"
#include "../Resources/TexturesHolder.hpp"

namespace Game { namespace Fases{

namespace Eventos {
    enum Tipo {M_LEFT_A, M_RIGHT_A, JUMP_A, M_LEFT_B, M_RIGHT_B, JUMP_B};
}

using Entidades::Personagens::Jogador;

using TADs::ListaEntidades;
using Resources::TextureHolder;
using Parametros::ParametrosFase;
using Entidades::Mapas::Mapa;
class Fase {
protected:
    // Consts
    static const int BG_TEXTURE;
    // Attributes
    ListaEntidades      l_entidades;

    Jogador*            jogador_a;
    Jogador*            jogador_b;
    
    Mapa                mapa;
    
    TextureHolder       textures;
    
    GerenciadorGrafico* g_grafico;
    ParametrosFase      parametros;
    
    // Init Functions
    void initParametros();
    virtual void initTextures() = 0;
    virtual void initJogadores() = 0;
    virtual void initMapa() = 0;
public:
    // Constructor & Destructor
    Fase(const string& f_parametros, GerenciadorGrafico* g_grafico, Jogador* jogador_a, Jogador* jogador_b = nullptr);
    virtual ~Fase();
    
    // Methods
    virtual void update(const float& dt) = 0;
    virtual void updateView(const float& dt);
    virtual void render(RenderTarget* target) = 0;
    virtual void onKeyInput(Eventos::Tipo tipo) = 0;
    virtual void onInitFase(Jogador* jogador_a, Jogador* jogador_b) = 0;
    virtual void onCloseFase() = 0;
};
}};
#endif /* Fase_hpp */
