//
//  ConfigMenu.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "ConfigMenu.hpp"

namespace Game { namespace Menus{

// Constructor & Destructor
ConfigMenu::ConfigMenu(RenderWindow& window, ParametrosJogo* parametros_jogo):
Menu(window),
parametros_jogo(nullptr)
{
    this->setParametrosJogo(parametros_jogo);
    this->initMenu();
}

ConfigMenu::~ConfigMenu(){
    this->widgets.clear();
}


// Init Methods
void ConfigMenu::initMenu(){
    this->initFonts();
    this->initTextures();
    this->initWidgets();
    this->initBackground();
}

void ConfigMenu::initWidgets(){
    this->initButtons();
    this->initTextViews();
}

void ConfigMenu::initButtons(){
    // Inicia buttons com suas posicoes e tamanhos
    // Posição base dos buttons
    Vector2f btn_size = Vector2f(450.f, 100.f);
    Vector2f btn_pos = Vector2f(this->context.getRenderWindow()->getSize().x*0.5  - btn_size.x/2 - 25, this->context.getRenderWindow()->getSize().y*.3);
    // Button opção de 1 jogador
    this->widgets.add(btn_single_player, new Button(btn_single_player, context ,*this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "1 JOGADOR"));
    // Button opção de 2 jogadores
    btn_pos.x += btn_size.x + 50;
    this->widgets.add(btn_dual_player, new Button(btn_dual_player, context ,*this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "2 JOGADORES"));
    // Posição button sair
    Vector2f btn_exit_pos =
    Vector2f(this->context.getRenderWindow()->getSize().x*0.8, this->context.getRenderWindow()->getSize().y*.8);
    // Button voltar
    this->widgets.add(btn_exit, new Button(btn_exit, context ,*this, btn_size, btn_exit_pos, this->fonts.get(Resources::Fonts::font_01), "VOLTAR"));
    // Button Atualizar nome jogador
    btn_pos.x -= btn_size.x/2 + 25;
    btn_pos.y = btn_pos.y + btn_size.y *1.2;
    btn_size.x = 950;
    this->widgets.add(btn_update_p_name, new Button(btn_update_p_name, context ,*this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "Atualizar Nome"));
}

void ConfigMenu::initTextViews() {
    Vector2f btn_size = Vector2f(950.f, 100.f);
    Vector2f btn_pos = Vector2f(this->context.getRenderWindow()->getSize().x*0.5, this->context.getRenderWindow()->getSize().y*.7);
    TextView* txt = new TextView(txt_player_name, context ,*this, btn_size, btn_pos, this->fonts.get(Resources::Fonts::font_01), "Jogador: " + this->parametros_jogo->getPlayerName());
    
    this->widgets.add(txt_player_name, txt);
}


// Methods
void ConfigMenu::updateMenu(const float &dt) {
    this->context.update(dt);
    this->widgets.update(dt);
}

void ConfigMenu::renderMenu(RenderTarget *target) const {
    target->draw(this->background);
    this->widgets.render(target);
}

void ConfigMenu::onGuiEvent(int id, GUI::Events::Type event_id){
    switch(id) {
        case btn_exit:
            this->parametros_jogo->saveToFile();
            onExit();
            break;
        case btn_single_player:
            this->parametros_jogo->setDualPlayer(false);
            break;
        case btn_dual_player:
            this->parametros_jogo->setDualPlayer(true);
            break;
        case btn_update_p_name:
            this->onUpdatePlayerName();
            break;
    }
}

void ConfigMenu::onUpdatePlayerName() {
    if (sf::Clipboard::getString() != ""){
        this->parametros_jogo->setPlayerName(sf::Clipboard::getString());
        this->widgets[txt_player_name]->setText("Jogador: " + this->parametros_jogo->getPlayerName());
    }
}

// Getters & Setters
void ConfigMenu::setParametrosJogo(ParametrosJogo *parametros_jogo) {
    if (parametros_jogo == nullptr)
        throw runtime_error("ERROR: ConfigMenu::setParametrosJogo: NULLPTR as argument \n");
    this->parametros_jogo = parametros_jogo;
}

}};
