//
//  Jogador.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Jogador_hpp
#define Jogador_hpp
#include "../base_includes.hpp"
#include "../Entidades/Personagem.hpp"

namespace Game { namespace Entidades { namespace Personagens {

class Jogador : public Personagem{
private:
    // Const
    static const Vector2f   lifebar_size;
    static const sf::Color  lifebar_color;
    static const int       max_life;
    
    // Attributes
    float total_dt;
    RectangleShape life_bar;
    
    // Init methods
    void initLifeBar();
public:
    // Constructor & Destructor
    Jogador(const Vector2f& position, Texture* texture);
    ~Jogador();
    
    // Methods
    void update(const float& dt);
    void updateLifeBar();
    void render(RenderTarget* target);
    void renderLifeBar(RenderTarget* target);
    void reset();
    
    // Getters & Setters
    const int getScore() const;
};

}}};

#endif /* Jogador_hpp */
