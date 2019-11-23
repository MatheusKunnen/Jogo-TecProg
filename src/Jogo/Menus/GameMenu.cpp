//
//  GameMenu.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "GameMenu.hpp"
#include "../States/StateManager.hpp"

namespace Game { namespace Menus{
  
// Constructor & Destructor
GameMenu::GameMenu(StateManager* handler):
Menu(handler, States::states_id::game_menu)
{
    this->initMenu();
}
    
GameMenu::~GameMenu(){
    this->widgets.clear();
}


// Init Methods
void GameMenu::initMenu(){
    this->initFonts();
    this->initTextures();
    this->initWidgets();
    this->initBackground();
}

void GameMenu::initWidgets(){
    this->initButtons();
}

void GameMenu::initButtons(){
    // Inicia buttons com suas posicoes é tamanhos
    Vector2f btn_size = Vector2f(450.f, 200.f);
    Vector2f btn_pos = Vector2f(this->context.getRenderWindow()->getSize().x/2.f, this->context.getRenderWindow()->getSize().y / 4.f);
    
    this->widgets.add(btn_start_floresta, new Button(btn_start_floresta, context, *this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "FLORESTA"));
    
    btn_pos.y = btn_pos.y + btn_size.y *1.2;
    this->widgets.add(btn_start_montanha, new Button(btn_start_montanha, context, *this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "MONTANHA"));
    
    btn_pos.y = btn_pos.y + btn_size.y *1.2;
    this->widgets.add(btn_exit, new Button(btn_exit, context ,*this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "VOLTAR"));
}

void GameMenu::initBackground() {
    this->textures.load(Resources::Textures::bg_game, this->textures.getFilename(Resources::Textures::bg_game));
    this->background.setTexture(&this->textures.get(Resources::Textures::bg_game));
}


// Methods
void GameMenu::update(const float &dt) {
    this->context.update(dt);
    this->widgets.update(dt);
}

void GameMenu::render(RenderTarget *target) {
    if (!target)
        target = GerenciadorGrafico::getInstance()->getRenderWindow();
    target->draw(this->background);
    this->widgets.render(target);
}
   
void GameMenu::onGuiEvent(int id, GUI::Events::Type event_id){
    switch(id) {
        case btn_start_floresta:
            onStartFaseFloresta();
            break;
        case btn_start_montanha:
            onStartFaseMontanha();
            break;
        case btn_exit:
            onExit();
            break;
    }
}

void GameMenu::onStartFaseFloresta() {
    this->manager->pushTopState(States::states_id::fase_floresta);
}

void GameMenu::onStartFaseMontanha() {
    this->manager->pushTopState(States::states_id::fase_montanha);
}

void GameMenu::onExit(){
    this->quit = true;
}

}};
