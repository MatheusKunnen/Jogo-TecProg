//
//  ParametrosGerenciadorGrafico.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "ParametrosGerenciadorGrafico.hpp"

namespace Game {  namespace Parametros {

// Const init
const int ParametrosGerenciadorGrafico::DEFAULT_FRAMERATE(0);
const int ParametrosGerenciadorGrafico::DEFAULT_WINDOW_HEIGHT(1024);
const int ParametrosGerenciadorGrafico::DEFAULT_WINDOW_WIDTH(1920);
const int ParametrosGerenciadorGrafico::DEFAULT_STYLE_NORMAL(sf::Style::Titlebar | sf::Style::Close);
const int ParametrosGerenciadorGrafico::DEFAULT_STYLE_FULLSCREEN(sf::Style::Fullscreen);
const string ParametrosGerenciadorGrafico::DEFAULT_WINDOW_TITLE("Danger in the Woods | Matheus Kunnen");

// Constructor & Destructor
ParametrosGerenciadorGrafico::ParametrosGerenciadorGrafico(const string& file):
        Parametro(file),
        window_width(ParametrosGerenciadorGrafico::DEFAULT_WINDOW_WIDTH),
        window_height(ParametrosGerenciadorGrafico::DEFAULT_WINDOW_HEIGHT),
        frame_rate_limit(ParametrosGerenciadorGrafico::DEFAULT_FRAMERATE),
        fullscreen(false),
        style(ParametrosGerenciadorGrafico::DEFAULT_STYLE_NORMAL),
        window_title(ParametrosGerenciadorGrafico::DEFAULT_WINDOW_TITLE),
        antialias_level(0)
{
    this->setStyle((fullscreen) ? ParametrosGerenciadorGrafico::DEFAULT_STYLE_FULLSCREEN : ParametrosGerenciadorGrafico::DEFAULT_STYLE_NORMAL);
    if(file != "")
        this->loadFromFile(file);
}

ParametrosGerenciadorGrafico::~ParametrosGerenciadorGrafico(){
    
}

// Methods
bool ParametrosGerenciadorGrafico::loadFromFile(const string& file){
    bool status = true;
    try{
        std::ifstream i(file);
        json j;
        i >> j;
        this->setWindowWidth(j["window_width"]);
        this->setWindowHeight(j["window_height"]);
        this->setWindowTitle(j["window_title"]);
        this->setFullscreen(j["fullscreen"] == 1);
        if (DEBUG_MODE)
            cout << j.dump() << endl; // DEBUG
        i.close();
        j.clear();
    } catch (std::exception e){
        cerr << "ERROR: ParametrosGGrafico.loadFromFile: " << e.what() << endl;
        status = false;
    }
    return status;
}

bool ParametrosGerenciadorGrafico::saveToFile(const string& file){
    bool status = true;
    try{
        std::ofstream out(file);
        json j;
        j["window_width"] = this->getWindowWidth();
        j["window_height"] = this->getWindowHeight();
        j["window_title"] = this->getWindowTitle();
        j["fullscreen"] = this->isFullscreen() ? 1 : 0;
        if (DEBUG_MODE)
            cout << j.dump() << endl; // DEBUG
        out << j.dump() << endl;
        out.close();
        j.clear();
    } catch (std::exception e){
        cerr << "ERROR: ParametrosGGrafico.loadFromFile: " << e.what() << endl;
        status = false;
    }
    return status;
}

// Getters & Setters
void ParametrosGerenciadorGrafico::setWindowWidth(int window_width){
    this->window_width = window_width;
}

int ParametrosGerenciadorGrafico::getWindowWidth() const{
    return this->window_width;
}

void ParametrosGerenciadorGrafico::setWindowHeight(int window_height){
    this->window_height = window_height;
}

int ParametrosGerenciadorGrafico::getWindowHeight() const{
    return this->window_height;
}

void ParametrosGerenciadorGrafico::setFrameRateLimit(int frame_rate_limit){
    this->frame_rate_limit = frame_rate_limit;
}

int ParametrosGerenciadorGrafico::getFrameRateLimit() const{
    return this->frame_rate_limit;
}

void ParametrosGerenciadorGrafico::setStyle(int style){
    this->style = style;
}

int ParametrosGerenciadorGrafico::getStyle() const{
    return this->style;
}

void ParametrosGerenciadorGrafico::setFullscreen(bool fullscreen){
    this->fullscreen = fullscreen;
    if (this->fullscreen)
        this->setStyle(sf::Style::Fullscreen);
    else
        this->setStyle(ParametrosGerenciadorGrafico::DEFAULT_STYLE_NORMAL);
}

bool ParametrosGerenciadorGrafico::isFullscreen() const {
    return this->fullscreen;
}

void ParametrosGerenciadorGrafico::setWindowTitle(const string window_title){
    this->window_title = window_title;
}

const string& ParametrosGerenciadorGrafico::getWindowTitle() const{
    return this->window_title;
}

void ParametrosGerenciadorGrafico::setAntialiasLevel(unsigned antialias_level){
    this->antialias_level = antialias_level;
}

unsigned ParametrosGerenciadorGrafico::getAntialiasLevel() const {
    return this->antialias_level;
}

}}

