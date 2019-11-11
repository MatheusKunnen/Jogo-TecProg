//
//  ParametrosFase.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "ParametrosFase.hpp"

namespace Game { namespace Parametros {

ParametrosFase::ParametrosFase(const string& filename):
Parametro(filename),
arquivo_mapa(),
arquivo_tileset(),
arquivo_bg()
{
    
}

ParametrosFase::~ParametrosFase() {
    
}

bool ParametrosFase::loadFromFile(const string &filename){
    bool status = true;
    try {
        if (this->filename != this->g_arquivos.getFilename())
            this->g_arquivos.setFilename(filename);
        // Check file load
        if (!this->g_arquivos.load())
            throw runtime_error("Error loading file.");
        // Gets file data
        this->setArquivoMapa(this->g_arquivos.getData()["arquivo_mapa"]);
        this->setArquivoTileSet(this->g_arquivos.getData()["arquivo_tileset"]);
        this->setArquivoBackground(this->g_arquivos.getData()["arquivo_bg"]);
    } catch(std::exception e){
        status = false;
        cerr << "ERROR: ParametrosFase::loadFromFile(): " << e.what() << endl;
    }
    return status;
}

bool ParametrosFase::saveToFile(const string &filename) {
    if (this->filename != this->g_arquivos.getFilename())
        this->g_arquivos.setFilename(filename);
    // Cria json com valores da classe
    json data;
    data["arquivo_mapa"] = this->getArquivoMapa();
    data["arquivo_tileset"] = this->getArquivoTileSet();
    data["arquivo_bg"] = this->getArquivoBackground();
    // Passa json para o gerenciador de arquivos
    g_arquivos.setData(data);
    // Manda ao gerenciador de arquivos guardar o json
    g_arquivos.save();
    data.clear();
    return true;
}

// Getters & Setters
void ParametrosFase::setArquivoMapa(const string &arquivo_mapa){
    this->arquivo_mapa = arquivo_mapa;
}

const string& ParametrosFase::getArquivoMapa() const {
    return this->arquivo_mapa;
}

void ParametrosFase::setArquivoTileSet(const string &arquivo_tileset){
    this->arquivo_tileset = arquivo_tileset;
}

const string& ParametrosFase::getArquivoTileSet() const {
    return this->arquivo_tileset;
}

void ParametrosFase::setArquivoBackground(const string &arquivo_bg){
    this->arquivo_bg = arquivo_bg;
}

const string& ParametrosFase::getArquivoBackground() const {
    return this->arquivo_bg;
}
}}
