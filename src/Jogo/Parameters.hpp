//
//  Parameters.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Parameters_hpp
#define Parameters_hpp

#include "base_includes.hpp"

namespace Game {

class Parameters {
private:
    string filename;
public:
    Parameters(const string& filename);
    ~Parameters();
    // Getters & Setters
    void setFilename(const string& filename);
    const string& getFilename() const;
    
};

}

#endif /* Parameters_hpp */
