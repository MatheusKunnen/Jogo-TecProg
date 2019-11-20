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
#include "../Entidades/Projetil.hpp"
#include "../Entidades/Desmatador.hpp"
#include "../Entidades/Narcotraficante.hpp"
#include "../Entidades/NarcotraficanteDesmatador.hpp"
#include "../Entidades/PlantaVenenosa.hpp"
#include "../Entidades/Espinho.hpp"
#include "../Entidades/level.hpp"
#include "../GerenciadorGrafico.hpp"
#include "../Gerenciadores/GerenciadorColisoes.hpp"
#include "../Parametros/ParametrosFase.hpp"
#include "../Resources/TexturesHolder.hpp"
#include "FaseEventHandler.hpp"

namespace Game { namespace Fases{

namespace eventos_jogador {
    enum Tipo {M_LEFT_A, M_RIGHT_A, JUMP_A, M_LEFT_B, M_RIGHT_B, JUMP_B};
}

using Entidades::Personagens::Jogador;
using Entidades::Obstaculos::Projetil;
using Entidades::Obstaculos::PlantaVenenosa;
using Entidades::Obstaculos::Espinho;
using Entidades::Personagens::Desmatador;
using Entidades::Personagens::Narcotraficante;
using Entidades::Personagens::NarcotraficanteDesmatador;

using TADs::ListaEntidades;
using Resources::TextureHolder;
using Gerenciadores::GerenciadorColisoes;
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
    GerenciadorColisoes g_colisoes;
    ParametrosFase      parametros;
    FaseEventHandler*   event_handler;
    
    // Init Functions
    void initParametros();
    virtual void initTextures();
    virtual void initJogadores();
    virtual void initInimigos() = 0;
    virtual void initObstaculos() = 0;
    virtual void initMapa();
    
public:
    // Constructor & Destructor
    Fase(const string& f_parametros, GerenciadorGrafico* g_grafico, Jogador* jogador_a, Jogador* jogador_b = nullptr);
    virtual ~Fase();
    
    // Methods
    virtual void update(const float& dt) = 0;
    virtual void updateView(const float& dt);
    virtual void checkPlayerStatus();
    virtual void addEntidade(Gerenciadores::Personagem* entidade);
    virtual void addEntidade(Gerenciadores::Obstaculo* obstaculo);
    virtual void createProjetil(const Vector2f& position, const short& direction, const int& damage, const float& speed);
    virtual void render(RenderTarget* target) = 0;
    virtual void onKeyInput(eventos_jogador::Tipo tipo, const float& dt);
    virtual void onInitFase(Jogador* jogador_a, Jogador* jogador_b, FaseEventHandler* event_handler) = 0;
    virtual void onCloseFase() = 0;
    
    // Getters & Setters
    void setEventHandler(FaseEventHandler* event_handler);
    FaseEventHandler* getEventHandler() const;
};
}};
#endif /* Fase_hpp */
