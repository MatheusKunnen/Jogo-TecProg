//
//  Inimigo.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Inimigo_hpp
#define Inimigo_hpp

#include "Jogador.hpp"

namespace Game { namespace Entidades { namespace Personagens {

class Inimigo : public Personagem {
protected:
    // Attributes
    float       damage;
    float       amplitude_mov;
    float       vel_mov;
    float       time_mov;
    float       idle_time;
    float       attack_delay;
    
    Jogador*    jogador_a;
    Jogador*    jogador_b;
    
public:
    // Constructor & Destructor
    Inimigo(const Vector2f& position, Texture* texture, Jogador* jogador_a, Jogador* jogador_b = nullptr, const int& damage = 1);
    ~Inimigo();
        
    // Methods
    void update(const float& dt);
    virtual void updatePlayerAttack();
    virtual void attack(Jogador* jogador) = 0;
    virtual void autoMove(const float& dt) = 0;
    
    // Getters & Setters
    void setDamage(const float& damage);
    const float& getDamage() const;
    void setAmplitudeMov(const float& amplitude_mov);
    const float& getAmplitudeMov() const;
    void setVelMov(const float& vel_mov);
    const float& getVelMov() const;
    void setAttackDelay(const float& vel_mov);
    const float& getAttackDelay() const;
    
};

}}}

#endif /* Inimigo_hpp */
