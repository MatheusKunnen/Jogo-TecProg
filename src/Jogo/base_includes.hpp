//
//  Header.h
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Base_includes_h
#define Base_includes_h

#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>

#include <SFML/Graphics.hpp>

// SFML usings
using sf::RenderWindow;
using sf::RenderTarget;
using sf::Texture;
using sf::Sprite;
using sf::Vector2i;
using sf::Vector2f;

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;

using std::unique_ptr;
using std::move;

using std::map;
using std::make_pair;

using std::stack;
using std::vector;

using std::runtime_error;


static const bool DEBUG_MODE = true;
static const string FONT_01_DIR = "Resources/fonts/font-01.otf"; // Crear clase FontHolder
#endif /* Base_includes */
