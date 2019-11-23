//
//  GerenciadorColisoes.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/13/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "GerenciadorColisoes.hpp"

namespace Game { namespace Gerenciadores {
  
// Constructor & Destructor
GerenciadorColisoes::GerenciadorColisoes(Mapa& mapa):
l_personagens(),
l_obstaculos(),
mapa(mapa)
{
    
}

GerenciadorColisoes::~GerenciadorColisoes(){
    this->l_personagens.clear(); // Limpa lista personagens
}

// Methods
void GerenciadorColisoes::gerenciarColisoes(){
    this->clearEndingObj();
    // Chama gerenciadores de colisoes
    this->gerenciarColisoesPM();
    this->gerenciarColisoesPP();
    this->gerenciarColisoesPO();
}

void GerenciadorColisoes::gerenciarColisoesPM() {
    if (!this->l_personagens.beginItr())
        return;
    // Verifica colisao com o mapa con todos os personagens
    do {
        checkCollision(this->l_personagens.getItr());
    } while (this->l_personagens.nextItr());
}

void GerenciadorColisoes::gerenciarColisoesPP() {
    int i, j;
    // Obtem nro de jogadores
    long count = this->l_personagens.getCount();
    // Verifica colisoes entre todos os personagens da lista
    for(i = 0; i<count-1 ; i++)
        for(j = i+1; j < count; j++)
            if(!this->l_personagens[i]->isEnding() && !this->l_personagens[j]->isEnding())
                checkCollision(this->l_personagens[i], this->l_personagens[j]);
}

void GerenciadorColisoes::gerenciarColisoesPO() {
    int i, j;
    // Obtem nro de personagens e obstaculos
    long count_personagens = this->l_personagens.getCount(),
         count_obstaculos = this->l_obstaculos.getCount();
        // Verifica colisoes entre todos os personagens e obstaculos
    for(i = 0; i < count_personagens; i++)
        for (j = 0; j < count_obstaculos; j++)
            if(!this->l_personagens[i]->isEnding() && !this->l_obstaculos[j]->isEnding())
                checkCollision(this->l_personagens[i], this->l_obstaculos[j]);
}

void GerenciadorColisoes::checkCollision(Personagem *personagem){
    // Obtem posicao/tamanho personagem
    const FloatRect& bounds = personagem->getGlobalBounds();
    
    // Verifica colisao com chao do mapa
    if (this->mapa.isSolidPixel(Vector2f(bounds.left, bounds.top + bounds.height)) ||
                    this->mapa.isSolidPixel(Vector2f(bounds.left + bounds.width, bounds.top + bounds.height)))
        personagem->onYCollision(true);
    else
        personagem->onYCollision(false);
    
    // Verifica colisao com paredes
    if (this->mapa.isSolidPixel(Vector2f(bounds.left, bounds.top + bounds.height-10)) ||
                    this->mapa.isSolidPixel(Vector2f(bounds.left + bounds.width, bounds.top + bounds.height-10)))
        personagem->onXCollision(true);
    else
        personagem->onXCollision(false);
}

void GerenciadorColisoes::checkCollision(Personagem *personagem_a, Personagem *personagem_b) {
    // Calcula vetor de distancia e distancia maxima
    const Vector2f      distance = Entidade::distanceV(personagem_a, personagem_b),
                    max_distance = Entidade::maxDistanceV(personagem_a, personagem_b);
    // Verifica colisao em X
    if (distance.x <= max_distance.x && sqrt(distance.y < max_distance.y - 100)){
        personagem_a->onXCollision(true);
        personagem_b->onXCollision(true);
    }
    // Verifica colisao em Y
    if (distance.y <= max_distance.y && distance.x < max_distance.x - 100){
        personagem_a->onYCollision(true);
        personagem_b->onYCollision(true);
    }
}

void GerenciadorColisoes::checkCollision(Personagem *personagem, Obstaculo *obstaculo) {
    // Calcula vetor de distancia e distancia maxima
    const Vector2f      distance = Entidade::distanceV(personagem, obstaculo),
                    max_distance = Entidade::maxDistanceV(personagem, obstaculo);
    // Verifica colisao
    if ((distance.x <= max_distance.x && distance.y < max_distance.y) && (distance.y <= max_distance.y && distance.x < max_distance.x)) {
        obstaculo->onCollision(personagem);
    }
}

void GerenciadorColisoes::add(Personagem *personagem) {
    this->l_personagens += personagem;
}

void GerenciadorColisoes::add(Obstaculo *obstaculo) {
    this->l_obstaculos += obstaculo;
}

void GerenciadorColisoes::clearEndingObj() {
    this->l_personagens.clearEnding();
    this->l_obstaculos.clearEnding();
}
    
void GerenciadorColisoes::clear(){
    this->l_personagens.clear();
}
// Operators
void GerenciadorColisoes::operator+=(Personagem *personagem){
    this->add(personagem);
}

void GerenciadorColisoes::operator+=(Obstaculo *obstaculo){
    this->add(obstaculo);
}
    
}}
