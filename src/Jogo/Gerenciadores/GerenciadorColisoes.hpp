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
#include "../TADs/ListaObstaculos.hpp"
#include "../Entidades/Jogador.hpp"
#include "../Entidades/Mapa.hpp"

namespace Game { namespace Gerenciadores {

using Entidades::Entidade;
using Entidades::Mapas::Mapa;
using Entidades::Personagens::Personagem;
using Entidades::Personagens::Jogador;
using Entidades::Obstaculos::Obstaculo;
using TADs::ListaPersonagens;
using TADs::ListaObstaculos;
using TADs::ListaEntidades;

class GerenciadorColisoes {
private:
    // Attributes
    ListaPersonagens    l_personagens;
    ListaObstaculos     l_obstaculos;
    Mapa&               mapa;
    
public:
    // Constructor & Destructor
    GerenciadorColisoes(Mapa& mapa);
    ~GerenciadorColisoes();
    
    // Methods
    void gerenciarColisoes();
    void gerenciarColisoesPM(); // Colisoes Personagem - Mapa
    void gerenciarColisoesPP(); // Colisoes Personagem - Personagem
    void gerenciarColisoesPO(); // Colisoes Personagem - Obstaculo
    
    void checkCollision(Personagem* personagem);
    void checkCollision(Personagem* personagem_a, Personagem* personagem_b);
    void checkCollision(Personagem* personagem, Obstaculo* obstaculo);
    
    void add(Personagem* personagem);
    void add(Obstaculo* obstaculo);
    
    void clearEndingObj();
    void clear();
    
    // Operadores
    void operator+=(Personagem* personagem);
    void operator+=(Obstaculo* obstaculo);
};

}}
#endif /* GerenciadorColisoes_hpp */
