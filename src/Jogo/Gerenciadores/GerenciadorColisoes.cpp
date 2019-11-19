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
GerenciadorColisoes::GerenciadorColisoes(Mapa& mapa, ListaEntidades& l_entidades):
l_personagens(),
l_obstaculos(),
l_entidades(l_entidades),
mapa(mapa)
{
    
}

GerenciadorColisoes::~GerenciadorColisoes(){
    this->l_personagens.clear(); // Limpa lista personagens
}

// Methods
void GerenciadorColisoes::gerenciarColisoes(){
    // Chama gerenciadores de colisoes
    this->gerenciarColisoesPersonagensMapa();
    this->gerenciarColisoesPersonagensPersonagens();
    this->gerenciarColisoesPersonagensObstaculos();
    this->gerenciarColisoesPersonagensProjeteis();
}

void GerenciadorColisoes::gerenciarColisoesPersonagensMapa() {
    if (!this->l_personagens.beginItr())
        return;
    // Verifica colisao com o mapa con todos os personagens
    do {
        checkMapCollision(this->l_personagens.getItr());
    } while (this->l_personagens.nextItr());
}

void GerenciadorColisoes::gerenciarColisoesPersonagensPersonagens() {
    int i, j;
    long count = this->l_personagens.getCount(); // Obtem nro de jogadores
    // Verifica colisoes entre todos os personagens da lista
    for(i = 0; i<count-1 ; i++)
        for(j = i+1; j < count; j++)
            if(!this->l_personagens[i]->isEnding() && !this->l_personagens[j]->isEnding())
                checkPPCollision(this->l_personagens[i], this->l_personagens[j]);
}

void GerenciadorColisoes::gerenciarColisoesPersonagensObstaculos() {
    int i, j;
    long count_personagens = this->l_personagens.getCount(),
         count_obstaculos = this->l_obstaculos.getCount();
    for(i = 0; i < count_personagens; i++)
        for (j = 0; j < count_obstaculos; j++)
            if(!this->l_personagens[i]->isEnding() && !this->l_obstaculos[j]->isEnding())
                checkPOCollision(this->l_personagens[i], this->l_obstaculos[j]);
}

void GerenciadorColisoes::gerenciarColisoesPersonagensProjeteis() {
    
}



void GerenciadorColisoes::checkMapCollision(Personagem *personagem){
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

void GerenciadorColisoes::checkPPCollision(Personagem *personagem_a, Personagem *personagem_b) {
    // Calcula vetor de distancia e distancia maxima
    const Vector2f      distance = Entidade::distanceV(personagem_a, personagem_b),
                    max_distance = Entidade::maxDistanceV(personagem_a, personagem_b);
    // Verifica colisao em X
    if (distance.x <= max_distance.x && distance.y < max_distance.y - 10){
        personagem_a->onXCollision(true);
        personagem_b->onXCollision(true);
    }
    // Verifica colisao em Y
    if (distance.y <= max_distance.y && distance.x < max_distance.x - 10){
        personagem_a->onYCollision(true);
        personagem_b->onYCollision(true);
    }
}

void GerenciadorColisoes::checkPOCollision(Personagem *personagem, Obstaculo *obstaculo) {
    // Calcula vetor de distancia e distancia maxima
    const Vector2f      distance = Entidade::distanceV(personagem, obstaculo),
                    max_distance = Entidade::maxDistanceV(personagem, obstaculo);
    // Verifica colisao
    if ((distance.x <= max_distance.x && distance.y < max_distance.y) && (distance.y <= max_distance.y && distance.x < max_distance.x)) {
        obstaculo->onCollision(personagem);
    }
}

const Vector2f GerenciadorColisoes::distance(const FloatRect& a, const FloatRect& b){
    return Vector2f(pow((a.left + a.width/2) - (b.left + b.width/2), 2),
                    pow((a.top + a.height/2) - (b.top + b.height/2), 2));
}

void GerenciadorColisoes::addPersonagem(Personagem *personagem) {
    this->l_personagens += personagem;
}

void GerenciadorColisoes::addObstaculo(Obstaculo *obstaculo) {
    this->l_obstaculos += obstaculo;
}
    
void GerenciadorColisoes::clear(){
    this->l_personagens.clear();
}
// Operators
void GerenciadorColisoes::operator+=(Personagem *personagem){
    this->addPersonagem(personagem);
}

void GerenciadorColisoes::operator+=(Obstaculo *obstaculo){
    this->addObstaculo(obstaculo);
}
    
}}
