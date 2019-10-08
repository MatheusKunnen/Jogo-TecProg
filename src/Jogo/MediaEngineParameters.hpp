//
//  MediaEngineParameters.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef MediaEngineParameters_hpp
#define MediaEngineParameters_hpp

#include "base_includes.hpp"
namespace Game {
class MediaEngineParameters{
private:
    int frame_rate_limit;
    int window_width;
    int window_height;
    string window_title;
public:
    explicit MediaEngineParameters(string file = "");
    ~MediaEngineParameters();
    // Methods
    bool loadFromFile(string file);
    bool saveToFile(string file);
    //Getters & Setters
    void setFrameRateLimit(int frame_rate_limit);
    int getFrameRateLimit() const;
    void setWindowWidth(int window_width);
    int getWindowWidth() const;
    void setWindowHeight(int window_height);
    int getWindowHeight() const;
    void setWindowTitle(const string window_title);
    const string& getWindowTitle() const;
    // Const
    static const int DEFAULT_FRAMERATE;
    static const int DEFAULT_WINDOW_HEIGHT;
    static const int DEFAULT_WINDOW_WIDTH;
    static const string DEFAULT_WINDOW_TITLE;
};
}
#endif /* MediaEngineParameters_hpp */
