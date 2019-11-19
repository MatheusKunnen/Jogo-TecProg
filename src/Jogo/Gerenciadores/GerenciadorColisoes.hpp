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
#include "../Entidades/level.hpp"

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
    ListaEntidades&     l_entidades;
    Mapa&               mapa;
    
    const Vector2f distance(const FloatRect& a, const FloatRect& b);
public:
    // Constructor & Destructor
    GerenciadorColisoes(Mapa& mapa, ListaEntidades& l_entidades);
    ~GerenciadorColisoes();
    
    // Methods
    void gerenciarColisoes();
    void gerenciarColisoesPersonagensMapa();
    void gerenciarColisoesPersonagensPersonagens();
    void gerenciarColisoesPersonagensObstaculos();
    void gerenciarColisoesPersonagensProjeteis();
    void checkMapCollision(Personagem* personagem);
    void checkPPCollision(Personagem* personagem_a, Personagem* personagem_b);
    void checkPOCollision(Personagem* personagem, Obstaculo* obstaculo);
    //void checkPpCollision(Personagem* personagem, )
    void addPersonagem(Personagem* personagem);
    void addObstaculo(Obstaculo* obstaculo);
    void clear();
    // Operadores
    void operator+=(Personagem* personagem);
    void operator+=(Obstaculo* obstaculo);
};

}}
#endif /* GerenciadorColisoes_hpp */
