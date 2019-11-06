//
//  Menu.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Menu.hpp"

namespace Game { namespace Menus{

Menu::Menu(RenderWindow& window):
context(window),
buttons()
{
    this->background.setSize(sf::Vector2f(window.getSize()));
    this->background.setFillColor(sf::Color::White);
}

Menu::~Menu(){
    
}

}}
