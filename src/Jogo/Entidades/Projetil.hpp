//
//  Projetil.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/18/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Projetil_hpp
#define Projetil_hpp

#include "Obstaculo.hpp"

namespace Game { namespace Entidades { namespace Obstaculos {

class Projetil : public Obstaculo {
private:
    // Attributes
    const short        direction;
    const float        speed;
    float              life_time;
    
public:
    // Constructor & Destructor
    Projetil(const Vector2f& position, Texture* texture, const int damage, const short& direction, const float& speed);
    ~Projetil();
    
    // Methods
    void update(const float& dt);
    void updateLifeTime(const float& dt);
    void move(const float& dt);
    void onCollision(Personagem* personagem);
};

}}}

#endif /* Projetil_hpp */
