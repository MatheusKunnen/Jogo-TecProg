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

const string ListaEntidades::toJson() const {
    stringstream s_id, s_x, s_y;
    auto i = lista_entidades.begin();
    
    // Abre e Inicia array json
    s_id << "\"e_id\":[" << i->get()->getId();
    s_x  << "\"e_x\":[" << i->get()->getPosition().x;
    s_y  << "\"e_y\":[" << i->get()->getPosition().y;
    i = i->getNext();
    
    // Carrega Array json
    while (i != nullptr){
        if(i->get() != nullptr && !i->get()->isEnding()){
            s_id << "," << i->get()->getId();
            s_x << "," << i->get()->getPosition().x;
            s_y << "," << i->get()->getPosition().y;
        }
        i = i->getNext();
    }
    
    // Fecha array json
    s_id << "],";
    s_x << "],";
    s_y << "]";
    
    // Junta tudo em um unico json
    stringstream global;
    global << s_id.str() << s_x.str() << s_y.str() << endl;
    
    // Retorna string com dados em formato json
    return global.str();
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
    this->itr = lista_entidades.begin();
    while(itr != nullptr){
        if(itr->get() != nullptr && !itr->get()->isEnding())
            itr->get()->update(dt);
            itr = itr->getNext();
    }
}

}};
