//
//  MediaEngine.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef MediaEngine_hpp
#define MediaEngine_hpp

// Generic Includes
#include "base_includes.hpp"
#include "MediaEngineParameters.hpp"

using Game::Parametros::MediaEngineParameters;

namespace Game {

class GerenciadorGrafico{
private:
    // Singleton instance
    static GerenciadorGrafico*         main_instance;
    
    // SFML Attributes
    RenderWindow*               main_window;
    
    // Attributes
    MediaEngineParameters       parameters;
    
    // init Methods
    void initWindow();
    
public:
    // Constructor & Destructor
    explicit GerenciadorGrafico(const string& parameters_file = "Resources/config/graphic_config.json");
    ~GerenciadorGrafico();
    // Singleton methods
    static GerenciadorGrafico* getInstance();
    void deleteInstance();
    // Setters & Getters
    RenderWindow* getRenderWindow();
    const View* getView();
};

}
#endif /* MediaEngine_hpp */
