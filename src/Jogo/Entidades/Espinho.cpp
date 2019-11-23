//
//  Espinho.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/19/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Espinho.hpp"

namespace Game { namespace Entidades { namespace Obstaculos {

// Constructor & Destructor
Espinho::Espinho(const Vector2f& position, Texture* texture):
Obstaculo(espinhos, position, texture)
{
    this->setDelayTime(0.5);
    this->setDamage(2.f);
}

Espinho::~Espinho(){
    
}

// Methods Matheus
void Espinho::onCollision(Personagem *personagem){
    if (personagem && this->idle_time > this->delay_time) {
        personagem->removeVida(this->damage);
        this->idle_time = 0.f;
    }
}

}}}
