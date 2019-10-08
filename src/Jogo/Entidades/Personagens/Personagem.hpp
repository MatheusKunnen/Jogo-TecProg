//
//  Personagem.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Personagem_hpp
#define Personagem_hpp

#include "base_includes.hpp"
#include "Entidade.hpp"

namespace Game { namespace Personagens{

class Personagem : public Entidades::Entidade {
private:
    // Attributes
    int num_vidas;
    float velocidade;
    int power;
public:
    // Constructor & Destructor
    Personagem();
    virtual ~Personagem();
    // Getters & Setters
    void setNumVidas(int num_vidas);
    int getNumVidas();
    // Methods
    virtual void update(float dt) = 0;
    virtual void draw(RenderTarget* target = nullptr) = 0;
};

}}
#endif /* Personagem_hpp */
