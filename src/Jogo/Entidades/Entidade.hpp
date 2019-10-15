//
//  Entidade.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Entidade_hpp
#define Entidade_hpp

#include "../base_includes.hpp"
#include "Componentes/MoveComponent.hpp"

namespace Game{ namespace Entidades {

class Entidade {
protected:
    // Attributes
    Texture*            texture;
    Sprite*             sprite;
    float gravity ; //DEBUG
    // Components
    unique_ptr<MoveComponent>       move_comp;
public:
    // Constructor & Destructor
    explicit Entidade(Texture* texture = nullptr);
    virtual ~Entidade();
    // Getters & Setters
    virtual void setPosition(const Vector2f& position);
    // Component Methods
    void setTexture(Texture* texture);
    void createMoveComponent(const float& max_vel, const float& acceleration, const float& deceleration);
    
    // Methods
    virtual void move(const sf::Vector2f& direction, const float& dt);
    virtual void update(const float& dt);
    virtual void render(RenderTarget* target);
};

}};

#endif /* Entidade_hpp */
