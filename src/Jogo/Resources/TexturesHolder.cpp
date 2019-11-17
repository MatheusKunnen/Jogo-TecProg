//
//  TexturesHolder.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/6/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "TexturesHolder.hpp"

namespace Game { namespace Resources {

// Const map init
const string TextureHolder::DEFAULT_NOT_FILE("Resources/img/texttures/no_texture.png");

map<Textures::ID, string> TextureHolder::default_filenames = {
                                                {Textures::bg_menu,"Resources/img/textures/backgrounds/bg-main_menu.jpeg"},
                                                {Textures::bg_fase,"Resources/img/textures/backgrounds/bg-main_menu.jpeg"},
                                                {Textures::jogador_a,"Resources/img/textures/sprites/player/player_a.png"},
                                                {Textures::jogador_b,"Resources/img/textures/sprites/player/player_b.png"},
                                                {Textures::narcotraficante,"Resources/img/textures/sprites/player/narcotraficante.png"},
                                                {Textures::desmatador,"Resources/img/textures/sprites/player/desmatador.png"},
                                                {Textures::narcotraficante_desmatador,"Resources/img/textures/sprites/player/narcotraficante_desmatador.png"},
                                                {Textures::planta_venenosa,"Resources/img/textures/obstaculos/planta_venenosa.png"},
                                                {Textures::pedra,"Resources/img/textures/sprites/obstasculos/pedra.png"},
                                                {Textures::spinhos,"Resources/img/textures/sprites/obstaculos/spinhos.png"}
};
// Constructor & Destructor
TextureHolder::TextureHolder():
ResourceHolder<sf::Texture, Textures::ID>()
{
    
}

TextureHolder::~TextureHolder(){
    
}

const string& TextureHolder::getFilename(Textures::ID id) {
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
