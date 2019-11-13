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
    initJogadores();
}

FaseFloresta::~FaseFloresta(){
    this->l_entidades.clear();
}

// Init Methods
void FaseFloresta::initTextures(){
    this->textures.load(Resources::Textures::background_01, this->textures.getFilename(Resources::Textures::background_01));
}

void FaseFloresta::initJogadores(){
    if (this->jogador_a != nullptr)
        this->l_entidades.add(this->jogador_a, false);
    if (this->jogador_b != nullptr)
        this->l_entidades.add(this->jogador_b, false);
}

void FaseFloresta::initMapa(){
    // Coloca textura de fundo
    this->mapa.setTexture(&this->textures.get(Resources::Textures::background_01));
    // Carrega Mapa
    this->mapa.load(this->parametros.getArquivoMapa(), this->parametros.getArquivoTileSet());
}
// Methods
void FaseFloresta::onKeyInput(Eventos::Tipo tipo){
    switch (tipo) {
        case Eventos::Tipo::M_LEFT_A:
            this->jogador_a->move(Vector2f(-1.f,0), 0);
            break;
        case Eventos::Tipo::M_RIGHT_A:
            this->jogador_a->move(Vector2f(1.f,0), 0);
            break;
        case Eventos::Tipo::JUMP_A:
                
            break;
        case Eventos::Tipo::M_LEFT_B:
            this->mapa.move(Vector2f(-6.f, 0.f),0);
            break;
        case Eventos::Tipo::M_RIGHT_B:
            this->mapa.move(Vector2f(6.f, 0.f),0);
            break;
        case Eventos::Tipo::JUMP_B:
            
            break;
        default:
            break;
    }
}

void FaseFloresta::update(const float &dt){
    l_entidades.update(dt); // Atualiza entidades
    this->updateView(dt);
}

void FaseFloresta::render(RenderTarget *target) {
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
    //this->l_entidades.add(&mapa);
    this->g_grafico->resetDefaultView(); // Retorna View original
}
}}
