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
const float MoveComponent::DEFAULT_MAX_SPEED = 1;
const float MoveComponent::DEFAULT_ACELERATION = 1.f;
const float MoveComponent::DEFAULT_DECELERATION = 1.f;

MoveComponent::MoveComponent(Sprite* sprite,  float& gravity, const float& max_speed, const float& aceleration, const float& deceleration):
sprite(sprite),
max_speed(max_speed),
gravity(gravity),
v_speed(200.f,100.f),
v_aceleration(aceleration * MoveComponent::ACELERATION_GAIN),
v_deceleration(deceleration * MoveComponent::ACELERATION_GAIN),
v_direction(0,0)
{
    
}

MoveComponent::~MoveComponent(){
    
}

// Methods
void MoveComponent::update(const float &dt){
    // Move texture
    this->sprite->move(this->max_speed*this->v_direction.x*dt,this->v_speed.y*this->v_direction.y*dt);
    this->v_direction.x = this->v_direction.y = 0.f;
    
    // Calculates vel direction
    //this->v_direction.x = (this->v_speed.x != 0) ? (this->v_speed.x > 0) ? 1 : -1 : 0;
    //this->v_direction.y =(this->v_speed.y < 0) ? 1 : -1 ;
    
    // Calculate deceleration
    //this->v_speed.x -= (v_deceleration * this->v_direction.x * dt);
    
    //if (this->v_speed.x * this->v_direction.x < 0)
    //    this->v_speed.x  = this->v_direction.x = 0;

}

void MoveComponent::move(const Vector2f& direction, const float& dt){
    this->v_direction += direction;
    // Update Speed vector
    //this->v_speed.x += (v_aceleration * direction.x * dt);
    //this->v_speed.y += (gravity * direction.y * dt);
    // Check for max_speed
    //if (this->v_speed.x  * this->v_direction.x > max_speed)
    //    this->v_speed.x = this->max_speed;
    //if (this->v_speed.y * this->v_direction.y > max_speed)
    //    this->v_speed.y = this->max_speed;
}

void MoveComponent::jump(const float& gain){
    this->v_aceleration = 5*gain;
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

const float &MoveComponent::getAceleration() const {
    return v_aceleration;
}

void MoveComponent::setAceleration(const float &vAceleration) {
    v_aceleration = vAceleration * MoveComponent::ACELERATION_GAIN;
}

const float &MoveComponent::getDeceleration() const {
    return v_deceleration;
}

void MoveComponent::setDeceleration(const float &vDeceleration) {
    v_deceleration = vDeceleration * MoveComponent::ACELERATION_GAIN;
}

void MoveComponent::setGravity(const float& gravity){
    this->gravity = gravity;
}

}}
