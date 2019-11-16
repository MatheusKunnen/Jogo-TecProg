//
//  ParametrosJogo.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "ParametrosJogo.hpp"

namespace Game { namespace Parametros {

ParametrosJogo::ParametrosJogo(const string& filename):
Parametro(filename),
player_name("Sem Nome"),
is_dual_player(false)
{
    
}
ParametrosJogo::~ParametrosJogo() {
    this->g_arquivos.clear();
}

bool ParametrosJogo::loadFromFile(const string &filename){
    bool status = true;
    try {
        if (this->filename != this->g_arquivos.getFilename())
            this->g_arquivos.setFilename(filename);
        // Check file load
        if (!this->g_arquivos.load())
            throw runtime_error("Error loading file.");
        // Gets file data
        //this->setPlayerName(this->g_arquivos.getData()["player_name"]); // Sem inicia sem nome
        this->setDualPlayer(this->g_arquivos.getData()["is_dual_player"] == 1);
    } catch(std::exception e){
        status = false;
        cerr << "ERROR: ParametrosJogo::loadFromFile(): " << e.what() << endl;
    }
    return status;
}

bool ParametrosJogo::saveToFile(const string &filename) {
    if (this->filename != this->g_arquivos.getFilename())
        this->g_arquivos.setFilename(filename);
    // Cria json com valores da classe
    json data;
    data["player_name"] = this->getPlayerName();
    data["is_dual_player"] = this->is_dual_player ? 1 : 0;
    // Passa json para o gerenciador de arquivos
    g_arquivos.setData(data);
    // Manda ao gerenciador de arquivos guardar o json
    g_arquivos.save();
    data.clear();
    return true;
}

// Getters & Setters
void ParametrosJogo::setDualPlayer(const bool &is_dual_player) {
    this->is_dual_player = is_dual_player;
}

const bool& ParametrosJogo::isDualPlayer() const {
    return this->is_dual_player;
}

void ParametrosJogo::setPlayerName(const string &player_name) {
    this->player_name = player_name;
}

const string& ParametrosJogo::getPlayerName() const {
    return this->player_name;
}

}}
