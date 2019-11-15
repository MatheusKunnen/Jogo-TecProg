//
//  RankingMenu.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "RankingMenu.hpp"

namespace Game { namespace Menus{
  
// Constructor & Destructor
RankingMenu::RankingMenu(RenderWindow& window):
Menu(window)
{
    this->initMenu();
}
    
RankingMenu::~RankingMenu(){
    this->widgets.clear();
}

// Init Methods
void RankingMenu::initMenu(){
    this->initFonts();
    this->initTextures();
    this->initWidgets();
    this->initBackground();
}

void RankingMenu::initWidgets(){
    this->initButtons();
}

void RankingMenu::initButtons(){
    // Inicia buttons com suas posicoes é tamanhos
    Vector2f btn_size = Vector2f(450.f, 100.f);
    Vector2f btn_pos = Vector2f(this->context.getRenderWindow()->getSize().x*0.8, this->context.getRenderWindow()->getSize().y*.8);
    
    //btn_pos.y = btn_pos.y + btn_size.y *1.2;
    this->widgets.add(btn_exit, new Button(btn_exit, context ,*this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "VOLTAR"));
}

// Methods
void RankingMenu::updateMenu(const float &dt) {
    this->context.update(dt);
    this->widgets.update(dt);
}

void RankingMenu::renderMenu(RenderTarget *target) const {
    target->draw(this->background);
    this->widgets.render(target);
}
   
void RankingMenu::onGuiEvent(int id, GUI::Events::Type event_id){
    switch(id) {
        case btn_exit:
            onExit();
            break;
    }
}

}};
