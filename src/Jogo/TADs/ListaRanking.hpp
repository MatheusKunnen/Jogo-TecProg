//
//  ListaRanking.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/17/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef ListaRanking_hpp
#define ListaRanking_hpp

#include "../Gerenciadores/GerenciadorArquivos.hpp"

namespace Game { namespace TADs {

using Gerenciadores::GerenciadorArquivos;
using nlohmann::json;

class ListaRanking{
private:
    // Classe para elemento do Ranking
    class RankingElement{
    private:
        // Attributes
        string      nome_jogador;
        int         score;
        
    public:
        // Constructor & Destructor
        RankingElement(const string& nome_jogador, const int& score);
        ~RankingElement();
        
        // Getters & Setters
        void setNomeJogador(const string& nome_jogador);
        const string& getNomeJogador() const;
        void setScore(const int& score);
        const int& getScore() const;
    };
    
    // Comparador para o set da lista Ranking
    struct RankingComparator {
        bool operator()(const RankingElement* a, const RankingElement* b) const;
    };
    
    // Attributes
    set<RankingElement*, RankingComparator>      l_ranking;
    GerenciadorArquivos                          g_arquivos;
    
public:
    // Constructor & Destructor
    ListaRanking(const string& filename = "Resources/config/ranking.json");
    ~ListaRanking();
    
    // Methods
    void add(const string& nome_jogador, const int& score);
    void add(RankingElement* element);
    RankingElement* get(const int& i) const;
    void clear();
    void load();
    void save();
    const string dump() const;
    
    // Getters & Setters
    const long getSize() const;
    void setFilename(const string& filename);
    const string& getFilename() const;
    
    // Operators
    RankingElement* operator[](const int& i) const ;
};

}}

#endif /* ListaRanking_hpp */
