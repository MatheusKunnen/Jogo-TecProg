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
    // Attributes
    string filename;
public:
    // Contructors & Destructors
    Parameters(const string& filename = "");
    ~Parameters();
    // Methods
    virtual bool loadFromFile(const string& filename) = 0;
    virtual bool saveToFile(const string& filename = "") const = 0;
    // Getters & Setters
    void setFilename(const string& filename);
    const string& getFilename() const;
    
};

}

#endif /* Parameters_hpp */
