//
//  Personagem.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Personagem_hpp
#define Personagem_hpp

#include "../base_includes.hpp"
#include "Entidade.hpp"

namespace Game { namespace Entidades { namespace Personagens {

class Personagem : public Entidade {
protected:
    // Attributes
    float                 num_vidas;
    
    // Components
    MoveComponent       move_comp;

public:
    // Constructor & Destructor
    Personagem(ID id, const Vector2f& position, Texture* texture, const float& num_vidas = 10);
    virtual ~Personagem();

    // Methods
    virtual void update(const float& dt);
    void move(const Vector2f& direction, const float& dt);
    void updateMoveComponent(const float& dt);
    void jump(const float& gain = 1.f);
    void onXCollision(const bool& on_collision);
    void onYCollision(const bool& on_collision);
    void removeVida(const int& n_vidas);
    
    // Getters & Setters
    MoveComponent& getMoveComponent();
    void setNumVidas(const float& num_vidas);
    const float& getNumVidas() const;
    
};

}}}
#endif /* Personagem_hpp */
