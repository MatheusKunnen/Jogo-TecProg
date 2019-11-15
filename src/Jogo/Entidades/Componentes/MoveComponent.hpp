//
//  MoveComponent.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef MoveComponent_hpp
#define MoveComponent_hpp
#include "../../base_includes.hpp"
namespace Game { namespace Entidades{

class MoveComponent{
private:
    // Attributes
    Vector2f    v_speed;
    Vector2f    max_speed;
    Vector2f    v_aceleration;
    Vector2f    v_deceleration;
    Vector2f    v_direction;
    Sprite*     player_sprite;
    bool        x_collision;
    bool        y_collision;
    
    // Const
    static const float      ACELERATION_GAIN;
    static const Vector2f   DEFAULT_MAX_SPEED;
    static const Vector2f   DEFAULT_ACELERATION;
    static const Vector2f   DEFAULT_DECELERATION;
public:
    // Constructor & Destructor
    explicit MoveComponent(Sprite* sprite,
                           const Vector2f& max_speed = MoveComponent::DEFAULT_MAX_SPEED,
                           const Vector2f& aceleration = MoveComponent::DEFAULT_ACELERATION,
                           const Vector2f& deceleration = MoveComponent::DEFAULT_DECELERATION);
    ~MoveComponent();
    
    // Methods
    void update(const float& dt);
    void move(const Vector2f& direction, const float& dt = 1);
    void jump(const float& gain);
    void reset();
    void onXCollision(const bool& on_collision);
    void onYCollision(const bool& on_collision);
    // Getters & Setters
    const Vector2f getMaxSpeed() const;
    void setMaxSpeed(const Vector2f& maxSpeed);
    const Vector2f &getVSpeed() const;
    void setVSpeed(const Vector2f &vSpeed);
    const Vector2f &getAceleration() const;
    void setAceleration(const Vector2f &vAceleration);
    const Vector2f &getDeceleration() const;
    void setDeceleration(const Vector2f &vDeceleration);
};

}};

#endif /* MoveComponent_hpp */
