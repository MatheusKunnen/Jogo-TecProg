//
//  FaseMontanha.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "FaseMontanha.hpp"
namespace Game { namespace Fases {

// Const
const string FaseMontanha::CONFIG_FILE("Resources/config/fase_b_config.json");


// Constructor && Destructor
FaseMontanha::FaseMontanha(GerenciadorGrafico* g_grafico, Jogador* jogador_a, Jogador* jogador_b):
Fase(FaseMontanha::CONFIG_FILE, g_grafico, jogador_a, jogador_b)
{
    
}

FaseMontanha::~FaseMontanha(){
    this->l_entidades.clear();
}

// Init Methods
void FaseMontanha::initInimigos() {
    
}

void FaseMontanha::initObstaculos() {
    
}

// Methods
void FaseMontanha::update(const float &dt){
    this->l_entidades.update(dt);
    this->mapa.update(dt);
    this->updateView(dt);
    // Verifica se um jogador Ganhou/Perdeu
    this->checkPlayerStatus();
}

void FaseMontanha::render(RenderTarget *target) {
    this->l_entidades.render(target);
    this->mapa.render(target);
    this->jogador_a->render(target);
}

void FaseMontanha::onInitFase(Jogador* jogador_a, Jogador* jogador_b, FaseEventHandler* event_handler){
    this->jogador_a = jogador_a;
    this->jogador_b = jogador_b; // Coloca jogadores na lista de entidades
    this->initJogadores();
    this->mapa.reset(); // Retorna o mapa a sua posicao inicial
    // Atualiza EventHandler
    this->setEventHandler(event_handler);
}

void FaseMontanha::onCloseFase(){
    this->l_entidades.clear(); // Limpa entidades
    //this->l_entidades.add(&mapa);
    this->g_grafico->resetDefaultView(); // Retorna View original
}

}}
