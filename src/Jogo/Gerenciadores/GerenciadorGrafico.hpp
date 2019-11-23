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
#include "../Parametros/ParametrosGerenciadorGrafico.hpp"

using Game::Parametros::ParametrosGerenciadorGrafico;

namespace Game { namespace Gerenciadores {

class GerenciadorGrafico{
private:
    // Singleton instance
    static GerenciadorGrafico*  main_instance;
   
    // Attributes
    ParametrosGerenciadorGrafico    parametros;
    RenderWindow*                   main_window;
    View                            main_view;
    
    // init Methods
    void initWindow(); // Inicia RenderWindow com os parametros corretos
    void initView(); // Obtem a View original do RenderWindow
    
    // Private Methods
    void onViewUpdated(); // Passa atualiza View do RenderWindow
    
    // Private Constructor (para Singleton)
    explicit GerenciadorGrafico(const string& parameters_file = "Resources/config/graphic_config.json");
public:
    // Destructor
    ~GerenciadorGrafico();
    
    // Singleton methods
    static GerenciadorGrafico* getInstance(); // Instancia a classe
    void deleteInstance(); // Elimina Instancia do singleton
    
    // Methods
    bool moveView(const float& x, const float& y); // Desloca a View
    void resetDefaultView(); // Restaura a View original
    
    // Setters & Getters
    RenderWindow* getRenderWindow();
    const View* getView() const;
    void setViewPosition(const Vector2f& position);
    void setViewPosition(const float& x, const float& y);
};

}}
#endif /* MediaEngine_hpp */
