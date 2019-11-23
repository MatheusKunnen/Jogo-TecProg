//
//  Parameters.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Parameters_hpp
#define Parameters_hpp

#include "../Gerenciadores/GerenciadorArquivos.hpp"

namespace Game { namespace Parametros {

using Gerenciadores::GerenciadorArquivos;
using namespace nlohmann;

class Parametro {
protected:
    // Attributes
    GerenciadorArquivos g_arquivos;
    string filename;
    
public:
    // Contructors & Destructors
    Parametro(const string& filename = "");
    ~Parametro();
    
    // Methods
    virtual bool loadFromFile(const string& filename = "") = 0;
    virtual bool saveToFile(const string& filename = "") = 0;
    
    // Getters & Setters
    void setFilename(const string& filename);
    const string& getFilename() const;
    
};

}}

#endif /* Parameters_hpp */
