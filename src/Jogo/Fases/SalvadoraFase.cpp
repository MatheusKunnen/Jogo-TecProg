//
//  SalvadoraFase.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/22/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "SalvadoraFase.hpp"

namespace Game { namespace Fases {
// Const
const string SalvadoraFase::FILE_FLORESTA("Resources/config/save_floresta.json");
const string SalvadoraFase::FILE_MONTANHA("Resources/config/save_montanha.json");

// Constructor & Destructor
SalvadoraFase::SalvadoraFase(ListaEntidades& l_entidades, const int& id):
g_arquivos(id == 1 ? SalvadoraFase::FILE_FLORESTA : SalvadoraFase::FILE_MONTANHA),
l_entidades(l_entidades),
vida_jogador_a(1),
vida_jogador_b(1)
{
    
}

SalvadoraFase::~SalvadoraFase(){
    this->clear();
}

// Methods
const bool SalvadoraFase::load() {
    bool status = true;
    try {
        // Carrega o aquivo
        if (!this->g_arquivos.load())
            throw runtime_error("Error loading file.");
        
        // Obtem dados do arquivo
        this->setSavedFase(this->g_arquivos.getData()["saved_fase"] == 1);
        if (this->isSavedFase()){
            this->setVidaJogador(1, this->g_arquivos.getData()["vida_a"]);
            this->setVidaJogador(2, this->g_arquivos.getData()["vida_b"]);
        }
        
    } catch(std::exception e){
        status = false;
        cerr << "ERROR: SalvadoraFase::load(): " << e.what() << endl;
    }
    return status;
}

const bool SalvadoraFase::save() {
    bool status = true;
    // Cria json com valores da classe
    json data;
    data["saved_fase"] = this->isSavedFase() ? 1 : 0;
    
    if (this->isSavedFase()){
        // Cria json
        stringstream s_json;
        s_json << "{" << "\"saved_fase\":" << (this->isSavedFase() ? "1" : "0") << ","
        << "\"vida_a\":" << this->getVidaJogador(1) << ","
        << "\"vida_b\":" << this->getVidaJogador(2) << ","
        << l_entidades.toJson() << "}" << endl;
        data.clear();
        // Verifica validade do json e carrega o objeto
        if (DEBUG_MODE)
            cout << s_json.str() << endl;
        data = json::parse(s_json.str());

        // Limpa string stream
        s_json.clear();
    }
    // Passa json para o gerenciador de arquivos
    g_arquivos.setData(data);
    
    // Manda ao gerenciador de arquivos guardar o json
    g_arquivos.save();
    data.clear();
    return status;
}

void SalvadoraFase::clear() {
    this->g_arquivos.clear();
}

vector<Vector2f> SalvadoraFase::getPositions(const int id) {
    vector<Vector2f> l_pos;
    json e_id = this->g_arquivos.getData()["e_id"],
         e_x  = this->g_arquivos.getData()["e_x"],
         e_y  = this->g_arquivos.getData()["e_y"];
    int i;
    // Itera lista e agrega posicoes com id compativel
    for (i = 0 ; i < e_id.size(); i++){
        if (e_id[i] == id)
            l_pos.push_back(Vector2f(e_x[i], e_y[i]));
    }
    // Limpa listas auxiliares
    e_id.clear();
    e_x.clear();
    e_y.clear();
    return l_pos;
}


// Getters & Setters
void SalvadoraFase::setSavedFase(const bool &saved_fase) {
    this->saved_fase = saved_fase;
}

const bool& SalvadoraFase::isSavedFase() const {
    return this->saved_fase;
}

void SalvadoraFase::setVidaJogador(const int &n, const float& vida) {
    if (n == 1)
        this->vida_jogador_a = vida;
    else
        this->vida_jogador_b = vida;
}

const float& SalvadoraFase::getVidaJogador(const int& n) {
    return n == 1 ? this->vida_jogador_a : this->vida_jogador_b;
}
}}
