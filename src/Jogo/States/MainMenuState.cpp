//
//  MainMenuState.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "MainMenuState.hpp"
#include "StateHandler.hpp"
namespace Game { namespace States {

// Constructor & Destructor
MainMenuState::MainMenuState(StateHandler* handler,GerenciadorGrafico* g_grafico, map<string, int>* supported_keys):
State(handler, g_grafico, supported_keys, states_id::game),
background(),
buttons(),
context(*g_grafico->getRenderWindow())
{
    this->background.setSize(sf::Vector2f(this->g_grafico->getRenderWindow()->getSize()));
    this->background.setFillColor(sf::Color::White);
    initValidKeys();
    initTextures();
    initFonts();
    initBackground();
    initButtons();
}

MainMenuState::~MainMenuState(){
    for(map<int, Button*>::iterator itr = this->buttons.begin(); itr != this->buttons.end(); ++itr){
        delete itr->second;
        //itr = buttons.erase(itr);
    }
	buttons.clear();
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

void MainMenuState::initTextures() {
	try {
		this->textures.load(Textures::background_01, TextureHolder::getFilename(Textures::background_01));
	} catch (std::exception e) {
		cerr << "MainMenuState::initTextures: ERROR Loading textutes: " << endl;
	}

}

void MainMenuState::initFonts(){
	try {
		if (!font.loadFromFile(FONT_01_DIR)) {
			throw runtime_error("FATAL ERROR: MainMenuState::initFonts(): failed to load Resources/fonts/font-01.otf");
		}
	}catch (std::exception e) {
			cerr << "MainMenuState::initFonts: ERROR Loading fontd: " << endl;
	}
}

void MainMenuState::initBackground(){
    //if (!this->bg_texture.loadFromFile(Textures))
    //    throw ("FATAL ERROR: MainMenuState::initBackground(): failed to load background textures.");
    this->background.setTexture(&this->textures.get(Textures::background_01));
}

void MainMenuState::initButtons(){
    //const int& id, Context& context, const Vector2f& back_size, const Vector2f& position, Font& font, const string& text = ""
    Vector2f btn_size = Vector2f(450.f, 100.f);
    Vector2f btn_pos = Vector2f(this->g_grafico->getRenderWindow()->getSize().x/2.f, this->g_grafico->getRenderWindow()->getSize().y / 4.f);
    buttons[btn_new_game] = new Button(btn_new_game, context, btn_size, btn_pos, this->font, "New Game");
    btn_pos.y = btn_pos.y + btn_size.y *1.2;
    buttons[btn_config] = new Button(btn_config, context, btn_size, btn_pos, this->font, "Config");
    btn_pos.y = btn_pos.y + btn_size.y *1.2;
    buttons[btn_exit] = new Button(btn_exit, context, btn_size, btn_pos, this->font, "EXIT");
    //buttons[btn_exit]->setEnabled(false);
}

// Methods
void MainMenuState::updateInput(const float& dt){
    if (this->buttons[btn_exit]->isPressed()){
        this->endState();
    }
        
    if (this->buttons[btn_new_game]->isPressed()){
        this->handler->pushState(states_id::game);
    }
}

void MainMenuState::update(const float& dt){
    this->updateMousePos();
    this->updateInput(dt);
    this->context.update(dt);
    for(map<int, Button*>::iterator itr = this->buttons.begin(); itr != this->buttons.end(); ++itr)
        itr->second->update();
}
    

void MainMenuState::render(RenderTarget* target){
    if (target == nullptr)
        target = this->g_grafico->getRenderWindow();
    target->draw(this->background);
    for(map<int, Button*>::iterator itr = this->buttons.begin(); itr != this->buttons.end(); ++itr)
        itr->second->render(target);
}

}};
