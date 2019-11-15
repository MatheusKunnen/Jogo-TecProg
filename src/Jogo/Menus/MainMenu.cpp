//
//  MainMenu.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "MainMenu.hpp"

namespace Game { namespace Menus{
  
// Constructor & Destructor
MainMenu::MainMenu(RenderWindow& window):
Menu(window)
{
    this->initMenu();
}
    
MainMenu::~MainMenu(){
    this->widgets.clear();
}


// Init Methods
void MainMenu::initMenu(){
    this->initFonts();
    this->initTextures();
    this->initWidgets();
    this->initBackground();
}

void MainMenu::initWidgets(){
    this->initButtons();
}

void MainMenu::initButtons(){
    // Inicia buttons com suas posicoes é tamanhos
    Vector2f btn_size = Vector2f(450.f, 100.f);
    Vector2f btn_pos = Vector2f(this->context.getRenderWindow()->getSize().x/2.f, this->context.getRenderWindow()->getSize().y / 4.f);
    
    this->widgets.add(btn_new_game, new Button(btn_new_game, context, *this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "New Game"));
    
    btn_pos.y = btn_pos.y + btn_size.y *1.2;
    this->widgets.add(btn_ranking, new Button(btn_ranking, context, *this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "Ranking"));
    
    btn_pos.y = btn_pos.y + btn_size.y *1.2;
    this->widgets.add(btn_config,  new Button(btn_config, context, *this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "Config"));
    
    btn_pos.y = btn_pos.y + btn_size.y *1.2;
    this->widgets.add(btn_exit, new Button(btn_exit, context ,*this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "EXIT"));
}


// Methods
void MainMenu::updateMenu(const float &dt) {
    this->context.update(dt);
    this->widgets.update(dt);
}

void MainMenu::renderMenu(RenderTarget *target) const {
    target->draw(this->background);
    this->widgets.render(target);    
}
   
void MainMenu::onGuiEvent(int id, GUI::Events::Type event_id){
    switch(id) {
        case btn_new_game:
            onOpenNewGame();
            break;
        case btn_ranking:
            onOpenRanking();
            break;
        case btn_config:
            onOpenConfig();
            break;
        case btn_exit:
            onExit();
            break;
    }
}

}};
