//
//  ListaObstaculos.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/17/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "ListaObstaculos.hpp"

namespace Game { namespace TADs {

// Constructor & Destructor
ListaObstaculos::ListaObstaculos():
l_obstaculos()
{
    
}

ListaObstaculos::~ListaObstaculos(){
    this->clear();
}

// Methods
void ListaObstaculos::add(Obstaculo *obstaculo) {
    this->l_obstaculos.push_back(obstaculo);
}

Obstaculo* ListaObstaculos::get(const int &i) {
    // Verifica se elemento esta dentro da lista
    if (i >= this->l_obstaculos.size())
        throw runtime_error("ERROR: ListaObstaculos::get(): index out of bounds.\n");
    // Inicia iterador da lista
    this->itr = this->l_obstaculos.begin();
    int j;
    // Busca elemento
    for (j = 0; j < i; j++, itr++) { }
    // Retorna Elemento
    return *this->itr;
}

void ListaObstaculos::clear() {
    this->l_obstaculos.clear();
}

// Getters & Setters
const long ListaObstaculos::getCount() const {
    // Retorna nro de elementos
    return this->l_obstaculos.size();
}

// Operators
void ListaObstaculos::operator+=(Obstaculo* obstaculo) {
    this->add(obstaculo);
}

Obstaculo* ListaObstaculos::operator[](const int& i){
    return this->get(i);
}

}}
