//
//  FaseFlorestaState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "FaseFlorestaState.hpp"

namespace Game { namespace States{

// Contructor & Destructor
FaseFlorestaState::FaseFlorestaState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys):
fase(g_grafico, Jogo::getInstance()->getJogadorA(), Jogo::getInstance()->getJogadorB()),
State(handler, g_grafico, supported_keys, fase_floresta){
    this->initValidKeys();
}

FaseFlorestaState::~FaseFlorestaState(){
    
}

// Init Methods
void FaseFlorestaState::initValidKeys(){
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
        cerr << "FATAL ERROR: FaseFlorestaState::initValidkeys: " << e.what() << endl;
    }
}

void FaseFlorestaState::update(const float &dt) {
    this->updateKeyInput(dt);
    this->fase.update(dt);
}

void FaseFlorestaState::updateKeyInput(const float &dt){
    // Verifica estado das keys utilizadas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_LEFT_A"])))
        this->fase.onKeyInput(Fases::Eventos::Tipo::M_LEFT_A);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_RIGHT_A"])))
        this->fase.onKeyInput(Fases::Eventos::Tipo::M_RIGHT_A);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["JUMP_A"])))
        this->fase.onKeyInput(Fases::Eventos::Tipo::JUMP_A);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_LEFT_B"])))
        this->fase.onKeyInput(Fases::Eventos::Tipo::M_LEFT_B);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_RIGHT_B"])))
        this->fase.onKeyInput(Fases::Eventos::Tipo::M_RIGHT_B);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["JUMP_B"])))
        this->fase.onKeyInput(Fases::Eventos::Tipo::JUMP_B);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["CLOSE"])))
        this->endState();
}

void FaseFlorestaState::render(RenderTarget *target) {
    if (target == nullptr)
        target = this->g_grafico->getRenderWindow();
    this->fase.render(target);
}

}}
