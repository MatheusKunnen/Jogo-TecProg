//
//  Pedra.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/19/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Pedra.hpp"

namespace Game { namespace Entidades { namespace Obstaculos {

// Constructor & Destructor
Pedra::Pedra(const Vector2f& position, Texture* texture):
Obstaculo(Type::planta_venenosa, position, texture)
{
    this->setDelayTime(0.5);
    this->setDamage(1);
}

Pedra::~Pedra(){
    
}

// Methods Matheus
void Pedra::onCollision(Personagem *personagem){
    if (personagem && this->idle_time > this->delay_time) {
        personagem->removeVida(this->damage);
        this->idle_time = 0.f;
    }
}

}}}
