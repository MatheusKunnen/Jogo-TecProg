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
    // Carrega Mapa
    this->mapa.LoadFromFile(this->parametros.getArquivoMapa());
    // Determina parte a ser renderizada
    this->mapa.SetDrawingBounds(sf::Rect<float>(0.f, 0.f, 9600, 1024));
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
void FaseFloresta::update(const float &dt){
    l_entidades.update(dt);
    this->updateMapa(dt);
}

void FaseFloresta::updateJogadores(const float &dt){
    
}

void FaseFloresta::updateMapa(const float &dt){
    View vieww = *this->g_grafico->getView();
    vieww.move(1, 0);
    this->g_grafico->getRenderWindow()->setView(vieww);
    sf::FloatRect rect = this->g_grafico->getRenderWindow()->getView().getViewport();
    auto size = this->g_grafico->getRenderWindow()->getSize();
    auto view = this->g_grafico->getView()->getCenter();
    rect.left = view.x - size.x/2;
    rect.top = view.y - size.y/2;
    rect.width = 1920;
    rect.height = 1024;
    this->mapa.SetDrawingBounds(rect);
}

void FaseFloresta::render(RenderTarget *target) {
    target->draw(this->background);
    this->mapa.Draw(target);
    this->l_entidades.render(target);

}

}}
