//
//  FontHolder.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "FontHolder.hpp"
namespace Game { namespace Resources {

// Const map init
const string FontHolder::DEFAULT_NOT_FILE("Resources/img/texttures/no_texture.png");

map<Fonts::ID, string> FontHolder::default_filenames = {
                                                {Fonts::font_01,"Resources/fonts/font-01.otf"}};
// Constructor & Destructor
FontHolder::FontHolder():
ResourceHolder<sf::Font, Fonts::ID>()
{
    
}

FontHolder::~FontHolder(){
    
}

const string& FontHolder::getFilename(Fonts::ID id) {
    try {
        auto file = FontHolder::default_filenames.find(id);
        if (file == FontHolder::default_filenames.end())
            throw ("FATAL ERROR: FontHolder::getFilename(ID id): default filename not defined.");
        return file->second;
    } catch (std::exception e) {
        cerr << e.what() << endl;
    }
    return DEFAULT_NOT_FILE;
}

}};
