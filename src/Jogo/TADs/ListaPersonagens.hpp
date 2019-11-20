//
//  ListaPersonagens.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/13/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef ListaPersonagens_hpp
#define ListaPersonagens_hpp

#include "../Entidades/Personagem.hpp"
#include <list>

namespace Game { namespace TADs {

using Entidades::Personagens::Personagem;
using std::list;
using std::iterator;

class ListaPersonagens{
private:
    // Attributes
    list<Personagem*>       l_personagens;
    list<Personagem*>::iterator  itr_personagens;
    
    
public:
    // Constructor & Destructor
    ListaPersonagens();
    ~ListaPersonagens();
    
    // Methods
    void add(Personagem* personagem);
    void clearEnding();
    void clear();
    bool beginItr();
    bool nextItr();
    Personagem* getItr() const;
    Personagem* get(const int& i);
    
    // Getters & Setters
    const long getCount() const;
    // Operators
    void operator+=(Personagem* personagem);
    Personagem* operator[](const int& i);
};

}}

#endif /* ListaPersonagens_hpp */
