//
//  Entidade.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Entidade_hpp
#define Entidade_hpp

#include "../GerenciadorGrafico.hpp"
#include "Componentes/MoveComponent.hpp"

namespace Game{ namespace Entidades {

class Entidade {
protected:
    // Attributes
    Texture*                        texture;
    Sprite                          sprite;
    float                           gravity;
    GerenciadorGrafico*             g_grafico;
    bool                            ending;

public:
    // Constructor & Destructor
    explicit Entidade(Texture* texture = nullptr, GerenciadorGrafico* g_grafico = nullptr);
    virtual ~Entidade();
    
    // Getters & Setters
    void setGGrafico(GerenciadorGrafico* g_grafico);
    virtual void setPosition(const Vector2f& position);
    virtual const FloatRect getGlobalBounds() const;
    virtual const Vector2f& getPosition() const;
    void setEnding(const bool& ending);
    const bool& isEnding() const;
    
    // Component Methods
    virtual void setTexture(Texture* texture);
    
    // Methods
    virtual void update(const float& dt);
    virtual void render(RenderTarget* target);
    
    // Static method
    static const Vector2f distanceV(Entidade* a, Entidade* b);
    static const Vector2f maxDistanceV(Entidade* a, Entidade* b);
    static const float distance(Entidade* a, Entidade* b);
    static const float maxDistance(Entidade* a, Entidade* b);
};

}};

#endif /* Entidade_hpp */
