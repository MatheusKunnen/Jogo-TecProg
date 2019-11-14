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
parametros(f_parametros)
{
    initParametros();
}

Fase::~Fase(){
    this->l_entidades.clear();
}

// Init methods
void Fase::initParametros(){
    // Carrega Parametros
    this->parametros.loadFromFile();
}

// Methods
void Fase::updateView(const float &dt){
    if (this->jogador_a != nullptr){
        this->mapa.setPosition(this->jogador_a->getPosition().x, this->g_grafico->getView()->getCenter().y);
    }
}

void Fase::onKeyInput(Eventos::Tipo tipo, const float& dt){
    switch (tipo) {
        case Eventos::Tipo::M_LEFT_A:
            if (this->jogador_a)
                this->jogador_a->move(Vector2f(-1.f,0), dt);
            break;
        case Eventos::Tipo::M_RIGHT_A:
            if (this->jogador_a)
                 this->jogador_a->move(Vector2f(1.f,0), dt);
            break;
        case Eventos::Tipo::JUMP_A:
             if (this->jogador_a)
                 this->jogador_a->jump(10);
            break;
        case Eventos::Tipo::M_LEFT_B:
             if (this->jogador_b)
                 this->jogador_b->move(Vector2f(-1.f,0), dt);
            break;
        case Eventos::Tipo::M_RIGHT_B:
            if (this->jogador_b)
                this->jogador_b->move(Vector2f(1.f,0), dt);
            break;
        case Eventos::Tipo::JUMP_B:
            if (this->jogador_b)
                this->jogador_b->jump(10);
            break;
        default:
            break;
    }
}

}}
