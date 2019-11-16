//
//  GerenciadorArquivos.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "GerenciadorArquivos.hpp"

namespace Game { namespace Gerenciadores {

GerenciadorArquivos::GerenciadorArquivos(const string& filename):
filename(filename),
data(nullptr)
{
    
}

GerenciadorArquivos::~GerenciadorArquivos(){
    this->data.clear();
}

bool GerenciadorArquivos::load(){
    bool status = true;
    try{
        std::ifstream i(this->filename);
        json j;
        i >> this->data;
        if (DEBUG_MODE) cout << this->data.dump() << endl; // DEBUG
        i.close();
    } catch (std::exception e){
        cerr << "ERROR: GerenciadorArquivos.load(): " << e.what() << endl;
        status = false;
    }
    return status;
}

bool GerenciadorArquivos::save(){
    bool status = true;
    try{
        std::ofstream out(this->filename);
        out << this->data.dump() << endl;
        out.close();
    } catch (std::exception e){
        cerr << "ERROR: GerenciadorArquivos.save(): " << e.what() << endl;
        status = false;
    }
    return status;
}

json& GerenciadorArquivos::getData() {
    return this->data;
}

void GerenciadorArquivos::setData(const json &data){
    this->data = data;
}

void GerenciadorArquivos::clear(){
    this->data.clear();
}
// Getters & Setters
void GerenciadorArquivos::setFilename(const string &filename){
    this->filename = filename;
}

const string& GerenciadorArquivos::getFilename() const {
    return this->filename;
}

}}
