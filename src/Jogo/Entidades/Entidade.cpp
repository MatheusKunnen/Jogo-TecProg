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
Entidade::Entidade(Texture* texture):
texture(nullptr),
sprite(nullptr),
speed(1.f)
{
    this->sprite = new Sprite;
    this->create_sprite(texture);
}

Entidade::~Entidade(){
    delete this->sprite;
    this->sprite = nullptr;
}

// Getters & Setters
void Entidade::setPosition(const Vector2f& position){
    if (this->sprite == nullptr)
        return;
    this->sprite->setPosition(position);
}

// Components Methos
void Entidade::create_sprite(Texture* texture){
    this->texture = texture;
    if (this->sprite == nullptr)
        return;
    
    this->sprite->setTexture(*this->texture);
}

// Methods
void Entidade::move(const sf::Vector2f& direction, const float& dt){
    if (this->sprite == nullptr)
        return;
    this->sprite->move(direction.x*this->speed*dt,direction.y*this->speed*dt);
}

void Entidade::update(const float& dt){
    
    
}

void Entidade::render(RenderTarget* target){
    if (this->sprite == nullptr)
        return;
    target->draw(*this->sprite);
}

}};
