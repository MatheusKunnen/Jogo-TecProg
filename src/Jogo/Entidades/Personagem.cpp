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
Entidade(texture),
num_vidas(1),
move_comp(&sprite){
    //initComponents();
}

Personagem::~Personagem(){
    this->move_comp.reset();
}

// Init Methods
void Personagem::initMoveComponent(){

}

// Methods
void Personagem::update(const float &dt){
    this->move_comp.update(dt);
}

void Personagem::move(const sf::Vector2f& direction, const float& dt){
    this->move_comp.move(direction, dt);
}

void Personagem::updateMoveComponent(const float& dt){
        this->move_comp.update(dt);
}

void Personagem::jump(const float& gain){
    this->move_comp.jump(gain);
}

void Personagem::onXCollision(const bool& on_collision){
    this->move_comp.onXCollision(on_collision);
}

void Personagem::onYCollision(const bool& on_collision){
    this->move_comp.onYCollision(on_collision);
}

void Personagem::removeVida(const int &n_vidas) {
    this->num_vidas -= n_vidas;
}


// Getters & Setters
MoveComponent& Personagem::getMoveComponent() {
    return this->move_comp;
}

void Personagem::setNumVidas(const int& n_vidas){
    this->num_vidas = n_vidas;
}

const int& Personagem::getNumVidas() const {
    return this->num_vidas;
}
}}};
