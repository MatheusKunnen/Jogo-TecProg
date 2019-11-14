//
//  GerenciadorColisoes.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/13/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef GerenciadorColisoes_hpp
#define GerenciadorColisoes_hpp

#include "../TADs/ListaPersonagens.hpp"
#include "../TADs/ListaEntidades.hpp"
#include "../Entidades/Jogador.hpp"
#include "../Entidades/level.hpp"

namespace Game { namespace Gerenciadores {

using Entidades::Mapas::Mapa;
using Entidades::Personagens::Personagem;
using Entidades::Personagens::Jogador;
using TADs::ListaPersonagens;
using TADs::ListaEntidades;

class GerenciadorColisoes {
private:
    // Attributes
    ListaPersonagens    l_personagens;
    ListaEntidades&     l_entidades;
    Mapa&               mapa;
    
public:
    // Constructor & Destructor
    GerenciadorColisoes(Mapa& mapa, ListaEntidades& l_entidades);
    ~GerenciadorColisoes();
    
    // Methods
    void gerenciarColisoes();
    void gerenciarColisoesMapa();
    void gerenciarColisoesEntidades();
    void checkMapCollision(Personagem* personagem);
    void addPersonagem(Personagem* personagem);
    void clear();
    // Operadores
    void operator+=(Personagem* personagem);
};

}}
#endif /* GerenciadorColisoes_hpp */