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
    initBackground();
    initJogadores();
}

FaseMontanha::~FaseMontanha(){
    
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

void FaseMontanha::initBackground(){
    this->background.setSize(Vector2f(this->g_grafico->getRenderWindow()->getSize()));
    this->background.setTexture(&this->textures.get(Resources::Textures::background_01));
}

void FaseMontanha::initMapa() {
    // Carrega Mapa
    this->mapa.LoadFromFile(this->parametros.getArquivoMapa());
    // Determina parte a ser renderizada
    this->mapa.SetDrawingBounds(sf::Rect<float>(0.f, 0.f, 9600, 1024));
}

// Methods
void FaseMontanha::update(const float &dt){
    this->l_entidades.update(dt);
}

void FaseMontanha::updateJogadores(const float &dt){
    
}

void FaseMontanha::updateMapa(const float &dt){
    this->mapa.SetDrawingBounds(sf::Rect<float>(this->g_grafico->getRenderWindow()->getView().getViewport()));
}
void FaseMontanha::render(RenderTarget *target) {
    target->draw(this->background);
    this->l_entidades.render(target);
    this->mapa.Draw(target);
}

}}
