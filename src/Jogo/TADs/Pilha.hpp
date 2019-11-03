//
//  Pilha.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/2/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Pilha_hpp
#define Pilha_hpp

#include "Lista.hpp"

namespace Game { namespace TADs {

template<class Tipo>
class Pilha : protected Lista<Tipo> {
public:
    // Constructor & Destructor
    Pilha(): Lista() { };
    ~Pilha() { };
    // Methods
    Tipo* top() const { return this->first; };
    void push(Tipo& elemento) { this->addFront(elemento, false); };
    void pop() {
        Tipo* elemento = this->first;
        this->remove(this->first);
    }
}
}};

#endif /* Pilha_hpp */
