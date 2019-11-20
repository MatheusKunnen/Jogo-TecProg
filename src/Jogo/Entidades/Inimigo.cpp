//
//  Inimigo.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Inimigo.hpp"

namespace Game { namespace Entidades { namespace Personagens {

Inimigo::Inimigo(const Vector2f& position, Texture* texture, Jogador* jogador_a, Jogador* jogador_b, const int& damage):
Personagem(position, texture),
jogador_a(jogador_a),
jogador_b(jogador_b),
damage(damage),
amplitude_mov(5),
vel_mov(5),
time_mov(0),
idle_time(0),
attack_delay(3)
{
    
}

Inimigo::~Inimigo(){
    
}

// Methods
void Inimigo::update(const float& dt){
    // Atualiza tempo ataque
    this->idle_time += dt;
    // Atualiza paso de movimento
    this->autoMove(dt);
    // Atualiza componente de movimento
    this->move_comp.update(dt);
    // Verifica se pode atacar ao jogador
    this->updatePlayerAttack();
}

void Inimigo::updatePlayerAttack(){
    // Espera para voltar a atacar
    if (this->idle_time < this->attack_delay)
        return;
    
    Vector2f distance, max_distance;
    // Verifica distancia de ataque com jogador
    if (jogador_a){
        distance = Entidade::distanceV(this->jogador_a, this);
        max_distance = Entidade::maxDistanceV(this->jogador_a, this);
        
        if ((distance.x <= max_distance.x && distance.y < max_distance.y) && (distance.y <= max_distance.y && distance.x < max_distance.x))
            this->attack(jogador_a);
    }
    // Verifica distancia de ataque com jogador
    if (this->jogador_b){
        distance = Entidade::distanceV(this->jogador_b, this);
        max_distance = Entidade::maxDistanceV(this->jogador_a, this);
        
        if ((distance.x <= max_distance.x && distance.y < max_distance.y) && (distance.y <= max_distance.y && distance.x < max_distance.x))
            this->attack(jogador_b);
    }
    
    // Reseta valor de idle time
    this->idle_time = 0.f;
}

// Getters & Setters
void Inimigo::setDamage(const float &damage) {
    this->damage = damage;
}

const float& Inimigo::getDamage() const {
    return this->damage;
}

void Inimigo::setAmplitudeMov(const float& amplitude_mov) {
    this->amplitude_mov = amplitude_mov;
}

const float& Inimigo::getAmplitudeMov() const {
    return this->amplitude_mov;
}

void Inimigo::setVelMov(const float &vel_mov) {
    this->vel_mov = vel_mov;
}

const float& Inimigo::getVelMov() const {
    return this->vel_mov;
}

void Inimigo::setAttackDelay(const float &attack_delay) {
    this->attack_delay = attack_delay;
}

const float& Inimigo::getAttackDelay() const {
    return this->attack_delay;
}

}}}
