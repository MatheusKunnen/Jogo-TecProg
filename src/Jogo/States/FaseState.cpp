//
//  FaseFlorestaState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "FaseState.hpp"
#include "StateManager.hpp"

namespace Game { namespace States{

// Contructor & Destructor
FaseState::FaseState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys, Fase& fase, Jogador* jogador_a, Jogador* jogador_b):
State(handler, g_grafico, supported_keys, fase_floresta),
fase(fase)
{
    this->fase.onInitFase(jogador_a, jogador_b, this);
    this->initValidKeys(); // Relaciona Keys utilizadas
    
}

FaseState::~FaseState(){
    // Notifica à fase que o estado esta fechando;
    this->fase.onCloseFase();
}

// Init Methods
void FaseState::initValidKeys(){
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

void FaseState::update(const float &dt) {
    // Notifica update para a fase
    this->fase.update(dt);
    // Verifica teclas apertadas
    this->updateKeyInput(dt);
}

void FaseState::updateKeyInput(const float &dt){
    // Verifica estado das keys utilizadas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_LEFT_A"])))
        this->fase.onKeyInput(Fases::eventos_jogador::Tipo::M_LEFT_A, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_RIGHT_A"])))
        this->fase.onKeyInput(Fases::eventos_jogador::Tipo::M_RIGHT_A, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["JUMP_A"])))
        this->fase.onKeyInput(Fases::eventos_jogador::Tipo::JUMP_A, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_LEFT_B"])))
        this->fase.onKeyInput(Fases::eventos_jogador::Tipo::M_LEFT_B, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_RIGHT_B"])))
        this->fase.onKeyInput(Fases::eventos_jogador::Tipo::M_RIGHT_B, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["JUMP_B"])))
        this->fase.onKeyInput(Fases::eventos_jogador::Tipo::JUMP_B, dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["CLOSE"])))
        this->manager->pushTopState(pause_menu);
}

void FaseState::render(RenderTarget *target) {
    if (target == nullptr)
        target = this->g_grafico->getRenderWindow();
    this->fase.render(target); // Renderiza a fase
}

void FaseState::onWin(){
    this->manager->pushTopState(win_menu);
}

void FaseState::onFailed() {
    this->manager->pushTopState(failed_menu);
}

// Methods (FaseEventHandler)
void FaseState::onFaseEvent(Fases::Event event_id){
    switch (event_id) {
        case Fases::Event::win:
            this->onWin();
            break;
        case Fases::Event::failed:
            this->onFailed();
        default:
            cerr << "WARNING: FaseState::onFaseEvent(): Invalid event_id" << endl;
            break;
    }
}

}}
