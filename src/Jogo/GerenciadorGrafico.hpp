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
    static GerenciadorGrafico*  main_instance;
    
    // SFML Attributes
    RenderWindow*               main_window;
    View                        main_view;
    
    // Attributes
    MediaEngineParameters       parameters;
    
    // init Methods
    void initWindow(); // Inicia RenderWindow com os parametros corretos
    void initView(); // Obtem a View original do RenderWindow
public:
    // Constructor & Destructor
    explicit GerenciadorGrafico(const string& parameters_file = "Resources/config/graphic_config.json");
    ~GerenciadorGrafico();
    
    // Singleton methods
    static GerenciadorGrafico* getInstance(); // Instancia a classe
    void deleteInstance(); // Elimina Instancia do singleton
    
    // Methods
    bool moveView(const float& x, const float& y); // Desloca a View
    void resetDefaultView(); // Restaura a View original
    bool inView(const Vector2f& position); // Verifica se a posicao encontra-se dentro da view
    bool inView(const float& x, const float& y);
    
    // Setters & Getters
    RenderWindow* getRenderWindow();
    const View* getView();
};

}
#endif /* MediaEngine_hpp */
