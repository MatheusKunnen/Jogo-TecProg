//
//  Entidade.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Entidade.hpp"
namespace Game{ namespace Entidades {

// Constructor & Destructor
Entidade::Entidade(ID id, Texture* texture):
id(id),
texture(texture),
sprite(),
ending(false)
{
    this->setTexture(texture);
}

Entidade::~Entidade(){

}

// Getters & Setters
void Entidade::setPosition(const Vector2f& position){
    this->sprite.setPosition(position);
}

const Vector2f& Entidade::getPosition() const {
    return this->sprite.getPosition();
}

const FloatRect Entidade::getGlobalBounds() const {
    return this->sprite.getGlobalBounds();
}

void Entidade::setEnding(const bool &ending) {
    this->ending = ending;
}

const bool& Entidade::isEnding() const {
    return this->ending;
}

// Components Methos
void Entidade::setTexture(Texture* texture){
    this->texture = texture;
    if (this->texture == nullptr)
        return;
    
    this->sprite.setTexture(*this->texture);
}

const ID& Entidade::getId() const {
    return this->id;
}

// Methods
void Entidade::render(RenderTarget* target){
    target->draw(this->sprite);
}

// Static Methods
const Vector2f Entidade::distanceV(Entidade* entidade_a, Entidade* entidade_b){
    const FloatRect a = entidade_a->getGlobalBounds(),
                    b = entidade_b->getGlobalBounds();
    return Vector2f(pow((a.left + a.width/2) - (b.left + b.width/2), 2),
                        pow((a.top + a.height/2) - (b.top + b.height/2), 2));
}

const Vector2f Entidade::maxDistanceV(Entidade* entidade_a, Entidade* entidade_b){
    const FloatRect a = entidade_a->getGlobalBounds(),
                    b = entidade_b->getGlobalBounds();
    return Vector2f(pow(b.width/2 + a.width/2, 2), pow(b.height/2 + a.height/2, 2));
}

const float Entidade::distance(Entidade* entidade_a, Entidade* entidade_b){
    const Vector2f distance = Entidade::distanceV(entidade_a, entidade_b);
    return std::sqrt(distance.x + distance.y);
}

const float Entidade::maxDistance(Entidade* entidade_a, Entidade* entidade_b){
    const Vector2f max_distance = Entidade::maxDistanceV(entidade_a, entidade_b);
    return std::sqrt(max_distance.x + max_distance.y);
}

}};
