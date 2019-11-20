//
//  Atirador.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/18/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Atirador_hpp
#define Atirador_hpp

#include "Inimigo.hpp"


namespace Game {

namespace Fases {
class Fase;
}

namespace Entidades { namespace Personagens {

using Fases::Fase;

class Atirador : public Inimigo {
protected:
    // Attributes
    Fase*           fase;
    const float     projetil_speed;
    
public:
    Atirador(const Vector2f& position, Texture* texture, Jogador* jogador_a, Jogador* jogador_b, Fase* fase, const float& projetil_speed, const float& damage = 1);
    virtual ~Atirador();
    
    // Methods
    virtual void updatePlayerAttack();
    virtual void attack(Jogador* jogador);
    virtual void atirar(const short& direction) = 0;
    
};

}}}

#endif /* Atirador_hpp */
