//
//  ListaRanking.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/17/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "ListaRanking.hpp"
namespace Game { namespace TADs {

/*
    Implementação de "Ranking Comparator"
*/
bool ListaRanking::RankingComparator::operator()(const ListaRanking::RankingElement& a, const ListaRanking::RankingElement& b) const {
    return a.getScore() > b.getScore();
}

/*
    Implementação métodos de "RankingElement"
 */
// Constructor & Destructor
ListaRanking::RankingElement::RankingElement(const string& nome_jogador, const int& score):
nome_jogador(nome_jogador),
score(score)
{
    
}

ListaRanking::RankingElement::~RankingElement() {
    
}

// Getters & Setters
void ListaRanking::RankingElement::setNomeJogador(const string &nome_jogador) {
    this->nome_jogador = nome_jogador;
}

const string& ListaRanking::RankingElement::getNomeJogador() const {
    return this->nome_jogador;
}

void ListaRanking::RankingElement::setScore(const int &score) {
    this->score = score;
}

const int& ListaRanking::RankingElement::getScore() const {
    return this->score;
}

/*
    Implementação métodos de ListaRanking
*/

// Constructor & Destructor
ListaRanking::ListaRanking(const string& filename):
g_arquivos(filename)
{
    this->load();
}

ListaRanking::~ListaRanking(){
    this->clear();
}

// Methods
void ListaRanking::add(const string &nome_jogador, const int &score){
    this->add(ListaRanking::RankingElement(nome_jogador, score));
}

void ListaRanking::add(const ListaRanking::RankingElement& element){

    this->l_ranking.insert(element);
    // Salva sempre que se agrega um novo jogador
    this->save();
}

const ListaRanking::RankingElement& ListaRanking::get(const int &i) const {
    // Verifica validade de indice
    if (i >= this->getSize())
        throw runtime_error("ERROR: ListaRanking::get(): Index out of bounds.\n");
    
    set<RankingElement, RankingComparator>::iterator itr = this->l_ranking.begin();
    int j;
    // Busca Elemento
    for(j = 0; j < i; j++, itr++);
    
    return *itr;
}

void ListaRanking::clear() {
    // Desaloca elementos
    //for (ListaRanking::RankingElement elemento : this->l_ranking)
    //    delete elemento;
    // Limpa lista
    this->l_ranking.clear();
}

void ListaRanking::load() {
    try {
        // Check file load
        if (!this->g_arquivos.load())
            throw runtime_error("Error loading file.");
        
        // Gets file data
        json a_nomes = this->g_arquivos.getData()["nomes"];
        json a_scores = this->g_arquivos.getData()["scores"];
        
        // Loads Array
        json::iterator  itr_n = a_nomes.begin(),
                        itr_s = a_scores.begin();
        while (itr_n != a_nomes.end()){
            this->add(itr_n.value(), itr_s.value());
            itr_n++;
            itr_s++;
        }
        
        // Clears Arrays
        a_nomes.clear();
        a_scores.clear();
    } catch(std::exception e){
        cerr << "ERROR: ListaRanking::load(): " << e.what() << endl;
    }
}

void ListaRanking::save() {
    // Cria json com valores da classe
    json data;
    
    // Gets file data
    json a_nomes = json::array();
    json a_scores = json::array();
    
    // Loads Arrays
    for (RankingElement element: this->l_ranking){
        a_nomes.push_back(element.getNomeJogador());
        a_scores.push_back(element.getScore());
    }
    // Add arrays to json obj
    data["nomes"] = a_nomes;
    data["scores"] = a_scores;
    
    // Sends data to g_arquivos
    g_arquivos.setData(data);
    
    // Manda ao gerenciador de arquivos guardar o json
    g_arquivos.save();
    
    // Limpa listas 
    data.clear();
    a_nomes.clear();
    a_scores.clear();
}

const string ListaRanking::dump() const {
    stringstream txt_board;
    int count = 0;
    for(const RankingElement& element: this->l_ranking){
        txt_board << ++count << "˚ - " << element.getNomeJogador() << " - " << element.getScore() << endl;
    }
    return txt_board.str();
}

// Getters & Setters
const long ListaRanking::getSize() const {
    return this->l_ranking.size();
}

void ListaRanking::setFilename(const string &filename) {
    this->g_arquivos.setFilename(filename);
}

const string& ListaRanking::getFilename() const {
    return this->g_arquivos.getFilename();
}

// Operators
const ListaRanking::RankingElement& ListaRanking::operator[](const int &i) const {
    return this->get(i);
}

}}
