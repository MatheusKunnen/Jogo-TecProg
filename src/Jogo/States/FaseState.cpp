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
FaseState::FaseState(StateManager* handler, Fase& fase, Jogador* jogador_a, Jogador* jogador_b):
State(handler, fase_floresta),
fase(fase)
{
    this->fase.onInitFase(jogador_a, jogador_b, this);
    
}

FaseState::~FaseState(){
    // Notifica à fase que o estado esta fechando;
    this->fase.onCloseFase();
}

void FaseState::update(const float &dt) {
    // Notifica update para a fase
    this->fase.update(dt);
    // Verifica teclas apertadas
    this->updateKeyInput(dt);
}

void FaseState::updateKeyInput(const float &dt){
    // Verifica estado das keys utilizadas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->fase.onKeyInput(Fases::eventos_jogador::Tipo::M_LEFT_A, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->fase.onKeyInput(Fases::eventos_jogador::Tipo::M_RIGHT_A, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->fase.onKeyInput(Fases::eventos_jogador::Tipo::JUMP_A, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->fase.onKeyInput(Fases::eventos_jogador::Tipo::M_LEFT_B, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->fase.onKeyInput(Fases::eventos_jogador::Tipo::M_RIGHT_B, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->fase.onKeyInput(Fases::eventos_jogador::Tipo::JUMP_B, dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->manager->pushTopState(pause_menu);
}

void FaseState::render(RenderTarget *target) {
    if (target == nullptr)
        target = GerenciadorGrafico::getInstance()->getRenderWindow();
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
