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
    int                 num_vidas;
    
    // Components
    MoveComponent       move_comp;
    
    // Init methods
    virtual void initComponents() = 0;
    virtual void initMoveComponent();
public:
    // Constructor & Destructor
    Personagem(const Vector2f& position, Texture* texture);
    virtual ~Personagem();

    // Methods
    virtual void update(const float& dt);
    virtual void move(const Vector2f& direction, const float& dt);
    virtual void updateMoveComponent(const float& dt);
    virtual void jump(const float& gain = 1.f);
    virtual void onXCollision(const bool& on_collision);
    virtual void onYCollision(const bool& on_collision);
    virtual void removeVida(const int& n_vidas);
    
    // Getters & Setters
    MoveComponent& getMoveComponent();
    void setNumVidas(const int& num_vidas);
    const int& getNumVidas() const;
    
};

}}}
#endif /* Personagem_hpp */
