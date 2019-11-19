//
//  PauseMenu.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "PauseMenu.hpp"
namespace Game { namespace Menus{
  
// Constructor & Destructor
PauseMenu::PauseMenu(RenderWindow& window):
Menu(window)
{
    this->initMenu();
}
    
PauseMenu::~PauseMenu(){
    this->widgets.clear();
}


// Init Methods
void PauseMenu::initMenu(){
    this->initFonts();
    this->initTextures();
    this->initWidgets();
    this->initBackground();
}

void PauseMenu::initWidgets(){
    this->initButtons();
}

void PauseMenu::initButtons(){
    // Inicia buttons com suas posicoes é tamanhos
    Vector2f btn_size = Vector2f(450.f, 200.f);
    Vector2f btn_pos = Vector2f(this->context.getRenderWindow()->getSize().x/2.f, this->context.getRenderWindow()->getSize().y / 4.f);
    
    this->widgets.add(btn_resume_game, new Button(btn_resume_game, context, *this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "RESUMIR"));
    
    btn_pos.y = btn_pos.y + btn_size.y *1.2;
    this->widgets.add(btn_exit, new Button(btn_exit, context ,*this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "VOLTAR"));
}


// Methods
void PauseMenu::updateMenu(const float &dt) {
    this->context.update(dt);
    this->widgets.update(dt);
}

void PauseMenu::renderMenu(RenderTarget *target) const {
    target->draw(this->background);
    this->widgets.render(target);
}
   
void PauseMenu::onGuiEvent(int id, GUI::Events::Type event_id){
    switch(id) {
        case btn_resume_game:
            onResumeGame();
            break;
        case btn_exit:
            onExit();
            break;
    }
}

}};