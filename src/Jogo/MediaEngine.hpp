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
// SFML includes
#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::RenderTarget;
using sf::Event;
using sf::Clock;

namespace Game {

class MediaEngine{
private:
    // Singleton instance
    static MediaEngine*         main_instance;
    
    // SFML Attributes
    RenderWindow*               main_window;
    
    // Attributes
    MediaEngineParameters       parameters;
    
    // init Methods
    void initWindow();
    
public:
    // Constructor & Destructor
    explicit MediaEngine(const string& parameters_file = "");
    ~MediaEngine();
    // Singleton methods
    static MediaEngine* getInstance();
    void deleteInstance();
    // Setters & Getters
    RenderWindow* getRenderWindow();
};

}
#endif /* MediaEngine_hpp */
