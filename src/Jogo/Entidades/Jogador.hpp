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
    // Attributes
    float total_dt;
    
    // Init methods
    void initComponents();
    void initMoveComponent();
public:
    // Constructor & Destructor
    Jogador(const Vector2f& position, Texture* texture);
    ~Jogador();
    
    // Methods
    void update(const float& dt);
    void reset();
    // Getters & Setters
    const int getScore() const;
};

}}};

#endif /* Jogador_hpp */
