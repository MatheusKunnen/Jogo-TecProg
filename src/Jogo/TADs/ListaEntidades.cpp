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
    this->lista_entidades.addLast(entidade, liberar);
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
        if(itr->get() != nullptr && !itr->get()->isEnding())
            itr->get()->render(target);
        itr = itr->getNext();
    }
}

void ListaEntidades::update(const float &dt){
    //this->clearEnding();
    this->itr = lista_entidades.begin();
    while(itr != nullptr){
        if(itr->get() != nullptr && !itr->get()->isEnding())
            itr->get()->update(dt);
            itr = itr->getNext();
    }
}

void ListaEntidades::clearEnding(){
    this->itr =lista_entidades.begin();
    Entidade* entidade = nullptr;
    while(itr != nullptr){
        entidade = itr->get();
        itr = itr->getNext();
        if(entidade->isEnding())
            this->lista_entidades.remove(entidade);

    }
}
}};
