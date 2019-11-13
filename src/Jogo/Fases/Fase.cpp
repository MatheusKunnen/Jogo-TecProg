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
        this->mapa.setPosition(this->jogador_a->getPosition());
    }
}

}}
