//
//  NarcotraficanteDesmatador.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/19/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "NarcotraficanteDesmatador.hpp"
#include "../Fases/Fase.hpp"

namespace Game { namespace Entidades { namespace Personagens{
// Const
const float NarcotraficanteDesmatador::DAMAGE(5.f);
const float NarcotraficanteDesmatador::DELAY_TIME(1.f);
const float NarcotraficanteDesmatador::ATTACK_DISTANCE(1280.f);
const float NarcotraficanteDesmatador::VEL_PROJETIL(12.f);

// Constructor & Destructor
NarcotraficanteDesmatador::NarcotraficanteDesmatador(const Vector2f& position, Texture* texture, Jogador* jogador_a, Jogador* jogador_b, Fase* fase):
Atirador(boss, position, texture, jogador_a, jogador_b, fase, NarcotraficanteDesmatador::VEL_PROJETIL, NarcotraficanteDesmatador::DAMAGE)
{
    this->setAttackDelay(NarcotraficanteDesmatador::DELAY_TIME);
}

NarcotraficanteDesmatador::~NarcotraficanteDesmatador() {
    
}

// Methods
void NarcotraficanteDesmatador::updatePlayerAttack(){
    // Espera para voltar a atacar
    if (this->idle_time < this->attack_delay)
        return;
    
    Vector2f distance, max_distance;
    // Verifica se jogador_a esta na distancia necessaria para ataca-lo
    if (this->jogador_a){
        distance = Entidade::distanceV(this->jogador_a, this);
        
        if ((distance.x <= pow(NarcotraficanteDesmatador::ATTACK_DISTANCE,2)))
            this->attack(jogador_a);
    }
    // Verifica se jogador_b esta na distancia necessaria para ataca-lo
    if (this->jogador_b){
        distance = Entidade::distanceV(this->jogador_b, this);
        
        if ((distance.x <= pow(NarcotraficanteDesmatador::ATTACK_DISTANCE,2)))
            this->attack(jogador_b);
    }
    // Reseta idle_time
    this->idle_time = 0.f;
}

void NarcotraficanteDesmatador::autoMove(const float &dt) {
    this->time_mov+= dt;
    this->move(Vector2f(this->getAmplitudeMov()*std::cos(this->getVelMov()*this->time_mov), 0), dt);
}

void NarcotraficanteDesmatador::atirar(const short &direction) {
    Vector2f pos = this->sprite.getPosition();
    pos.x = (direction > 0) ? pos.x + this->getGlobalBounds().width + 32.f: pos.x - 32.f;
    pos.y += this->getGlobalBounds().height - 64.f;
    this->fase->createProjetil(pos, direction, this->damage, this->vel_projetil);
}

}}}



