//
//  Personagem.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Personagem.hpp"

namespace Game { namespace Entidades { namespace Personagens{

Personagem::Personagem(const Vector2f& position, Texture* texture):
Entidade(texture){
    //initComponents();
}

Personagem::~Personagem(){
}

// Methods
void Personagem::jump(const float& gain){
    this->move_comp->jump(gain);
}

}}};
