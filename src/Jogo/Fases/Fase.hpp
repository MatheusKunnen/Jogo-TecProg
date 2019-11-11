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
using TADs::ListaEntidades;
using Resources::TextureHolder;
using Entidades::Personagens::Jogador;
using Parametros::ParametrosFase;
class Fase {
protected:
    // Consts
    static const int BG_TEXTURE;
    // Attributes
    ListaEntidades      l_entidades;

    Jogador*            jogador_a;
    Jogador*            jogador_b;
    
    Level               mapa;
    RectangleShape      background;
    
    TextureHolder       textures;
    
    GerenciadorGrafico* g_grafico;
    ParametrosFase      parametros;
    
    // Init Functions
    void initParametros();
    virtual void initTextures() = 0;
    virtual void initJogadores() = 0;
    virtual void initBackground() = 0;
    virtual void initMapa() = 0;
public:
    // Constructor & Destructor
    Fase(const string& f_parametros, GerenciadorGrafico* g_grafico, Jogador* jogador_a, Jogador* jogador_b = nullptr);
    virtual ~Fase();
    
    // Methods
    virtual void update(const float& dt) = 0;
    virtual void updateJogadores(const float& dt) = 0;
    virtual void updateMapa(const float& dt) = 0;
    virtual void render(RenderTarget* target) = 0;
};
}};
#endif /* Fase_hpp */
