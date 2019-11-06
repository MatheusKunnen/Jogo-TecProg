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
GameState::GameState(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys):
State(handler, g_grafico, supported_keys, states_id::game),
textures_used(),
jogador(nullptr)
{
    initTextures();
    initValidKeys();
    initEntities();
    lvl.LoadFromFile("Resources/maps/phase-X.tmx");
}

GameState::~GameState(){
    delete jogador;
}

// Init Methods
void GameState::initTextures(){
    textures_used.load(Resources::Textures::male_player, TextureHolder::getFilename(Resources::Textures::male_player)/*"Resources/img/sprites/player/male_player.png"*/);
}

void GameState::initValidKeys(){
    try{
        this->used_keys["MOVE_LEFT"] = this->supported_keys->at("A");
        this->used_keys["MOVE_RIGHT"] = this->supported_keys->at("D");
        this->used_keys["JUMP"] = this->supported_keys->at("W");
        this->used_keys["MOVE_DOWN"] = this->supported_keys->at("S");
        this->used_keys["CLOSE"] = this->supported_keys->at("Escape");
    } catch (std::exception e) {
        cerr << "FATAL ERROR: GameState::initValidkeys: " << e.what() << endl;
    }
}

void GameState::initEntities(){
    this->jogador = new Jogador(Vector2f(100.f, 100.f), &textures_used.get(Resources::Textures::male_player));
}

// Methods
void GameState::updateInput(const float& dt){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_LEFT"])))
        this->jogador->move(sf::Vector2f(-1.f,0.f), dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_RIGHT"])))
        this->jogador->move(sf::Vector2f(1.f,0), dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["MOVE_DOWN"])))
        this->jogador->move(sf::Vector2f(0,1.f), dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["JUMP"])))
        this->jogador->jump(5);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->used_keys["CLOSE"])))
        this->endState();
}

void GameState::update(const float& dt){
    this->updateInput(dt);
    this->jogador->update(dt);
}

void GameState::render(RenderTarget* target){
    if (target == nullptr)
        target = this->g_grafico->getRenderWindow();
    lvl.SetDrawingBounds(sf::Rect<float>(0.f, 0.f, 1920, 1024));
    //lvl.Move(2, 2);
    lvl.Draw((RenderWindow*)(target));
    this->jogador->render(target);
    
}
}};
