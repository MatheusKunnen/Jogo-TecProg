//
//  Fase.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Fase.hpp"

namespace Game { namespace Fases{

// Consts
const int Fase::BG_TEXTURE(1);

// Constructor & Destructor
Fase::Fase(const string& f_parametros, GerenciadorGrafico* g_grafico, Jogador* jogador_a, Jogador* jogador_b):
l_entidades(),
jogador_a(jogador_a),
jogador_b(jogador_b),
mapa(g_grafico),
textures(),
g_colisoes(mapa, l_entidades),
g_grafico(g_grafico),
parametros(f_parametros),
event_handler(nullptr)
{
    initParametros();
    initTextures();
    initMapa();
}

Fase::~Fase(){
    this->l_entidades.clear();
}

// Init methods
void Fase::initParametros(){
    // Carrega Parametros
    this->parametros.loadFromFile();
}

void Fase::initTextures(){
    this->textures.load(Resources::Textures::background_01, this->parametros.getArquivoBackground());
}

void Fase::initMapa(){
    // Coloca textura de fundo
    this->mapa.setTexture(&this->textures.get(Resources::Textures::background_01));
    // Carrega Mapa
    this->mapa.load(this->parametros.getArquivoMapa(), this->parametros.getArquivoTileSet());
}

void Fase::initJogadores(){
    if (this->jogador_a != nullptr){
        this->l_entidades.add(this->jogador_a, false);
        this->g_colisoes += this->jogador_a;
        this->jogador_a->setPosition(this->parametros.getPosPlayerA());
        
    }
    if (this->jogador_b != nullptr) {
        this->l_entidades.add(this->jogador_b, false);
        this->g_colisoes += this->jogador_b;
        this->jogador_b->setPosition(this->parametros.getPosPlayerB());
        this->g_grafico->resetDefaultView();
    }
}

// Methods
void Fase::updateView(const float &dt){
    if (this->jogador_a != nullptr){
        this->mapa.setPosition(this->jogador_a->getPosition().x, this->g_grafico->getView()->getCenter().y);
    }
}

void Fase::checkPlayerStatus(){
    // Verifica se algum jogador chegou ao final
    if ((this->jogador_a->getPosition().x >= this->parametros.getPosXWin()) ||
        (this->jogador_b && this->jogador_b->getPosition().x >= this->parametros.getPosXWin())){
        if (this->event_handler)
            this->event_handler->onFaseEvent(Event::win);
        this->g_grafico->resetDefaultView();
    }
    // Verifica se nenhum jogador caiu pela borda
    if ((this->jogador_a->getPosition().y >= this->g_grafico->getRenderWindow()->getSize().y) ||
        (this->jogador_b && this->jogador_b->getPosition().y >= this->g_grafico->getRenderWindow()->getSize().y)){
        if (this->event_handler)
            this->event_handler->onFaseEvent(Event::failed);
        this->g_grafico->resetDefaultView();
    }

}

void Fase::onKeyInput(eventos_jogador::Tipo tipo, const float& dt){
    switch (tipo) {
        case eventos_jogador::Tipo::M_LEFT_A:
            if (this->jogador_a)
                this->jogador_a->move(Vector2f(-1.f,0), dt);
            break;
        case eventos_jogador::Tipo::M_RIGHT_A:
            if (this->jogador_a)
                 this->jogador_a->move(Vector2f(1.f,0), dt);
            break;
        case eventos_jogador::Tipo::JUMP_A:
             if (this->jogador_a)
                 this->jogador_a->jump(10);
            break;
        case eventos_jogador::Tipo::M_LEFT_B:
             if (this->jogador_b)
                 this->jogador_b->move(Vector2f(-1.f,0), dt);
            break;
        case eventos_jogador::Tipo::M_RIGHT_B:
            if (this->jogador_b)
                this->jogador_b->move(Vector2f(1.f,0), dt);
            break;
        case eventos_jogador::Tipo::JUMP_B:
            if (this->jogador_b)
                this->jogador_b->jump(10);
            break;
        default:
            break;
    }
}

// Getters & Setters
void Fase::setEventHandler(FaseEventHandler *event_handler){
    this->event_handler = event_handler;
}

FaseEventHandler* Fase::getEventHandler() const {
    return this->event_handler;
}

}}
