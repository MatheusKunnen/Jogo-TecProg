//
//  ListaEntidades.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "ListaEntidades.hpp"

namespace Game { namespace TADs{

ListaEntidades::ListaEntidades():
lista_entidades(),
itr(nullptr)
{
    
}

ListaEntidades::~ListaEntidades(){
    this->clear();
}

void ListaEntidades::add(Entidade *entidade, const bool& liberar){
    this->lista_entidades.addFront(entidade, liberar);
}

void ListaEntidades::clear(){
    this->lista_entidades.clearAll();
}

void ListaEntidades::operator+=(Entidade* entidade){
    this->add(entidade, true);
}

void ListaEntidades::render(RenderTarget *target){
    this->itr = lista_entidades.begin();
    while (itr != nullptr){
        itr->get()->render(target);
        itr++;
    }
}

void ListaEntidades::update(const float &dt){
    this->itr =lista_entidades.begin();
    while(itr != nullptr){
        itr->get()->update(dt);
        itr++;
    }
}
}};
