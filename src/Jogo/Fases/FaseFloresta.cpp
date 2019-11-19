//
//  FaseFloresta.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "FaseFloresta.hpp"

namespace Game { namespace Fases {

// Const
const string FaseFloresta::CONFIG_FILE("Resources/config/fase_a_config.json");


// Constructor && Destructor
FaseFloresta::FaseFloresta(GerenciadorGrafico* g_grafico, Jogador* jogador_a, Jogador* jogador_b):
Fase(FaseFloresta::CONFIG_FILE, g_grafico, jogador_a, jogador_b)
{

}

FaseFloresta::~FaseFloresta(){
    this->l_entidades.clear();
}

// Init Methods
void FaseFloresta::initInimigos() {
    
    Narcotraficante* desmatador = new Narcotraficante(Vector2f(1400.f, 600.f), &this->textures.get(Resources::Textures::desmatador), this->jogador_a, this->jogador_b, this, 5);
    
    this->l_entidades += desmatador;
    this->g_colisoes += desmatador;
}

void FaseFloresta::initObstaculos() {
    PlantaVenenosa* obstaculo = new PlantaVenenosa(Vector2f(700.f,500.f), &this->textures.get(Resources::Textures::planta_venenosa));
    
    this->l_entidades+= obstaculo;
    this->g_colisoes += obstaculo;
}

// Methods
void FaseFloresta::update(const float &dt){
    // Verifica colisoes
    g_colisoes.gerenciarColisoes();
    // Atualiza entidades
    l_entidades.update(dt);
    // Atualiza view do RenderWindow
    this->updateView(dt);
    // Verifica se um jogador Ganhou/Perdeu
    this->checkPlayerStatus();
}

void FaseFloresta::render(RenderTarget *target) {
    // Renderiza todas as entidades
    this->l_entidades.render(target);
}

void FaseFloresta::onInitFase(Jogador* jogador_a, Jogador* jogador_b, FaseEventHandler* event_handler){
    // Agrega mapa
    this->l_entidades.add(&mapa);
    // Atualiza ponteiros de jogadores
    this->jogador_a = jogador_a;
    this->jogador_b = jogador_b;
    // Inicia jogadores
    this->initJogadores();
    // Inicia Obstaculos
    initObstaculos();
    // Inicia Inimigos
    initInimigos();
    // Retorna o mapa a sua posicao inicial
    this->mapa.reset();
    // Atualiza EventHandler
    this->setEventHandler(event_handler);
}

void FaseFloresta::onCloseFase(){
    // Limpa entidades
    this->l_entidades.clear();
    // Limpa gerenciador de colisoes
    this->g_colisoes.clear();
    // Retorna à View original
    this->g_grafico->resetDefaultView();
}
}}
