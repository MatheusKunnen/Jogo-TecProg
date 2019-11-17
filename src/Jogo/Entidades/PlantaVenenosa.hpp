//
//  PlantaVenenosa.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/17/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef PlantaVenenosa_hpp
#define PlantaVenenosa_hpp

#include "Obstaculo.hpp"

namespace Game { namespace Entidades { namespace Obstaculos {

using Entidades::Obstaculos::Obstaculo;

class PlantaVenenosa : public Obstaculo {
private:
public:
    // Constructor & Destructor
    PlantaVenenosa(const Vector2f& position, Texture* texture);
    ~PlantaVenenosa();
    
    // Methods
    void onCollision(Personagem* personagem);
    
};

}}}

#endif /* PlantaVenenosa_hpp */
