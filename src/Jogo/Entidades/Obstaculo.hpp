//
//  Obstaculo.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/6/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Obstaculo_hpp
#define Obstaculo_hpp

#include "../base_includes.hpp"
#include "Personagem.hpp"

namespace Game { namespace Entidades { namespace Obstaculos {

using Entidades::Personagens::Personagem;

enum Type {planta_venenosa, pedra, espinhos, projetil};

class Obstaculo : public Entidade {
protected:
    // Attributes
    const int   type_id;
    int         damage;
    float       idle_time;
    float       delay_time;
    
public:
    // Constructor & Destructor
    Obstaculo(const Type type_id, const Vector2f& position, Texture* texture, const int damage = 1);
    virtual ~Obstaculo();
    
    // Methods
    virtual void update(const float& dt);
    virtual void onCollision(Personagem* personagem) = 0;
    
    // Getters & Setters
    virtual void setDamage(const int& damage);
    virtual const int& getDamage() const;
    void setDelayTime(const float& delay_time);
    const float& getDelayTime() const ;
};

}}}

#endif /* Obstaculo_hpp */
