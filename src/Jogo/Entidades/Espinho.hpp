//
//  Espinho.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/19/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Espinho_hpp
#define Espinho_hpp

#include "Obstaculo.hpp"

namespace Game { namespace Entidades { namespace Obstaculos {

using Entidades::Obstaculos::Obstaculo;

class Espinho : public Obstaculo {
public:
    // Constructor & Destructor
    Espinho(const Vector2f& position, Texture* texture);
    ~Espinho();
    
    // Methods
    void onCollision(Personagem* personagem);
    
};

}}}

#endif /* Espinho_hpp */
