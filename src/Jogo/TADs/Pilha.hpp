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
class Pilha{
private:
    Lista<Tipo> lista;
public:
    // Constructor & Destructor
    Pilha(): lista() { };
    ~Pilha() { };
    // Methods
    Tipo* top() const { return this->lista.getFirst(); };
    void push(Tipo* elemento, const bool& liberar = true) { this->lista.addFront(elemento, liberar); };
    void pop() {
        this->lista.remove(this->lista.getFirst());
    };
    void clear(){ this->lista.clearAll(); };
    const bool empty() const { return this->lista.count() <= 0; };
    // Operators
    void operator--() { this->lista->pop(); };
};

}};

#endif /* Pilha_hpp */
