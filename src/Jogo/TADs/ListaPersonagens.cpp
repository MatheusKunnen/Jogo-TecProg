//
//  ListaPersonagens.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/13/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "ListaPersonagens.hpp"

namespace Game { namespace TADs {

// Constructor & Destructor
ListaPersonagens::ListaPersonagens():
l_personagens(),
itr_personagens()
{
    
}

ListaPersonagens::~ListaPersonagens(){
    this->clear();
}

// Methods
void ListaPersonagens::add(Personagem *personagem){
    if (personagem != nullptr)
        this->l_personagens.push_back(personagem);
}

void ListaPersonagens::clear(){
    this->l_personagens.clear();
}

bool ListaPersonagens::beginItr() {
    if (this->l_personagens.empty()) // Verifica que a lista nao esteja vazia
        return false;
    this->itr_personagens = this->l_personagens.begin(); // Inicia iterador
    return true;
}

bool ListaPersonagens::nextItr(){
    itr_personagens++;
    if (this->itr_personagens == this->l_personagens.end())
        return false;
    return true;
}

Personagem* ListaPersonagens::getItr() const {
    return *this->itr_personagens;
}

// Operators
void ListaPersonagens::operator+=(Personagem* personagem){
    this->add(personagem);
}
}}
