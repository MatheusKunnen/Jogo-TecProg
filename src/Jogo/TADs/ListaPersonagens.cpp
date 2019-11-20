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

Personagem* ListaPersonagens::get(const int &i){
    if (i >= this->getCount()) // Verifica que o elemento esteja na lista
        return nullptr;
    // Inicia iterador
    list<Personagem*>::iterator itr = this->l_personagens.begin();
    // Vai até a posicao do elemento
    int j;
    for(j = 0; j < i; j++, itr++);
    // Retorna elemento
    return *itr;
}

void ListaPersonagens::clearEnding() {
    //for (Personagem* per : this->l_personagens)
    //    if (per->isEnding())
    //        this->l_personagens.remove(per);
}

// Getters && setters
const long ListaPersonagens::getCount() const {
    return this->l_personagens.size();
}
    
// Operators
void ListaPersonagens::operator+=(Personagem* personagem){
    this->add(personagem);
}

Personagem* ListaPersonagens::operator[](const int &i){
    return this->get(i);
}
}}
