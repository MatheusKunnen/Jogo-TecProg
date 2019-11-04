//
//  ListaEntidades.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef ListaEntidades_hpp
#define ListaEntidades_hpp

#include "Lista.hpp"
#include "../Entidades/Entidade.hpp"

namespace Game { namespace TADs{
using Entidades::Entidade;

class ListaEntidades {
private:
    // Attributes
    Lista<Entidade>                      lista_entidades;
    Lista<Entidade>::Elemento<Entidade>* itr;
public:
    // Cosntructor & Destructor
    ListaEntidades();
    ~ListaEntidades();
    // Methods
    void add(Entidade* entidade, const bool& liberar = true);
    void clear();
    void operator+=(Entidade* entidade);
    void render(RenderTarget* target);
    void update(const float& dt);
};

}};
#endif /* ListaEntidades_hpp */
