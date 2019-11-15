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
arquivo_bg(),
pos_player_a(250.f, 250.f),
pos_player_b(250.f, 250.f),
pos_x_win(1000.f)
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
        this->setPosPlayerA(Vector2f(this->g_arquivos.getData()["pos_x_p_a"],
                                     this->g_arquivos.getData()["pos_y_p_a"]));
        this->setPosPlayerB(Vector2f(this->g_arquivos.getData()["pos_x_p_b"],
                                     this->g_arquivos.getData()["pos_y_p_b"]));
        this->setPosXWin(this->g_arquivos.getData()["pos_x_win"]);

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
    data["pos_x_p_a"] = this->pos_player_a.x;
    data["pos_y_p_a"] = this->pos_player_a.y;
    data["pos_x_p_b"] = this->pos_player_b.x;
    data["pos_y_p_b"] = this->pos_player_b.y;
    data["pos_x_win"] = this->getPosXWin();
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

void ParametrosFase::setPosPlayerA(const Vector2f &pos_player_a){
    this->pos_player_a = pos_player_a;
}

const Vector2f& ParametrosFase::getPosPlayerA() const {
    return this->pos_player_a;
}

void ParametrosFase::setPosPlayerB(const Vector2f &pos_player_b){
    this->pos_player_b = pos_player_b;
}

const Vector2f& ParametrosFase::getPosPlayerB() const {
    return this->pos_player_b;
}

void ParametrosFase::setPosXWin(const float &pos_x_win) {
    this->pos_x_win = pos_x_win;
}

const float& ParametrosFase::getPosXWin() const {
    return this->pos_x_win;
}

}}
