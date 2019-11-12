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
Entidade::Entidade(Texture* texture, GerenciadorGrafico* g_grafico):
g_grafico(g_grafico),
texture(nullptr),
sprite(nullptr),
move_comp(nullptr)
{
    this->sprite = new Sprite;
    this->setTexture(texture);
}

Entidade::~Entidade(){
    delete this->sprite;
    this->sprite = nullptr;
    this->move_comp.reset();
}

// Getters & Setters
void Entidade::setPosition(const Vector2f& position){
    if (this->sprite == nullptr)
        return;
    this->sprite->setPosition(position);
}

// Components Methos
void Entidade::setTexture(Texture* texture){
    this->texture = texture;
    if (this->texture == nullptr)
        return;
    
    this->sprite->setTexture(*this->texture);
    this->sprite->setScale(0.3f, 0.3f);
}

void Entidade::createMoveComponent(const float& max_vel, const float& acceleration, const float& deceleration){
    this->move_comp = unique_ptr<MoveComponent>(new MoveComponent(this->sprite, gravity, max_vel, acceleration, deceleration));
}

// Methods
void Entidade::move(const sf::Vector2f& direction, const float& dt){
    if (this->sprite == nullptr || this->move_comp == nullptr)
        return;
    this->move_comp->move(direction, dt);
    
}

void Entidade::update(const float& dt){
    if (this->move_comp != nullptr)
        this->move_comp->update(dt);
}

void Entidade::render(RenderTarget* target){
    if (this->sprite == nullptr)
        return;
    target->draw(*this->sprite);
}

}};
