//
//  Entidade.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Entidade_hpp
#define Entidade_hpp

#include "base_includes.hpp"
#include <SFML/Graphics.hpp>


// SFML usings
using sf::RenderWindow;
using sf::RenderTarget;
using sf::Texture;
using sf::Sprite;
using sf::Vector2i;
using sf::Vector2f;

namespace Game{ namespace Entidades {

class Entidade {
protected:
    // Attributes
    Texture*             texture;
    sf::Sprite*          sprite;
    
    float speed;
public:
    // Constructor & Destructor
    explicit Entidade(Texture* texture = nullptr);
    virtual ~Entidade();
    // Getters & Setters
    virtual void setPosition(const Vector2f& position);
    // Component Methods
    void create_sprite(Texture* texture);
    
    // Methods
    virtual void move(const sf::Vector2f& direction, const float& dt);
    virtual void update(const float& dt);
    virtual void render(RenderTarget* target);
};

}};

#endif /* Entidade_hpp */
