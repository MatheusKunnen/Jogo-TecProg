//
//  MediaEngineParameters.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef MediaEngineParameters_hpp
#define MediaEngineParameters_hpp

#include "Parametros.hpp"

namespace Game {  namespace Parametros {

class ParametrosGerenciadorGrafico : public Parametro{
private:
    // Attributes
    int             window_width;
    int             window_height;
    int             frame_rate_limit;
    int             style;
    bool            fullscreen;
    string          window_title;
    unsigned        antialias_level;
    
    
public:
    // Constructor & Destructor
    explicit ParametrosGerenciadorGrafico(const string& file = "");
    ~ParametrosGerenciadorGrafico();
    // Methods
    bool loadFromFile(const string& file);
    bool saveToFile(const string& file);
    //Getters & Setters
    void setWindowWidth(int window_width);
    int getWindowWidth() const;
    void setWindowHeight(int window_height);
    int getWindowHeight() const;
    void setFrameRateLimit(int frame_rate_limit);
    int getFrameRateLimit() const;
    void setStyle(int style);
    int getStyle() const;
    void setFullscreen(bool fullscreen);
    bool isFullscreen() const;
    void setWindowTitle(const string window_title);
    const string& getWindowTitle() const;
    void setAntialiasLevel(unsigned antialias_level);
    unsigned getAntialiasLevel() const;
    
    // Const
    static const int        DEFAULT_FRAMERATE;
    static const int        DEFAULT_WINDOW_HEIGHT;
    static const int        DEFAULT_WINDOW_WIDTH;
    static const string     DEFAULT_WINDOW_TITLE;
    static const int        DEFAULT_STYLE_NORMAL;
    static const int        DEFAULT_STYLE_FULLSCREEN;
};
}} 
#endif /* MediaEngineParameters_hpp */
