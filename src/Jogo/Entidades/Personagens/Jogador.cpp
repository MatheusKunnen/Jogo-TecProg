//
//  Jogador.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Jogador.hpp"
namespace Game { namespace Entidades {

Jogador::Jogador(const Vector2f& position, Texture* texture):
Entidade(texture)
{
    this->initComponents();
    this->setPosition(position);
}

Jogador::~Jogador(){
    
}

// Init Methods
void Jogador::initComponents(){
    
}

//Methods

}};
