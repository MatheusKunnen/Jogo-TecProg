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
    
    //this->createMoveComponent(100.f,250, 200);
}

//Methods

}}};
