//
//  MainMenuState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "MainMenuState.hpp"

namespace Game { namespace States {

// Constructor & Destructor
MainMenuState::MainMenuState(sf::RenderWindow* render_window, map<string, int>* supported_keys):
State(render_window, supported_keys),
background(),
options_button(nullptr)
{
    this->background.setSize(sf::Vector2f(this->render_window->getSize()));
    this->background.setFillColor(sf::Color::White);
    initValidKeys();
    initFonts();
    initButtons();
}

MainMenuState::~MainMenuState(){
    
}

// Init Methods
void MainMenuState::initValidKeys(){
    try{
        this->used_keys["MOVE_LEFT"] = this->supported_keys->at("A");
        this->used_keys["MOVE_RIGHT"] = this->supported_keys->at("D");
        this->used_keys["MOVE_UP"] = this->supported_keys->at("S");
        this->used_keys["MOVE_DOWN"] = this->supported_keys->at("W");
    } catch (std::exception e) {
        cerr << "FATAL ERROR: MainMenuState::initValidkeys: " << e.what() << endl;
    }
}

void MainMenuState::initFonts(){
    if (!font.loadFromFile("Resources/fonts/font-01.otf")){
        throw ("FATAL ERROR: MainMenuState::initFonts(): failed to load Resources/fonts/font-01.otf");
    }
}

void MainMenuState::initButtons(){
    this->options_button = new Button(Vector2f(150.f,50.f), Vector2f(200.f,200.f), &this->font, "New Game");
}

// Methods
void MainMenuState::endState(){
    cout << "Ending MainMenuState" << endl;
}
void MainMenuState::updateInput(const float& dt){
    this->checkQuit();
    
}

void MainMenuState::update(const float& dt){
    this->updateMousePos();
    this->updateInput(dt);
    
    this->options_button->update(this->mouse_pos_view);
    
}

void MainMenuState::render(RenderTarget* target){
    if (target == nullptr)
        target = this->render_window;
    target->draw(this->background);
    options_button->render(target);
}

}};
