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
MainMenuState::MainMenuState(sf::RenderWindow* render_window, map<string, int>* supported_keys, stack<State*>* states_stack):
State(render_window, supported_keys, states_stack),
background(),
buttons()
{
    this->background.setSize(sf::Vector2f(this->render_window->getSize()));
    this->background.setFillColor(sf::Color::White);
    initValidKeys();
    initFonts();
    initBackground();
    initButtons();
}

MainMenuState::~MainMenuState(){
    for(map<int, Button*>::iterator itr = this->buttons.begin(); itr != this->buttons.end(); ++itr){
        delete itr->second;
        buttons.erase(itr);
    }
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
    if (!font.loadFromFile(FONT_01_DIR)){
        throw ("FATAL ERROR: MainMenuState::initFonts(): failed to load Resources/fonts/font-01.otf");
    }
}

void MainMenuState::initBackground(){
    if (!this->bg_texture.loadFromFile("Resources/img/backgrounds/bg-main_menu.jpeg"))
        throw ("FATAL ERROR: MainMenuState::initBackground(): failed to load Resources/img/backgrounds/bg-main_menu.jpeg");
    this->background.setTexture(&this->bg_texture);
}

void MainMenuState::initButtons(){
    Vector2f btn_size = Vector2f(450.f, 100.f);
    Vector2f btn_pos = Vector2f(render_window->getSize().x/2.f, render_window->getSize().y / 4.f);
    buttons[btn_new_game] = new Button(btn_size, btn_pos, &this->font, "New Game");
    btn_pos.y = btn_pos.y + btn_size.y *1.2;
    buttons[btn_config] = new Button(btn_size, btn_pos, &this->font, "Config");
    btn_pos.y = btn_pos.y + btn_size.y *1.2;
    buttons[btn_exit] = new Button(btn_size, btn_pos, &this->font, "EXIT");
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
    
    for(map<int, Button*>::iterator itr = this->buttons.begin(); itr != this->buttons.end(); ++itr)
        itr->second->update(this->mouse_pos_view);
    
    if (this->buttons[btn_exit]->isPressed()){
        this->quit = true;
    }
    
    if (this->buttons[btn_new_game]->isPressed()){
        this->states_stack->push(new GameState(this->render_window,  this->supported_keys, this->states_stack));
    }
}

void MainMenuState::render(RenderTarget* target){
    if (target == nullptr)
        target = this->render_window;
    target->draw(this->background);
    for(map<int, Button*>::iterator itr = this->buttons.begin(); itr != this->buttons.end(); ++itr)
        itr->second->render(target);
}

}};
