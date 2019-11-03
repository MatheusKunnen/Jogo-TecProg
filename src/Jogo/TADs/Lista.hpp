//
//  Lista.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/2/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Lista_hpp
#define Lista_hpp

#include "../base_includes.hpp"
namespace Game { namespace TADs {

template<class Tipo>
class Lista{
protected:
    // Nested Class
    template<class TipoE>
    class Elemento{
    private:
        // Attributes
        Elemento*   next;
        Elemento*   prev;
        TipoE*      elemento;
        bool        liberar;
    public:
        // Constructor && Destructor
        explicit Elemento(TipoE& elemento, bool liberar = true):
        elemento(&elemento), next(nullptr), prev(nullptr), liberar(liberar){ };
        ~Elemento() {
            if (liberar) // Verifica que deve-se desalocar o elemento
                delete elemento;
            next = prev = elemento = nullptr;
            
        };
        // Getters & Setters
        void setNext(const Elemento* next) {this->next = next; };
        Elemento* getNext() const { return this->next; };
        void setPrev(const Elemento* prev) {this->prev = prev; };
        Elemento* getPrev() const { return this->prev; };
        void set(TipoE* elemento) { this->elemento = elemento; };
        TipoE* get() const { return this->elemento; };
        // Operators
        Elemento* operator++() const { return this->getNext(); };
        Elemento* operator--() const { return this->getPrev(); };
        void operator=(TipoE& elemento) { this->set(elemento); };
        bool operator==(TipoE& elemento) { return this->elemento == elemento; };
    };
    // Attributes
    Elemento<Tipo>*      p_first;
    Elemento<Tipo>*      p_last;
    int                  lenght;
public:
    // Constructor & Destructor
    Lista(): p_first(nullptr), p_last(nullptr), lenght(0){ }
    ~Lista() { clearAll(); };
    // Getters & Setters
    const int getLenght() const { return this->lenght; };
    // Methods
    void addFront(Tipo& elemento, bool liberar = true) {
        this->add(elemento, liberar, true);
    }
    void addLast(Tipo& elemento, bool liberar = true) {
        this->add(elemento, liberar, false);
    }
    void add(Tipo& elemento, bool liberar, bool front) {
        Elemento<Tipo>* novo = new Elemento<Tipo*>(elemento, liberar);
        if (front){
            novo->setNext(this->p_first);
            this->p_first->setPrev(novo);
            this->p_first = novo;
        } else {
            novo->setPrev(this->p_last);
            this->p_last->setNext(novo);
            this->p_last = novo;
        }
            
    }
    void remove(Tipo& elemento){
        auto itr = this->p_first;
        while (itr != nullptr){
            if (itr == elemento){
                if (itr->getNext() != nullptr)
                    itr->getNext()->setPrev(itr->getPrev());
                if (itr->getPrev() != nullptr)
                    itr->getPrev()->setNext(itr->getNext());
                delete itr; // Elimina elemento
                break;
            }
            itr = itr++; // Navega para o seguinte elemento
        }
    }
    Tipo* get(int i_elemento) const {
        if (i_elemento >= lenght) // Verifica que o indice seja valido
            throw runtime_error("ERROR: get(): Index out of range");
        
        int i;
        Elemento<Tipo> itr = this->p_first;
        for (i = 0; i <= i_elemento; i++) // Busca o elemento
            itr = itr++;
        
        return itr->get(); // Retorna o solicitado
    }
    void clearAll(){ // Limpa todos os elementos
        this->lenght = 0;
        Elemento<Tipo>* aux;
        while(this->p_first != nullptr){
            aux = this->p_first++;
            delete this->p_first;
            this->p_first = aux;
        }
    };
    // Operators
    virtual void operator+=(Tipo& elemento) { this->addFront(elemento); };
    virtual void operator-=(Tipo& elemento) { this->remove(elemento); };
    virtual Tipo& operator[](int index) { return this->get(index); };
};
}}


#endif /* Lista_hpp */