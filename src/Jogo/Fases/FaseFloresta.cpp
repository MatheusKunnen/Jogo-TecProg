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
    initBackground();
    initJogadores();
}

FaseFloresta::~FaseFloresta(){
    this->l_entidades.clear();
}

// Init Methods
void FaseFloresta::initMapa(){
    // Coloca textura de fundo
    this->mapa.setTexture(&this->textures.get(Resources::Textures::background_01));
    // Carrega Mapa
    this->mapa.load(this->parametros.getArquivoMapa(), this->parametros.getArquivoTileSet());
}

void FaseFloresta::initTextures(){
    this->textures.load(Resources::Textures::background_01, this->textures.getFilename(Resources::Textures::background_01));
}

void FaseFloresta::initJogadores(){
    if (this->jogador_a != nullptr)
        this->l_entidades.add(this->jogador_a, false);
    if (this->jogador_b != nullptr)
        this->l_entidades.add(this->jogador_b, false);
}

void FaseFloresta::initBackground(){
    this->background.setSize(Vector2f(this->g_grafico->getRenderWindow()->getSize()));
    this->background.setTexture(&this->textures.get(Resources::Textures::background_01));
}

// Methods
void FaseFloresta::onKeyInput(Eventos::Tipo tipo){
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

void FaseFloresta::update(const float &dt){
    l_entidades.update(dt);
    //this->mapa.move(Vector2f(2.f, 0.f),0);
    this->mapa.update(dt);
    this->updateMapa(dt);
}

void FaseFloresta::updateJogadores(const float &dt){
    
}

void FaseFloresta::updateMapa(const float &dt){
    
}

void FaseFloresta::render(RenderTarget *target) {
    //target->draw(this->background);
    this->mapa.render(target);
    this->l_entidades.render(target);

}

}}
