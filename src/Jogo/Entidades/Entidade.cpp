//
//  Entidade.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Entidade.hpp"
namespace Game{ namespace Entidades {

Entidade::Entidade():
speed(1.f)
{
    this->shape.setSize(sf::Vector2f(150.f,150.f));
}

Entidade::~Entidade(){

}

void Entidade::move(const sf::Vector2f& direction, const float& dt){
    this->shape.move(direction.x*this->speed*dt,direction.y*this->speed*dt);
}

void Entidade::update(const float& dt){
    
    
}

void Entidade::render(RenderTarget* target){
    target->draw(this->shape);
}

}};
