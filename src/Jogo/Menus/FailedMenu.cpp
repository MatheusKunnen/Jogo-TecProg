//
//  FailedMenu.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "FailedMenu.hpp"
#include "StateManager.hpp"

namespace Game { namespace Menus{
  
// Constructor & Destructor
FailedMenu::FailedMenu(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys):
Menu(handler, g_grafico, supported_keys, States::states_id::failed_menu)
{
    this->initMenu();
}
    
FailedMenu::~FailedMenu(){
    this->widgets.clear();
}


// Init Methods
void FailedMenu::initMenu(){
    this->initFonts();
    this->initTextures();
    this->initWidgets();
    this->initBackground();
}

void FailedMenu::initWidgets(){
    this->initButtons();
    this->initTextViews();
}

void FailedMenu::initButtons(){
    // Inicia buttons com suas posicoes é tamanhos
    Vector2f btn_size = Vector2f(450.f, 100.f);
    Vector2f btn_pos = Vector2f(this->context.getRenderWindow()->getSize().x*0.5, this->context.getRenderWindow()->getSize().y*.8);
    
    //btn_pos.y = btn_pos.y + btn_size.y *1.2;
    this->widgets.add(btn_exit, new Button(btn_exit, context ,*this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "VOLTAR"));
}

void FailedMenu::initTextViews(){
    // Inicia buttons com suas posicoes é tamanhos
    Vector2f btn_size = Vector2f(450.f, 100.f);
    Vector2f btn_pos = Vector2f(this->context.getRenderWindow()->getSize().x*0.5, this->context.getRenderWindow()->getSize().y*.2);
    
    //btn_pos.y = btn_pos.y + btn_size.y *1.2;
    TextView* txt = new TextView(txt_01, context ,*this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "PERDEU :(");
    this->widgets.add(txt_01, txt);
}


// Methods
void FailedMenu::update(const float &dt) {
    this->context.update(dt);
    this->widgets.update(dt);
}

void FailedMenu::render(RenderTarget *target) {
    if (!target)
        target = this->g_grafico->getRenderWindow();
    target->draw(this->background);
    this->widgets.render(target);
}
   
void FailedMenu::onGuiEvent(int id, GUI::Events::Type event_id){
    switch(id) {
        case btn_exit:
            onExit();
            break;
    }
}

void FailedMenu::onExit() {
    // Muda bandeira de finalização
    this->manager->addStatePop(2);
}

}};
