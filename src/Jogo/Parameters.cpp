//
//  Parameters.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Parameters.hpp"

namespace Game {  namespace Parameters {

Parameters::Parameters(const string& filename):
filename(filename){
    
}

Parameters::~Parameters(){
    this->filename.clear();
}

void Parameters::setFilename(const string &filename){
    this->filename = filename;
}

const string& Parameters::getFilename() const {
    return this->filename;
}

}}
