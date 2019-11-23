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
pos_boss(0.f, 0.f),
pos_x_win(1000.f),
l_pos_inimigos(),
l_pos_obstaculos()
{
    
}

ParametrosFase::~ParametrosFase() {
    
}

bool ParametrosFase::loadFromFile(const string &filename){
    bool status = true;
    try {
        if (this->filename != this->g_arquivos.getFilename())
            this->g_arquivos.setFilename(filename);
        
        // Carrega o aquivo
        if (!this->g_arquivos.load())
            throw runtime_error("Error loading file.");
        
        // Obtem dados do arquivo
        this->setArquivoMapa(this->g_arquivos.getData()["arquivo_mapa"]);
        this->setArquivoTileSet(this->g_arquivos.getData()["arquivo_tileset"]);
        this->setArquivoBackground(this->g_arquivos.getData()["arquivo_bg"]);
        this->setPosPlayerA(Vector2f(this->g_arquivos.getData()["pos_x_p_a"],
                                     this->g_arquivos.getData()["pos_y_p_a"]));
        this->setPosPlayerB(Vector2f(this->g_arquivos.getData()["pos_x_p_b"],
                                     this->g_arquivos.getData()["pos_y_p_b"]));
        this->setPosBoss(Vector2f(this->g_arquivos.getData()["pos_x_boss"],
                                     this->g_arquivos.getData()["pos_y_boss"]));
        this->setPosXWin(this->g_arquivos.getData()["pos_x_win"]);
        
        // Carrega arquivo em json
        json a_x = this->g_arquivos.getData()["pos_inimigos_x"];
        json a_y = this->g_arquivos.getData()["pos_inimigos_y"];
        
        // Carrega Array com pos inimigos
        json::iterator  itr_x = a_x.begin(),
                        itr_y = a_y.begin();
        while (itr_x != a_x.end()){
            this->l_pos_inimigos.push_back(Vector2f(itr_x.value(), itr_y.value()));
            itr_x++;
            itr_y++;
        }
        
        // Carrega Array com pos obstaculos
        a_x = this->g_arquivos.getData()["pos_obstaculos_x"];
        a_y = this->g_arquivos.getData()["pos_obstaculos_y"];
        itr_x = a_x.begin();
        itr_y = a_y.begin();
        while (itr_x != a_x.end()){
            this->l_pos_obstaculos.push_back(Vector2f(itr_x.value(), itr_y.value()));
            itr_x++;
            itr_y++;
        }

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
    data["pos_x_boss"] = this->pos_boss.x;
    data["pos_y_boss"] = this->pos_boss.y;
    data["pos_y_p_b"] = this->pos_player_b.y;
    data["pos_x_win"] = this->getPosXWin();
    
    // Cria arrays json
    json a_x = json::array();
    json a_y = json::array();
    
    // Carrega arrays json de Inimigos
    for (Vector2f vector: this->l_pos_inimigos){
        a_x.push_back(vector.x);
        a_y.push_back(vector.y);
    }
    
    // Passa array para o objeto json
    data["pos_inimigos_x"] = a_x;
    data["pos_inimigos_y"] = a_y;
    
    // Limpa arrays json
    a_x.clear();
    a_y.clear();
    
    // Carrega arrays json de obstaculos
    for (Vector2f vector: this->l_pos_obstaculos){
        a_x.push_back(vector.x);
        a_y.push_back(vector.y);
    }
    
    // Passa array para o objeto json
    data["pos_obstaculos_x"] = a_x;
    data["pos_obstaculos_y"] = a_y;
    
    // Limpa arrays json
    a_x.clear();
    a_y.clear();
    
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

void ParametrosFase::setPosBoss(const Vector2f &pos_boss) {
    this->pos_boss = pos_boss;
}

const Vector2f& ParametrosFase::getPosBoss() const {
    return this->pos_boss;
}

void ParametrosFase::setPosXWin(const float &pos_x_win) {
    this->pos_x_win = pos_x_win;
}

const float& ParametrosFase::getPosXWin() const {
    return this->pos_x_win;
}

void ParametrosFase::setListaPosInimigos(const vector<Vector2f>& l_pos_inimigos) {
    this->l_pos_inimigos = l_pos_inimigos;
}

const vector<Vector2f>& ParametrosFase::getListaPosInimigos() const {
    return this->l_pos_inimigos;
}

void ParametrosFase::setListaPosObstaculos(const vector<Vector2f>& l_pos_obstaculos) {
    this->l_pos_obstaculos = l_pos_obstaculos;
}

const vector<Vector2f>& ParametrosFase::getListaPosObstaculos() const {
    return this->l_pos_obstaculos;
}
}}
