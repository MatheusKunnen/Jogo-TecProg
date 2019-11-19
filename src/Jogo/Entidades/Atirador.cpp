//
//  Atirador.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/18/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Atirador.hpp"
#include "../Fases/Fase.hpp"

namespace Game { namespace Entidades { namespace Personagens {

// Constructor & Destructor
Atirador::Atirador(const Vector2f& position, Texture* texture, Jogador* jogador_a, Jogador* jogador_b, Fase* fase, const int& damage):
Inimigo(position, texture, jogador_a, jogador_b, damage),
fase(fase),
projetil_speed(1)
{
    
}

Atirador::~Atirador(){
    
}

// Methods
void Atirador::updatePlayerAttack() {
    // Espera para voltar a atacar
    if (this->idle_time < this->attack_delay)
        return;
    
    Vector2f distance, max_distance;
    // Verifica se jogador_a esta na distancia necessaria para ataca-lo
    if (this->jogador_a){
        distance = Entidade::distanceV(this->jogador_a, this);
        max_distance = Entidade::maxDistanceV(this->jogador_a, this);
        max_distance.x *= 20;
        
        if ((distance.x <= max_distance.x && distance.y < max_distance.y) && (distance.y <= max_distance.y && distance.x < max_distance.x))
            this->attack(jogador_a);
    }
    // Verifica se jogador_b esta na distancia necessaria para ataca-lo
    if (this->jogador_b){
        distance = Entidade::distanceV(this->jogador_b, this);
        max_distance = Entidade::maxDistanceV(this->jogador_a, this);
        max_distance.x *= 10;
        
        if ((distance.x <= max_distance.x && distance.y < max_distance.y) && (distance.y <= max_distance.y && distance.x < max_distance.x))
            this->attack(jogador_b);
    }
    // Reseta idle_time
    this->idle_time = 0.f;
}

void Atirador::attack(Jogador *jogador) {
    this->atirar((jogador->getPosition().x - this->getPosition().x > 0) ? 1 : -1);
}

/*void Atirador::autoMove(const float &dt) {
 this->move(Vector2f(this->getAmplitudeMov() * std::cos(this->getVelMov()*this->time_mov), 0), dt);
 }
 
 void Atirador::atirar(const short &direction) {
 this->fase->createProjetil(this->sprite.getPosition(), direction, this->damage, this->projetil_speed);
 }*/

}}}
