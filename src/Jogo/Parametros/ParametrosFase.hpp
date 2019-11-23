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
    string            arquivo_mapa; // Dir arquivo com dados do mapa
    string            arquivo_tileset; // Dir arquivo de tiles do mapa
    string            arquivo_bg; // Dir arquivo do background da fase
    Vector2f          pos_player_a; // Posição inicial do jogador A
    Vector2f          pos_player_b; // Posição inicial do jogador B
    Vector2f          pos_boss; // Posicao do chefão 
    float             pos_x_win; // Posição de ponto para ganhar
    vector<Vector2f>  l_pos_inimigos; // Posições possíveis para os inimigos
    vector<Vector2f>  l_pos_obstaculos; // Posições possíveis para os obstaculos

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
    void setPosBoss(const Vector2f& pos_boss);
    const Vector2f& getPosBoss() const;
    void setPosXWin(const float& pos_player_b);
    const float& getPosXWin() const;
    void setListaPosInimigos(const vector<Vector2f>& l_pos_inimigos);
    const vector<Vector2f>& getListaPosInimigos() const;
    void setListaPosObstaculos(const vector<Vector2f>& l_pos_obstaculos);
    const vector<Vector2f>& getListaPosObstaculos() const;
};
}}

#endif /* ParametrosFase_hpp */
