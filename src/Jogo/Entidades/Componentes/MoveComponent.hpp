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
    float       max_speed;
    float       v_aceleration;
    float       v_deceleration;
    float&      gravity;
    Vector2f    v_direction;
    Sprite*     sprite;
    
    // Init methods
    
    // Const
    static const float      ACELERATION_GAIN;
    static const float      DEFAULT_MAX_SPEED;
    static const float   DEFAULT_ACELERATION;
    static const float   DEFAULT_DECELERATION;
public:
    // Constructor & Destructor
    explicit MoveComponent(Sprite* sprite,
                            float& gravity,
                           const float& max_speed = MoveComponent::DEFAULT_MAX_SPEED,
                           const float& aceleration = MoveComponent::DEFAULT_ACELERATION,
                           const float& deceleration = MoveComponent::DEFAULT_DECELERATION);
    ~MoveComponent();
    
    // Methods
    void update(const float& dt);
    void move(const Vector2f& direction, const float& dt);
    void jump(const float& gain);
    // Getters & Setters
    float getMaxSpeed() const;
    void setMaxSpeed(float maxSpeed);
    const Vector2f &getVSpeed() const;
    void setVSpeed(const Vector2f &vSpeed);
    const float &getAceleration() const;
    void setAceleration(const float &vAceleration);
    const float &getDeceleration() const;
    void setDeceleration(const float &vDeceleration);
    void setGravity(const float& gravity);
};

}};

#endif /* MoveComponent_hpp */
