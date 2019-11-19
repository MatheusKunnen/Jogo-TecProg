//
//  Narcotraficante.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/18/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Narcotraficante.hpp"
#include "../Fases/Fase.hpp"

namespace Game { namespace Entidades { namespace Personagens{

// Constructor & Destructor
Narcotraficante::Narcotraficante(const Vector2f& position, Texture* texture, Jogador* jogador_a, Jogador* jogador_b, Fase* fase, const int& damage):
Atirador(position, texture, jogador_a, jogador_b, fase, damage)
{
    
}

Narcotraficante::~Narcotraficante() {
    
}

// Methods
void Narcotraficante::autoMove(const float &dt) {
    this->move(Vector2f(std::cos(this->getVelMov()*this->time_mov), 0), dt);
}

void Narcotraficante::atirar(const short &direction) {
    Vector2f pos = this->sprite.getPosition();
    pos.x = (direction > 0) ? pos.x + 16 : pos.x - 130;
    pos.y -=32;
    this->fase->createProjetil(pos, direction, this->damage, this->projetil_speed);
}

}}}
