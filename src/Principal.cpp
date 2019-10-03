//
//  Principal.cpp
//  SFML-Test
//
//  Created by Matheus Kunnen Ledesma on 8/22/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//
#include "Principal.hpp"

Principal::Principal(int i){
    this->nosewe  = i;
}

void Principal::printInt(){
    std::cout << " > " << this->nosewe << std::endl;
}
