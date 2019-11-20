//
//  Narcotraficante.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/18/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Narcotraficante_hpp
#define Narcotraficante_hpp

#include "Atirador.hpp"

namespace Game { namespace Entidades { namespace Personagens {

class Narcotraficante : public Atirador {
private:
    // Const
    static const float DAMAGE;
    static const float DELAY_TIME;
    static const float ATTACK_DISTANCE;
    static const float VEL_PROJETIL;
    
public:
    // Constructor & Destructor
    Narcotraficante(const Vector2f& position, Texture* texture, Jogador* jogador_a, Jogador* jogador_b, Fase* fase, const int& damage = 1);
    ~Narcotraficante();
    
    // Methods
    void autoMove(const float& dt);
    void atirar(const short& direction);
};

}}}

#endif /* Narcotraficante_hpp */
