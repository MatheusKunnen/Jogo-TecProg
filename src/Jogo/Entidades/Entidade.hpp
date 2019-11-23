//
//  Entidade.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Entidade_hpp
#define Entidade_hpp

#include "../Gerenciadores/GerenciadorGrafico.hpp"
#include "Componentes/MoveComponent.hpp"

namespace Game{ namespace Entidades {

using Gerenciadores::GerenciadorGrafico;

enum ID {mapa, jogador, desmatador, narcotraficante, boss, planta_venenosa, pedra, espinhos, projetil};

class Entidade {
protected:
    // Attributes
    const ID        id;
    Texture*        texture;
    Sprite          sprite;
    bool            ending;

public:
    // Constructor & Destructor
    explicit Entidade(ID id, Texture* texture = nullptr);
    virtual ~Entidade();
    
    // Getters & Setters
    virtual void setPosition(const Vector2f& position);
    const FloatRect getGlobalBounds() const;
    virtual const Vector2f& getPosition() const;
    void setTexture(Texture* texture);
    void setEnding(const bool& ending);
    const bool& isEnding() const;
    const ID& getId() const;
    
    // Methods
    virtual void update(const float& dt) = 0;
    virtual void render(RenderTarget* target);
    
    // Static method
    static const Vector2f distanceV(Entidade* a, Entidade* b);
    static const Vector2f maxDistanceV(Entidade* a, Entidade* b);
    static const float distance(Entidade* a, Entidade* b);
    static const float maxDistance(Entidade* a, Entidade* b);
};

}};

#endif /* Entidade_hpp */
