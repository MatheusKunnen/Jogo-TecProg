//
//  FaseMontanhaState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "FaseMontanhaState.hpp"

namespace Game { namespace States{

// Contructor & Destructor
FaseMontanhaState::FaseMontanhaState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys, Fase& fase):
fase(fase),
State(handler, g_grafico, supported_keys, fase_montanha){
    this->initValidKeys();
}

FaseMontanhaState::~FaseMontanhaState(){
    this->fase.onCloseFase();
}

// Init Methods
void FaseMontanhaState::initValidKeys(){
    try{
        // Inicia Teclas a ser utilizadas
        this->used_keys["MOVE_LEFT_A"] = this->supported_keys->at("A");
        this->used_keys["MOVE_RIGHT_A"] = this->supported_keys->at("D");
        this->used_keys["JUMP_A"] = this->supported_keys->at("W");
        this->used_keys["MOVE_LEFT_B"] = this->supported_keys->at("LEFT");
        this->used_keys["MOVE_RIGHT_B"] = this->supported_keys->at("RIGHT");
        this->used_keys["JUMP_B"] = this->supported_keys->at("UP");
        this->used_keys["PAUSE"] = this->supported_keys->at("Space");
        this->used_keys["CLOSE"] = this->supported_keys->at("Escape");
    } catch (std::exception e) {
        cerr << "FATAL ERROR: FaseMontanhaState::initValidkeys: " << e.what() << endl;
    }
}

void FaseMontanhaState::update(const float &dt) {
    this->updateKeyInput(dt);
    this->fase.update(dt);
}

void FaseMontanhaState::updateKeyInput(const float& dt){
    // Verifica estado das keys utilizadas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_LEFT_A"])))
        return;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_RIGHT_A"])))
        return;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["JUMP_A"])))
        return;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_LEFT_B"])))
        return;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_RIGHT_B"])))
        return;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["JUMP_B"])))
        this->manager->pushTopState(States::pause_menu);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["CLOSE"])))
        this->endState();
}

void FaseMontanhaState::render(RenderTarget *target) {
    if (target == nullptr)
        target = this->g_grafico->getRenderWindow();
    this->fase.render(target);
}
}}
