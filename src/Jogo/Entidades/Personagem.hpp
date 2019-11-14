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
private:
    // Attributes
    int num_vidas;
    
    // Components
    unique_ptr<MoveComponent>       move_comp;
    
    // Init methods
    virtual void initComponents() = 0;
    virtual void initMoveComponent() = 0;
public:
    // Constructor & Destructor
    Personagem(const Vector2f& position, Texture* texture);
    virtual ~Personagem();
    void createMoveComponent(const float& max_vel, const float& acceleration, const float& deceleration);
    // Methods
    virtual void jump(const float& gain = 1.f);
    virtual void onXCollision();
    virtual void onYCollision();
    
    // Getters & Setters
    unique_ptr<MoveComponent>& getMoveComponent();
    void setNumVidas(int num_vidas);
    int getNumVidas();
    
};

}}}
#endif /* Personagem_hpp */
