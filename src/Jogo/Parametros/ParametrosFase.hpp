//
//  ParametrosFase.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef ParametrosFase_hpp
#define ParametrosFase_hpp

#include "Parametros.hpp"

namespace Game { namespace Parametros{

class ParametrosFase : public Parametro {
private:
    string      arquivo_mapa;
    string      arquivo_tileset;
    string      arquivo_bg;
    Vector2f    pos_player_a;
    Vector2f    pos_player_b;
    float       pos_x_win;
    
public:
    // Constructor & Destructor
    ParametrosFase(const string& filename);
    ~ParametrosFase();
    // Methods
    bool loadFromFile(const string& filename = "");
    bool saveToFile(const string& filename = "");
    // Getters & Setters
    void setArquivoMapa(const string& arquivo_mapa);
    const string& getArquivoMapa() const;
    void setArquivoTileSet(const string& arquivo_tileset);
    const string& getArquivoTileSet() const;
    void setArquivoBackground(const string& arquivo_bg);
    const string& getArquivoBackground() const;
    void setPosPlayerA(const Vector2f& pos_player_a);
    const Vector2f& getPosPlayerA() const;
    void setPosPlayerB(const Vector2f& pos_player_b);
    const Vector2f& getPosPlayerB() const;
    void setPosXWin(const float& pos_player_b);
    const float& getPosXWin() const;
};
}}

#endif /* ParametrosFase_hpp */
