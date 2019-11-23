//
//  EndGameMenu.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/19/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "EndGameMenu.hpp"
#include "../States/StateManager.hpp"

namespace Game { namespace Menus{
  
// Constructor & Destructor
EndGameMenu::EndGameMenu(StateManager* handler, const bool& win):
Menu(handler, States::states_id::failed_menu),
win(win)
{
    this->initMenu();
}
    
EndGameMenu::~EndGameMenu(){
    this->widgets.clear();
}


// Init Methods
void EndGameMenu::initMenu(){
    this->initFonts();
    this->initTextures();
    this->initWidgets();
    this->initBackground();
}

void EndGameMenu::initWidgets(){
    this->initButtons();
    this->initTextViews();
}

void EndGameMenu::initButtons(){
    // Inicia buttons com suas posicoes é tamanhos
    Vector2f btn_size = Vector2f(450.f, 100.f);
    Vector2f btn_pos = Vector2f(this->context.getRenderWindow()->getSize().x*0.5, this->context.getRenderWindow()->getSize().y*.8);
    
    this->widgets.add(btn_exit, new Button(btn_exit, context ,*this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "VOLTAR"));
}

void EndGameMenu::initTextViews(){
    // Inicia buttons com suas posicoes é tamanhos
    Vector2f size = Vector2f(450.f, 100.f);
    Vector2f pos = Vector2f(this->context.getRenderWindow()->getSize().x*0.5, this->context.getRenderWindow()->getSize().y*.5);
    
    TextView* txt = new TextView(txt_01, context ,*this, size, pos, this->fonts.get(Resources::Fonts::font_01), (win) ? "GANHOU :D" : "PERDEU :(");
    txt->setTextColor((win) ? sf::Color::Green : sf::Color::Red);
    this->widgets.add(txt_01, txt);
}


// Methods
void EndGameMenu::update(const float &dt) {
    this->context.update(dt);
    this->widgets.update(dt);
}

void EndGameMenu::render(RenderTarget *target) {
    if (!target)
        target = GerenciadorGrafico::getInstance()->getRenderWindow();
    target->draw(this->background);
    this->widgets.render(target);
}
   
void EndGameMenu::onGuiEvent(int id, GUI::Events::Type event_id){
    switch(id) {
        case btn_exit:
            onExit();
            break;
    }
}

void EndGameMenu::onExit() {
    // Solicita remoção ao StateManager
    this->manager->addStatePop(2);
}

}};

