//
//  MoveComponent.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "MoveComponent.hpp"

namespace Game { namespace Entidades {

const float MoveComponent::ACELERATION_GAIN(100);
const Vector2f MoveComponent::DEFAULT_MAX_SPEED(300.f, 250.f);
const Vector2f MoveComponent::DEFAULT_ACELERATION(2000.f, 10000.f);
const Vector2f MoveComponent::DEFAULT_DECELERATION(500.f,1000.f);

MoveComponent::MoveComponent(Sprite* sprite, const Vector2f& max_speed, const Vector2f& v_aceleration, const Vector2f& v_deceleration):
player_sprite(sprite),
max_speed(max_speed),
v_speed(0.f,0.f),
v_aceleration(v_aceleration),
v_deceleration(v_deceleration),
v_direction(0.f,0.f),
x_collision(false),
y_collision(false)
{
    
}

MoveComponent::~MoveComponent(){
    
}

// Methods
void MoveComponent::update(const float &dt){
    // EIXO X
    // Move a sprite da personagem
    this->player_sprite->move(this->v_speed.x * dt + this->v_aceleration.x*this->v_direction.x*dt*dt/2, 0);
    // Atualiza velocidade
    this->v_speed.x += v_aceleration.x * v_direction.x * dt;
    
    if (this->v_speed.x > 0.f) {
        // Verifica limite de velocidade
        if (this->v_speed.x > this->max_speed.x)
            this->v_speed.x = this->max_speed.x;
        
        // Desacelera caso nao tenha movimento
        if (this->v_direction.x == 0)
            this->v_speed.x -= v_deceleration.x * dt;
        
        // Verifica quando a velocidade inverteu
        if (this->v_speed.x < 0.f)
            this->v_speed.x = 0.f;
    } else if(this->v_speed.x < 0.f) {
        // Verifica limite de velocidade
        if (this->v_speed.x < -this->max_speed.x)
            this->v_speed.x = -this->max_speed.x;
        
        // Desacelera caso nao tenha movimento
        if (this->v_direction.x == 0)
            this->v_speed.x += v_deceleration.x * dt;
        
        // Verifica quando a velocidade inverteu
        if (this->v_speed.x > 0.f)
            this->v_speed.x = 0.f;
    }
    this->v_direction.x = 0; // Reseta direcao do movimento
    
    // EIXO Y
    if (v_speed.y < 0 ) { // Caso jogador saltou
        
        this->player_sprite->move(0.f, this->v_speed.y * dt + this->v_aceleration.y*dt*dt/2);
        
        this->v_speed.y += this->v_aceleration.y*dt;
        
        this->y_collision = false;
    } else if (this->y_collision) { // Caso personagem colide
        this->v_speed.y = 0; // Anula velocidade
    } else { // Caso queda livre
        this->v_speed.y = this->max_speed.y; // Coloca velocidade de queda
        this->player_sprite->move(0.f,this->v_speed.y * dt);
    }
    
    
}

void MoveComponent::move(const Vector2f& direction, const float& dt){
    // Adiciona direcao solicitada
    this->v_direction += direction;
}

void MoveComponent::jump(const float& gain){
    if (this->y_collision) // Verifica que esteja tocando o chao
        this->v_speed.y = -200*gain;
}

void MoveComponent::reset() {
    this->setVSpeed(Vector2f(0.f, 0.f)); // Reseta velocidades
}

void MoveComponent::onXCollision(const bool& on_collision) {
    this->x_collision = on_collision;
    if (this->x_collision) {
        this->v_direction.x *= -1; // Inverte direcao do movimento
        this->v_speed.x *= this->v_speed.x < 0 && this->v_direction.x< 0 ? 1 : -1; // Reduz e inverte velocidade
    }
}

void MoveComponent::onYCollision(const bool& on_collision) {
    this->y_collision = on_collision;
}

// Getters & Setters
const Vector2f MoveComponent::getMaxSpeed() const {
    return max_speed;
}

void MoveComponent::setMaxSpeed(const Vector2f& maxSpeed) {
    max_speed = maxSpeed;
}

const Vector2f &MoveComponent::getVSpeed() const {
    return v_speed;
}

void MoveComponent::setVSpeed(const Vector2f &vSpeed) {
    v_speed = vSpeed;
}

const Vector2f &MoveComponent::getAceleration() const {
    return v_aceleration;
}

void MoveComponent::setAceleration(const Vector2f& vAceleration) {
    v_aceleration += vAceleration;// * MoveComponent::ACELERATION_GAIN;
}

const Vector2f &MoveComponent::getDeceleration() const {
    return v_deceleration;
}

void MoveComponent::setDeceleration(const Vector2f &vDeceleration) {
    v_deceleration = vDeceleration;// * MoveComponent::ACELERATION_GAIN;
}

}}
