//
//  NarcotraficanteDesmatador.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/19/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef NarcotraficanteDesmatador_hpp
#define NarcotraficanteDesmatador_hpp

#include "Atirador.hpp"

namespace Game { namespace Entidades { namespace Personagens {

class NarcotraficanteDesmatador : public Atirador {
private:
    // Const
    static const float DAMAGE;
    static const float DELAY_TIME;
    static const float ATTACK_DISTANCE;
    static const float VEL_PROJETIL;
    
    
public:
    // Constructor & Destructor
    NarcotraficanteDesmatador(const Vector2f& position, Texture* texture, Jogador* jogador_a, Jogador* jogador_b, Fase* fase);
    ~NarcotraficanteDesmatador();
    
    // Methods
    void updatePlayerAttack();
    void autoMove(const float& dt);
    void atirar(const short& direction);
};

}}}

#endif /* NarcotraficanteDesmatador_hpp */
