//
//  PlantaVenenosa.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/17/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "PlantaVenenosa.hpp"

namespace Game { namespace Entidades { namespace Obstaculos {

// Constructor & Destructor
PlantaVenenosa::PlantaVenenosa(const Vector2f& position, Texture* texture):
Obstaculo(Type::planta_venenosa, position, texture)
{
    this->setDelayTime(1);
    this->setDamage(2);
}

PlantaVenenosa::~PlantaVenenosa(){
    
}

// Methods Matheus
void PlantaVenenosa::onCollision(Personagem *personagem){
    if (personagem && this->idle_time > this->delay_time) {
        personagem->removeVida(this->damage);
        this->idle_time = 0.f;
    }
}

}}}
