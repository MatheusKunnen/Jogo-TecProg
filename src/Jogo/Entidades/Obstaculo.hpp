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

enum Type {planta_venenosa, pedra, espinhos};

class Obstaculo : public Entidade {
protected:
    // Attributes
    const int type_id;
    int     damage;
    
public:
    // Constructor & Destructor
    Obstaculo(const Type type_id, const Vector2f& position, Texture* texture, const int damage = 1);
    virtual ~Obstaculo();
    
    // Methods
    virtual void update(const float& dt);
    virtual void onCollision(Personagem* personagem);
    
    // Getters & Setters
    void setDamage(const int& damage);
    const int& getDamage() const;
};

}}}

#endif /* Obstaculo_hpp */
