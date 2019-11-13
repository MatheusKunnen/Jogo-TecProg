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
    initTextures();
    initMapa();
    initJogadores();
}

FaseMontanha::~FaseMontanha(){
    this->l_entidades.clear();
}
// Init Methods
void FaseMontanha::initTextures(){
    this->textures.load(Resources::Textures::background_01, this->textures.getFilename(Resources::Textures::background_01));
}

void FaseMontanha::initJogadores(){
    if (this->jogador_a != nullptr)
        this->l_entidades.add(this->jogador_a, false);
    if (this->jogador_b != nullptr)
        this->l_entidades.add(this->jogador_b, false);
}

void FaseMontanha::initMapa() {
    // Coloca textura de fundo
    this->mapa.setTexture(&this->textures.get(Resources::Textures::background_01));
    // Carrega Mapa
    this->mapa.load(this->parametros.getArquivoMapa(), this->parametros.getArquivoTileSet());
}

// Methods
void FaseMontanha::onKeyInput(Eventos::Tipo tipo){
    switch (tipo) {
        case Eventos::Tipo::M_LEFT_A:
            this->mapa.move(Vector2f(-2.f, 0.f),0);
            break;
        case Eventos::Tipo::M_RIGHT_A:
            this->mapa.move(Vector2f(2.f, 0.f),0);
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

void FaseMontanha::update(const float &dt){
    this->l_entidades.update(dt);
    this->mapa.update(dt);
}

void FaseMontanha::render(RenderTarget *target) {
    this->l_entidades.render(target);
    this->mapa.render(target);
    this->jogador_a->render(target);
}

void FaseMontanha::onInitFase(Jogador* jogador_a, Jogador* jogador_b){
    this->jogador_a = jogador_a;
    this->jogador_b = jogador_b; // Coloca jogadores na lista de entidades
    this->initJogadores();
    this->mapa.reset(); // Retorna o mapa a sua posicao inicial
}

void FaseMontanha::onCloseFase(){
    this->l_entidades.clear(); // Limpa entidades
    //this->l_entidades.add(&mapa);
    this->g_grafico->resetDefaultView(); // Retorna View original
}

}}
