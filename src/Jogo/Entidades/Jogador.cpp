//
//  Jogador.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Jogador.hpp"
namespace Game { namespace Entidades { namespace Personagens {

// Const
const Vector2f Jogador::lifebar_size(64.f, 10.f);
const sf::Color Jogador::lifebar_color(255, 0, 0);
const int Jogador::max_life(15);

// Constructor & Destructor
Jogador::Jogador(const Vector2f& position, Texture* texture):
Personagem(position, texture, Jogador::max_life)
{
    this->initLifeBar();
}

Jogador::~Jogador(){
    
}

// Init Methods
void Jogador::initLifeBar(){
    this->life_bar.setSize(Jogador::lifebar_size);
    this->life_bar.setFillColor(Jogador::lifebar_color);
    
}

//Methods
void Jogador::update(const float &dt){
    this->total_dt += dt;
    this->move_comp.update(dt);
    this->updateLifeBar();
}

void Jogador::updateLifeBar() {
    Vector2f pos = this->getPosition();
    pos.y -= 32;
    this->life_bar.setPosition(pos);
    this->life_bar.setScale(this->getNumVidas()/Jogador::max_life, 1);
}

void Jogador::render(RenderTarget *target){
    target->draw(this->sprite);
    this->renderLifeBar(target);
}

void Jogador::renderLifeBar(RenderTarget *target){
    target->draw(this->life_bar);
}

void Jogador::reset(){
    this->setNumVidas(Jogador::max_life);
    this->total_dt = 0;
    this->move_comp.reset();
}

// Getters & Setters
const int Jogador::getScore() const {
    return (pow(this->getNumVidas(), 2) / pow(this->total_dt, 2)) * 10000;
}
}}};
