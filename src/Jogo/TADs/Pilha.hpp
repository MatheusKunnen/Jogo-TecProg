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
    Pilha(): Lista<Tipo>() { };
    ~Pilha() { };
    // Methods
    Tipo* top() const { return this->p_first->get(); };
    void push(Tipo* elemento, const bool& liberar = true) { this->addFront(elemento, liberar); };
    void pop() {
        this->remove(this->p_first->get());
    };
    void clear(){ this->clearAll(); };
    const bool empty() const { return this->lenght <= 0; };
    // Operators
    void operator--() { this->pop(); };
};

}};

#endif /* Pilha_hpp */
