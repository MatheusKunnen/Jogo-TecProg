//
//  ListaObstaculos.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/17/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef ListaObstaculos_hpp
#define ListaObstaculos_hpp

#include "../Entidades/Obstaculo.hpp"

namespace Game { namespace TADs {

using Entidades::Obstaculos::Obstaculo;

class ListaObstaculos {
private:
    // Attributes
    list<Obstaculo*>            l_obstaculos;
    list<Obstaculo*>::iterator  itr;
    
public:
    // Constructor & Destructor
    ListaObstaculos();
    ~ListaObstaculos();
    
    // Methods
    void add(Obstaculo* obstaculo);
    Obstaculo* get(const int& i);
    void clearEnding();
    void clear();
    
    // Getters & Setters
    const long getCount() const;
    
    // Operators
    void operator+=(Obstaculo* obstaculo);
    Obstaculo* operator[](const int& i);
    
};

}}
#endif /* ListaObstaculos_hpp */
