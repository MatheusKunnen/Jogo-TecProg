//
//  Parameters.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Parametros.hpp"

namespace Game {  namespace Parametros {

Parametro::Parametro(const string& filename):
g_arquivos(filename),
filename(filename){
    
}

Parametro::~Parametro(){
    this->filename.clear();
}

void Parametro::setFilename(const string &filename){
    this->filename = filename;
}

const string& Parametro::getFilename() const {
    return this->filename;
}

}}
