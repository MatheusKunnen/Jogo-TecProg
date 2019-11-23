//
//  SalvadoraFase.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/22/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef SalvadoraFase_hpp
#define SalvadoraFase_hpp

#include "../Gerenciadores/GerenciadorArquivos.hpp"
#include "../TADs/ListaEntidades.hpp"

namespace Game { namespace Fases {

class Fase;

using Gerenciadores::GerenciadorArquivos;
using Gerenciadores::json;
using TADs::ListaEntidades;

class SalvadoraFase {
private:
    // Const
    static const string FILE_FLORESTA;
    static const string FILE_MONTANHA;
    
    // Attributes
    GerenciadorArquivos g_arquivos;
    ListaEntidades&     l_entidades;
    bool                saved_fase;
    float               vida_jogador_a;
    float               vida_jogador_b;
    
public:
    // Constructor & Destructor
    SalvadoraFase(ListaEntidades& l_entidades, const int& id);
    ~SalvadoraFase();
    
    // Methods
    const bool load();
    const bool save();
    void clear();
    vector<Vector2f> getPositions(const int id);
    
    // Getters & Setters
    void setSavedFase(const bool& saved_fase);
    const bool& isSavedFase() const;
    void setVidaJogador(const int& n, const float& vida);
    const float& getVidaJogador(const int& n);
    
    
};
}}

#endif /* SalvadoraFase_hpp */
