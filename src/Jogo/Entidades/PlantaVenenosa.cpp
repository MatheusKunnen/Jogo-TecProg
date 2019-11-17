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
    this->setDamage(2);
}

PlantaVenenosa::~PlantaVenenosa(){
    
}

// Methods
void PlantaVenenosa::onCollision(Personagem *personagem){
    if (personagem)
        personagem->removeVida(this->damage);
}

}}}
