//
//  Fase.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Fase_hpp
#define Fase_hpp

#include "../FrameTimer.hpp"

#include "../TADs/ListaEntidades.hpp"

#include "../Entidades/Mapa.hpp"
#include "../Entidades/Jogador.hpp"
#include "../Entidades/Projetil.hpp"
#include "../Entidades/Narcotraficante.hpp"
#include "../Entidades/Espinho.hpp"

#include "../Gerenciadores/GerenciadorGrafico.hpp"
#include "../Gerenciadores/GerenciadorColisoes.hpp"
#include "../Parametros/ParametrosFase.hpp"
#include "../Resources/TexturesHolder.hpp"

#include "SalvadoraFase.hpp"
#include "FaseEventHandler.hpp"

namespace Game { namespace Fases{

namespace eventos_jogador {
    enum Tipo {M_LEFT_A, M_RIGHT_A, JUMP_A, M_LEFT_B, M_RIGHT_B, JUMP_B};
}

// ID de cada fase
enum ID {fase_floresta = 1, fase_montanha = 2};

using Entidades::Mapas::Mapa;
using Entidades::Personagens::Jogador;
using Entidades::Personagens::Inimigo;
using Entidades::Personagens::Narcotraficante;
using Entidades::Obstaculos::Obstaculo;
using Entidades::Obstaculos::Projetil;
using Entidades::Obstaculos::Espinho;

using TADs::ListaEntidades;
using Resources::TextureHolder;
using Gerenciadores::GerenciadorColisoes;
using Gerenciadores::GerenciadorGrafico;
using Parametros::ParametrosFase;


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
    SalvadoraFase       salvadora;
    FaseEventHandler*   event_handler;
    
    // Init Functions
    void initParametros();
    virtual void initTextures();
    virtual void initJogadores();
    virtual void initInimigos() = 0;
    virtual void initObstaculos() = 0;
    virtual void onSavedFase() = 0;
    virtual void initMapa();
    
public:
    // Constructor & Destructor
    Fase(ID id, const string& f_parametros, Jogador* jogador_a, Jogador* jogador_b = nullptr);
    virtual ~Fase();
    
    // Methods
    virtual void update(const float& dt);
    void updateView(const float& dt);
    void checkPlayerStatus();
    void addEntidade(Gerenciadores::Personagem* entidade);
    void addEntidade(Gerenciadores::Obstaculo* obstaculo);
    void createProjetil(const Vector2f& position, const short& direction, const int& damage, const float& speed);
    void render(RenderTarget* target);
    void onKeyInput(eventos_jogador::Tipo tipo, const float& dt);
    virtual void onInitFase(Jogador* jogador_a, Jogador* jogador_b, FaseEventHandler* event_handler) = 0;
    void onCloseFase();
    
    // Getters & Setters
    void setEventHandler(FaseEventHandler* event_handler);
    FaseEventHandler* getEventHandler() const;
};
}};
#endif /* Fase_hpp */
