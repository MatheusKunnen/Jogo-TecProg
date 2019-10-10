//
//  Jogador.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Jogador_hpp
#define Jogador_hpp
#include "base_includes.hpp"
#include "Entidade.hpp"

namespace Game { namespace Entidades {

class Jogador : public Entidade{
private:
    // Attributes
    
    // Init methods
    void initComponents();
public:
    // Constructor & Destructor
    Jogador(const Vector2f& position, Texture* texture);
    ~Jogador();
    // Methods
    
};

}};

#endif /* Jogador_hpp */
