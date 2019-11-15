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
    initTextures();
    initMapa();
    //initJogadores();
}

FaseFloresta::~FaseFloresta(){
    this->l_entidades.clear();
}

// Init Methods
void FaseFloresta::initTextures(){
    this->textures.load(Resources::Textures::background_01, this->textures.getFilename(Resources::Textures::background_01));
}

void FaseFloresta::initMapa(){
    // Coloca textura de fundo
    this->mapa.setTexture(&this->textures.get(Resources::Textures::background_01));
    // Carrega Mapa
    this->mapa.load(this->parametros.getArquivoMapa(), this->parametros.getArquivoTileSet());
}
// Methods
void FaseFloresta::update(const float &dt){
    g_colisoes.gerenciarColisoes();
    l_entidades.update(dt); // Atualiza entidades

    this->updateView(dt);
}

void FaseFloresta::render(RenderTarget *target) {
//    if (target == nullptr)
//        target = this->g_grafico->getRenderWindow();
    this->l_entidades.render(target);

}

void FaseFloresta::onInitFase(Jogador* jogador_a, Jogador* jogador_b){
    this->l_entidades.add(&mapa);// Coloca jogadores na lista de entidades
    this->jogador_a = jogador_a;
    this->jogador_b = jogador_b;
    
    this->initJogadores();
    
    this->mapa.reset(); // Retorna o mapa a sua posicao inicial
}

void FaseFloresta::onCloseFase(){
    this->l_entidades.clear(); // Limpa entidades
    this->g_colisoes.clear(); // Limpa gerenciador de colisoes
    this->g_grafico->resetDefaultView(); // Retorna View original
}
}}
