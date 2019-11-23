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
RankingMenu::RankingMenu(StateManager* handler, ListaRanking& l_ranking):
Menu(handler, States::states_id::ranking_menu),
l_ranking(l_ranking)
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
    this->initRankingBoard();
}

void RankingMenu::initWidgets(){
    this->initButtons();
    this->initTextViews();
}

void RankingMenu::initButtons(){
    // Inicia buttons com suas posicoes é tamanhos
    Vector2f btn_size = Vector2f(450.f, 100.f);
    Vector2f btn_pos = Vector2f(this->context.getRenderWindow()->getSize().x*0.8, this->context.getRenderWindow()->getSize().y*.8);
    
    //btn_pos.y = btn_pos.y + btn_size.y *1.2;
    this->widgets.add(btn_exit, new Button(btn_exit, context ,*this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "VOLTAR"));
}

void RankingMenu::initTextViews(){
    Vector2f size = Vector2f(450.f, 100.f);
    Vector2f pos = Vector2f(this->context.getRenderWindow()->getSize().x*0.5, this->context.getRenderWindow()->getSize().y*.1);
    this->widgets.add(txt_header, new TextView(txt_header, context ,*this, size, pos, this->fonts.get(Resources::Fonts::font_01), "N˚ | Jogador | Pontos"));
    pos.y = pos.y + size.y *1.2;
    this->widgets.add(txt_board, new TextView(txt_board, context ,*this, size, pos, this->fonts.get(Resources::Fonts::font_01), "--\t\t--\t\t--"));
}

void RankingMenu::initBackground() {
    this->textures.load(Resources::Textures::bg_ranking, this->textures.getFilename(Resources::Textures::bg_ranking));
    this->background.setTexture(&this->textures.get(Resources::Textures::bg_ranking));
}

void RankingMenu::initRankingBoard(){
    this->widgets[txt_board]->setText(this->l_ranking.dump(), false);
}

// Methods
void RankingMenu::update(const float &dt) {
    this->context.update(dt);
    this->widgets.update(dt);
}

void RankingMenu::render(RenderTarget *target) {
    if (!target)
        target = GerenciadorGrafico::getInstance()->getRenderWindow();
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

void RankingMenu::onExit() {
    this->quit = true;
}

}};
