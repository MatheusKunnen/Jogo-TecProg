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
texture(texture),
sprite()
{
    this->setTexture(texture);
}

Entidade::~Entidade(){
    //delete this->sprite;
    //this->sprite = nullptr;
    //this->move_comp.reset();
}

// Getters & Setters
void Entidade::setGGrafico(GerenciadorGrafico *g_grafico) {
    this->g_grafico = g_grafico;
}

void Entidade::setPosition(const Vector2f& position){
    this->sprite.setPosition(position);
}

const Vector2f& Entidade::getPosition() const {
    return this->sprite.getPosition();
}

const FloatRect Entidade::getGlobalBounds() const {
    return this->sprite.getGlobalBounds();
}

void Entidade::move(const sf::Vector2f& direction, const float& dt){
    
}

// Components Methos
void Entidade::setTexture(Texture* texture){
    this->texture = texture;
    if (this->texture == nullptr)
        return;
    
    this->sprite.setTexture(*this->texture);
    this->sprite.setScale(0.3f, 0.3f);
}



// Methods
void Entidade::update(const float &dt){
    
}

void Entidade::render(RenderTarget* target){
    //target = this->g_grafico->getRenderWindow();
    target->draw(this->sprite);
}

}};
