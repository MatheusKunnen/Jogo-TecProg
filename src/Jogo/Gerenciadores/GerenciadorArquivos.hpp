//
//  GerenciadorArquivos.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef GerenciadorArquivos_hpp
#define GerenciadorArquivos_hpp

#include "../base_includes.hpp"
#include "../libs/json.hpp"

namespace Game { namespace Gerenciadores {
using namespace nlohmann;

class GerenciadorArquivos {
private:
    // Attributes
    string      filename;
    json        data;
public:
    // Constructor & Destructor
    GerenciadorArquivos(const string& filename);
    ~GerenciadorArquivos();
    
    // Methods
    bool load();
    bool save();
    json& getData();
    void setData(const json& data);
    void clear();
    
    // Getters & Setters
    void setFilename(const string& filename);
    const string& getFilename() const;
};

}}

#endif /* GerenciadorArquivos_hpp */
