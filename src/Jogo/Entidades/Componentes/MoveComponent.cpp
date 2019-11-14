//
//  MoveComponent.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "MoveComponent.hpp"

namespace Game { namespace Entidades {

const float MoveComponent::ACELERATION_GAIN = 100;
const float MoveComponent::DEFAULT_MAX_SPEED = 250;
const float MoveComponent::DEFAULT_ACELERATION = 1.f;
const float MoveComponent::DEFAULT_DECELERATION = 1.f;

MoveComponent::MoveComponent(Sprite* sprite,  float& gravity, const float& max_speed, const float& aceleration, const float& v_deceleration):
sprite(sprite),
max_speed(250),
gravity(gravity),
v_speed(0.f,100.f),
v_aceleration(1000, 10000),//aceleration * MoveComponent::ACELERATION_GAIN),
v_deceleration(500,1000),//v_deceleration * MoveComponent::ACELERATION_GAIN),
v_direction(0,0),
onXCollision(false),
onYCollision(false)
{
    
}

MoveComponent::~MoveComponent(){
    
}

// Methods
void MoveComponent::update(const float &dt){
    if (!onXCollision){
        this->sprite->move(this->v_speed.x * dt + this->v_aceleration.x*this->v_direction.x*dt*dt/2, 0);
        this->v_speed.x += v_aceleration.x * v_direction.x * dt;
        if (this->v_speed.x > 0.f) {
            //Max v_speed check
            if (this->v_speed.x > this->max_speed)
                this->v_speed.x = this->max_speed;
            
            //v_deceleration
            if (this->v_direction.x == 0)
                this->v_speed.x -= v_deceleration.x * dt;
                
            
            if (this->v_speed.x < 0.f)
                this->v_speed.x = 0.f;
        } else if(this->v_speed.x < 0.f) {
            if (this->v_speed.x < -this->max_speed) // Max speed limitation
                this->v_speed.x = -this->max_speed;
            
            // Deceleratin player
            if (this->v_direction.x == 0)
                this->v_speed.x += v_deceleration.x * dt;
            
            if (this->v_speed.x > 0.f)
                this->v_speed.x = 0.f;
        }
        this->v_direction.x = 0;
    } else {
        onXCollision = false;
    }
    
    if (v_speed.y < 0){
        this->sprite->move(0.f, this->v_speed.y * dt + this->v_aceleration.y*dt*dt/2);
        this->v_speed.y += this->v_aceleration.y*dt;
    } else {
        this->v_speed.y = 250;
        this->sprite->move(0.f, this->v_direction.y * this->v_speed.y * dt);
    }
    this->onYCollision = false;
    this->v_direction.y = 1;
    
    
    
}

void MoveComponent::move(const Vector2f& direction, const float& dt){
    this->v_direction += direction;
    this->v_speed.x += this->v_aceleration.x * direction.x * dt;
}

void MoveComponent::jump(const float& gain){
    if (this->onYCollision)
        this->v_speed.y = -250*gain;
}

void MoveComponent::reset() {
    this->setVSpeed(Vector2f(0.f, 0.f));
}

void MoveComponent::stopX() {
    this->onXCollision = true;
    this->v_speed.x = 0.f;
}

void MoveComponent::stopY() {
    this->onYCollision = true;
    this->v_direction.y = 0.f;
}

// Getters & Setters
float MoveComponent::getMaxSpeed() const {
    return max_speed;
}

void MoveComponent::setMaxSpeed(float maxSpeed) {
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

void MoveComponent::setGravity(const float& gravity){
    this->gravity = gravity;
}

}}
