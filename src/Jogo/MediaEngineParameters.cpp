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
const int MediaEngineParameters::DEFAULT_STYLE_NORMAL(sf::Style::Titlebar | sf::Style::Close);
const int MediaEngineParameters::DEFAULT_STYLE_FULLSCREEN(sf::Style::Fullscreen);
const string MediaEngineParameters::DEFAULT_WINDOW_TITLE("GAME SFML | Matheus Kunnen");

// Constructor & Destructor
MediaEngineParameters::MediaEngineParameters(string file):
window_width(MediaEngineParameters::DEFAULT_WINDOW_WIDTH),
window_height(MediaEngineParameters::DEFAULT_WINDOW_HEIGHT),
frame_rate_limit(MediaEngineParameters::DEFAULT_FRAMERATE),
fullscreen(false),
style(MediaEngineParameters::DEFAULT_STYLE_NORMAL),
window_title(MediaEngineParameters::DEFAULT_WINDOW_TITLE),
antialias_level(0)
{
    this->setStyle((fullscreen) ? MediaEngineParameters::DEFAULT_STYLE_FULLSCREEN : MediaEngineParameters::DEFAULT_STYLE_NORMAL);
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

void MediaEngineParameters::setFrameRateLimit(int frame_rate_limit){
    this->frame_rate_limit = frame_rate_limit;
}

int MediaEngineParameters::getFrameRateLimit() const{
    return this->frame_rate_limit;
}

void MediaEngineParameters::setStyle(int style){
    this->style = style;
}

int MediaEngineParameters::getStyle() const{
    return this->style;
}

void MediaEngineParameters::setFullscreen(bool fullscreen){
    this->fullscreen = fullscreen;
    if (this->fullscreen)
        this->setStyle(sf::Style::Fullscreen);
    else
        this->setStyle(MediaEngineParameters::DEFAULT_STYLE_NORMAL);
}

bool MediaEngineParameters::isFullscreen() const {
    return this->fullscreen;
}

void MediaEngineParameters::setWindowTitle(const string window_title){
    this->window_title = window_title;
}

const string& MediaEngineParameters::getWindowTitle() const{
    return this->window_title;
}

void MediaEngineParameters::setAntialiasLevel(unsigned int antialias_level){
    this->antialias_level = antialias_level;
}

unsigned MediaEngineParameters::getAntialiasLevel() const {
    return this->antialias_level;
}

}

