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
            checkPPCollision(this->l_personagens[i], this->l_personagens[j]);
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
    // Obtem posicoes/tamanhos dos personagens
    const FloatRect&    bounds_a = personagem_a->getGlobalBounds(),
                        bounds_b = personagem_b->getGlobalBounds();
    // Calcula vetor de distancia e distancia maxima
    const Vector2f      distance = this->distance(bounds_a, bounds_b),
                        max_distance(pow(bounds_b.width/2 + bounds_a.width/2, 2), pow(bounds_b.height/2 + bounds_a.height/2, 2));
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

const Vector2f GerenciadorColisoes::distance(const FloatRect& a, const FloatRect& b){
    return Vector2f(pow((a.left + a.width/2) - (b.left + b.width/2), 2),
                    pow((a.top + a.height/2) - (b.top + b.height/2), 2));
}

void GerenciadorColisoes::addPersonagem(Personagem *personagem) {
    this->l_personagens += personagem;
}
    
void GerenciadorColisoes::clear(){
    this->l_personagens.clear();
}
// Operators
void GerenciadorColisoes::operator+=(Personagem *personagem){
    this->addPersonagem(personagem);
}
    
}}
