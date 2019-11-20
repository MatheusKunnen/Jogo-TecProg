//
//  Obstaculo.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/6/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Obstaculo.hpp"

namespace Game { namespace Entidades { namespace Obstaculos {

Obstaculo::Obstaculo(const Type type_id, const Vector2f& position, Texture* texture, const int damage):
Entidade(texture),
type_id(type_id),
damage(damage),
idle_time(0),
delay_time(0)
{
    this->setPosition(position);
}

Obstaculo::~Obstaculo(){
        
}

// Methods
void Obstaculo::update(const float &dt) {
    this->idle_time += dt;
}


// Getters & Setters
void Obstaculo::setDamage(const float& damage){
    this->damage = damage;
}

const float& Obstaculo::getDamage() const {
    return this->damage;
}

void Obstaculo::setDelayTime(const float &delay_time) {
    this->delay_time = delay_time;
}

const float& Obstaculo::getDelayTime() const {
    return this->delay_time;
}

}}}
