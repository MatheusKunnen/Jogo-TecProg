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

// Const
const float Narcotraficante::DAMAGE(2.f);
const float Narcotraficante::DELAY_TIME(1.5);
const float Narcotraficante::ATTACK_DISTANCE(320.f);
const float Narcotraficante::VEL_PROJETIL(6.f);

// Constructor & Destructor
Narcotraficante::Narcotraficante(const Vector2f& position, Texture* texture, Jogador* jogador_a, Jogador* jogador_b, Fase* fase, const int& damage):
Atirador(narcotraficante,position, texture, jogador_a, jogador_b, fase,  Narcotraficante::VEL_PROJETIL, Narcotraficante::DAMAGE)
{
    this->setAttackDelay(Narcotraficante::DELAY_TIME);
}

Narcotraficante::~Narcotraficante() {
    
}

// Methods
void Narcotraficante::autoMove(const float &dt) {
    this->time_mov+= dt;
    this->move(Vector2f(std::cos(this->getVelMov()*this->time_mov), 0), dt);
}

void Narcotraficante::atirar(const short &direction) {
    Vector2f pos = this->sprite.getPosition();
    pos.x = (direction > 0) ? pos.x + this->getGlobalBounds().width + 48.f: pos.x - 48.f;
    pos.y += this->getGlobalBounds().height - 64.f;
    this->fase->createProjetil(pos, direction, this->damage, this->vel_projetil);
}

}}}
