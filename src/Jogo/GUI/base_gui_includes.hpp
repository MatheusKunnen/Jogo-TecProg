//
//  base_gui_includes.h
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef base_gui_includes_h
#define base_gui_includes_h

#include <iostream>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>

namespace GUI {

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::map;

using std::runtime_error;

// SFML includes
using sf::RenderWindow;
using sf::RenderTarget;
using sf::RectangleShape;
using sf::Texture;
using sf::Font;
using sf::Text;
using sf::Color;
using sf::Vector2f;
using sf::Vector2i;

static const bool DEBUG_MODE = true;

}
#endif /* base_gui_includes_h */
