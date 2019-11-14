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
    this->l_personagens.clear();
}

// Methods
void GerenciadorColisoes::gerenciarColisoes(){
    this->gerenciarColisoesMapa();
    this->gerenciarColisoesEntidades();
}

void GerenciadorColisoes::gerenciarColisoesMapa() {
    if (!this->l_personagens.beginItr())
        return;
    do {
        checkMapCollision(this->l_personagens.getItr());
    } while (this->l_personagens.nextItr());
}

void GerenciadorColisoes::gerenciarColisoesEntidades() {
    
}

void GerenciadorColisoes::checkMapCollision(Personagem *personagem){
    //cout << "left:" << personagem->getGlobalBounds().left << " top:" << personagem->getGlobalBounds().top <<  " height:" << personagem->getGlobalBounds().height << " widht:" << personagem->getGlobalBounds().width << endl;
    const FloatRect& bounds = personagem->getGlobalBounds();
    if (this->mapa.isSolidPixel(Vector2f(bounds.left, bounds.top + bounds.height)) ||
                    this->mapa.isSolidPixel(Vector2f(bounds.left + bounds.width, bounds.top + bounds.height)))
        personagem->getMoveComponent()->stopY();
    if (this->mapa.isSolidPixel(Vector2f(bounds.left, bounds.top + bounds.height-10)) ||
                    this->mapa.isSolidPixel(Vector2f(bounds.left + bounds.width, bounds.top + bounds.height-10)))
        personagem->getMoveComponent()->stopX();
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
