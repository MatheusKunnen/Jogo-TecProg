//
//  Pedra.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/19/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Pedra_hpp
#define Pedra_hpp

#include "Obstaculo.hpp"

namespace Game { namespace Entidades { namespace Obstaculos {

using Entidades::Obstaculos::Obstaculo;

class Pedra : public Obstaculo {
public:
    // Constructor & Destructor
    Pedra(const Vector2f& position, Texture* texture);
    ~Pedra();
    
    // Methods
    void onCollision(Personagem* personagem);
    
};

}}}

#endif /* Pedra_hpp */
