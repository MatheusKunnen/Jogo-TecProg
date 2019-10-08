//
//  MediaEngineParameters.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "MediaEngineParameters.hpp"

namespace Game {

// Const init
const int MediaEngineParameters::DEFAULT_FRAMERATE(60);
const int MediaEngineParameters::DEFAULT_WINDOW_HEIGHT(1080);
const int MediaEngineParameters::DEFAULT_WINDOW_WIDTH(1920);
const string MediaEngineParameters::DEFAULT_WINDOW_TITLE("GAME SFML | Matheus Kunnen");

// Constructor & Destructor
MediaEngineParameters::MediaEngineParameters(string file):
frame_rate_limit(MediaEngineParameters::DEFAULT_FRAMERATE),
window_width(MediaEngineParameters::DEFAULT_WINDOW_WIDTH),
window_height(MediaEngineParameters::DEFAULT_WINDOW_HEIGHT)
,window_title(MediaEngineParameters::DEFAULT_WINDOW_TITLE)
{
    if(file != "")
        this->loadFromFile(file);
}

MediaEngineParameters::~MediaEngineParameters(){
    
}

// Methods
bool MediaEngineParameters::loadFromFile(string file){
    return false;
}

bool MediaEngineParameters::saveToFile(string file){
    return false;
}

// Getters & Setters
void MediaEngineParameters::setFrameRateLimit(int frame_rate_limit){
    this->frame_rate_limit = frame_rate_limit;
}

int MediaEngineParameters::getFrameRateLimit() const{
    return this->frame_rate_limit;
}

void MediaEngineParameters::setWindowWidth(int window_width){
    this->window_width = window_width;
    
}

int MediaEngineParameters::getWindowWidth() const{
    return this->window_width;
}

void MediaEngineParameters::setWindowHeight(int window_height){
    this->window_height = window_height;
}

int MediaEngineParameters::getWindowHeight() const{
    return this->window_height;
}

void MediaEngineParameters::setWindowTitle(const string window_title){
    this->window_title = window_title;
}

const string& MediaEngineParameters::getWindowTitle() const{
    return this->window_title;
}
}

