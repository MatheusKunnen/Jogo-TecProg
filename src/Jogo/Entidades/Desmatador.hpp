//
//  Desmatador.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/18/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Desmatador_hpp
#define Desmatador_hpp

#include "Inimigo.hpp"

namespace Game { namespace Entidades { namespace Personagens{

class Desmatador : public Inimigo {
private:
    // Const
    static const float  DAMAGE;
    static const float  DELAY_TIME;
    
public:
    // Constructor & Destructor
    Desmatador(const Vector2f& position, Texture* texture, Jogador* jogador_a, Jogador* jogador_b = nullptr);
    ~Desmatador();
    
    // Methods
    void attack(Jogador* jogador);
    void autoMove(const float& dt);

};

}}}

#endif /* Desmatador_hpp */
