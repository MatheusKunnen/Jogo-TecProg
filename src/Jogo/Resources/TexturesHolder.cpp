//
//  TexturesHolder.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/6/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "TexturesHolder.hpp"

namespace Game { namespace Textures {

// Const map init
const string TextureHolder::DEFAULT_NOT_FILE("Resources/img/texttures/no_texture.png");

map<ID, string> TextureHolder::default_filenames = {
                                                {background_01,"Resources/img/textures/backgrounds/bg-main_menu.jpeg"},
                                                {background_02,"Resources/img/textures/sprites/player/male_player.png"},
                                                {male_player,"Resources/img/textures/sprites/player/male_player.png"} };
// Constructor & Destructor
TextureHolder::TextureHolder():
ResourceHolder<sf::Texture, Textures::ID>()
{
    
}

TextureHolder::~TextureHolder(){
    
}

const string& TextureHolder::getFilename(ID id) {
    try {
        auto file = TextureHolder::default_filenames.find(id);
        if (file == TextureHolder::default_filenames.end())
            throw ("FATAL ERROR: TextureHolder::getFilename(ID id): default filename not defined.");
        return file->second;
    } catch (std::exception e) {
        cerr << e.what() << endl;
    }
    return DEFAULT_NOT_FILE;
}

}};
