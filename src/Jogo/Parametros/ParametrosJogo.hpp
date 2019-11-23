//
//  ParametrosJogo.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef ParametrosJogo_hpp
#define ParametrosJogo_hpp

#include "Parametros.hpp"

namespace Game { namespace Parametros{

class ParametrosJogo : public Parametro {
private:
    // Attributes
    bool        is_dual_player;
    string      player_name;
    
public:
    // Constructor & Destructor
    ParametrosJogo(const string& filename = "Resources/config/jogo_config.json");
    ~ParametrosJogo();
    
    // Methods
    bool loadFromFile(const string& filename = "");
    bool saveToFile(const string& filename = "");
    
    // Getters & Setters
    void setDualPlayer(const bool& is_dual_player);
    const bool& isDualPlayer() const;
    void setPlayerName(const string& player_name);
    const string& getPlayerName() const;
};
}}

#endif /* ParametrosJogo_hpp */
