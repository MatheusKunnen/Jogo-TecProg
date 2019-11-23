//
//  Projetil.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/18/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Projetil.hpp"

namespace Game { namespace Entidades { namespace Obstaculos{

Projetil::Projetil(const Vector2f& position, Texture* texture, const int damage, const short& direction, const float& speed):
Obstaculo(projetil, position, texture, damage),
direction(direction),
speed(speed),
life_time(0.5)
{
    this->initSprite();
}

Projetil::~Projetil() {
    
}

// Init Methods
void Projetil::initSprite(){
    this->sprite.setScale((this->direction > 0) ? -1 : 1, 1);
}

// Methods
void Projetil::update(const float &dt) {
    this->updateLifeTime(dt);
    this->move(dt);
}

void Projetil::updateLifeTime(const float &dt) {
    this->life_time += dt;
    if (life_time > 3)
        this->setEnding(true);
}

void Projetil::move(const float &dt) {
    Vector2f pos = this->sprite.getPosition();
    pos.x += this->direction*this->speed;
    this->sprite.setPosition(pos);
}

void Projetil::onCollision(Personagem *personagem) {
    // Sempre danifica o personagem (inversamente proporcional ao tempo de vida)
    personagem->removeVida(this->getDamage()/(this->life_time));
    // Depois de colidir não precissa ser utilizado
    this->setEnding(true);
}

}}}
