//
//  GameState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "GameState.hpp"
namespace Game { namespace States {
// Constructor & Destructor
GameState::GameState(RenderWindow* render_window, map<string, int>* supported_keys, stack<State*>* states_stack):
State(render_window, supported_keys, states_stack)
{
    initValidKeys();
}

GameState::~GameState(){
    
}

// Init Methods
void GameState::initValidKeys(){
    try{
        this->used_keys["MOVE_LEFT"] = this->supported_keys->at("A");
        this->used_keys["MOVE_RIGHT"] = this->supported_keys->at("D");
        this->used_keys["MOVE_UP"] = this->supported_keys->at("W");
        this->used_keys["MOVE_DOWN"] = this->supported_keys->at("S");
    } catch (std::exception e) {
        cerr << "FATAL ERROR: GameState::initValidkeys: " << e.what() << endl;
    }
}

// Methods
void GameState::endState(){
    cout << "Ending gamestate" << endl;
}
void GameState::updateInput(const float& dt){
    this->checkQuit();
    
}

void GameState::update(const float& dt){
    this->updateMousePos();
    this->updateInput(dt);
    
    this->jogador.update(dt);
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_LEFT"])))
        this->jogador.move(sf::Vector2f(-1.f,0.f), dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_RIGHT"])))
        this->jogador.move(sf::Vector2f(1.f,0), dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_UP"])))
        this->jogador.move(sf::Vector2f(0,-1.f), dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_DOWN"])))
        this->jogador.move(sf::Vector2f(0,1.f), dt);
}

void GameState::render(RenderTarget* target){
    if (target == nullptr)
        target = this->render_window;
    this->jogador.render(target);
}
}};
