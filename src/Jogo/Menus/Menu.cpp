//
//  Menu.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Menu.hpp"
#include "../States/StateManager.hpp"

namespace Game { namespace Menus{

Menu::Menu(StateManager* handler, States::states_id id):
State(handler, id),
context(*GerenciadorGrafico::getInstance()->getRenderWindow()),
widgets()
{
    this->background.setSize(sf::Vector2f(GerenciadorGrafico::getInstance()->getRenderWindow()->getSize()));
    this->background.setFillColor(sf::Color::White);
}

Menu::~Menu(){
    
}

// Init Methods
void Menu::initFonts(){
    // Carrega fonte a ser utilizada
    try {
        this->fonts.load(Resources::Fonts::font_01, this->fonts.getFilename(Resources::Fonts::font_01));
    } catch (std::exception e){
        cerr << "Menu::initFonts: Error loading fonts" << endl;
    }
}

void Menu::initTextures(){
    // Carrega texturas a serem utilizadas
    try {
        this->textures.load(Resources::Textures::bg_menu, TextureHolder::getFilename(Resources::Textures::bg_menu));
    } catch (std::exception e) {
        cerr << "Menu::initTextures: ERROR Loading textutes: " << endl;
    }
}

void Menu::initBackground(){
    this->background.setTexture(&this->textures.get(Resources::Textures::bg_menu));
}

}}
