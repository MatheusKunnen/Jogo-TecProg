//
//  Desmatador.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/18/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Desmatador.hpp"

namespace Game { namespace Entidades { namespace Personagens {
Desmatador::Desmatador(const Vector2f& position, Texture* texture, Jogador* jogador_a, Jogador* jogador_b):
Inimigo(position, texture, jogador_a, jogador_b, 5)
{
    
}

Desmatador::~Desmatador(){
    
}

// Methods
void Desmatador::attack(Jogador* jogador){
    jogador->removeVida(this->getDamage());
}

void Desmatador::autoMove(const float& dt) {
    this->time_mov += dt;
    this->move(Vector2f(this->getAmplitudeMov() * std::cos(this->getVelMov()*this->time_mov), 0), dt);
}

}}}
