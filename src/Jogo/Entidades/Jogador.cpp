//
//  Jogador.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Jogador.hpp"
namespace Game { namespace Entidades { namespace Personagens {

Jogador::Jogador(const Vector2f& position, Texture* texture):
Personagem(position, texture)
{
    initComponents();
    this->setPosition(position);
}

Jogador::~Jogador(){
    
}

// Init Methods
void Jogador::initComponents(){
    this->initMoveComponent();
}

void Jogador::initMoveComponent(){
    
}

//Methods
void Jogador::update(const float &dt){
    this->total_dt += dt;
    this->move_comp.update(dt);
}

void Jogador::reset(){
    this->setNumVidas(5);
    this->total_dt = 0;
}

// Getters & Setters
const int Jogador::getScore() const {
    return (pow(this->getNumVidas(), 2) / pow(this->total_dt, 2)) * 10000;
}
}}};
