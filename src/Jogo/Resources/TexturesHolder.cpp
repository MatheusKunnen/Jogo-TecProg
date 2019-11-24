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
                                                {Textures::bg_menu,"Resources/img/textures/backgrounds/bg_main_menu.png"},
                                                {Textures::bg_fase,"Resources/img/textures/backgrounds/bg_fase_a.png"},
                                                {Textures::bg_config,"Resources/img/textures/backgrounds/bg_config.png"},
                                                {Textures::bg_ranking,"Resources/img/textures/backgrounds/bg_ranking.png"},
                                                {Textures::bg_game,"Resources/img/textures/backgrounds/bg_game.png"},
                                                {Textures::bg_pause,"Resources/img/textures/backgrounds/bg_pause.png"},
                                                {Textures::jogador_a,"Resources/img/textures/sprites/player/player_a.png"},
                                                {Textures::jogador_b,"Resources/img/textures/sprites/player/player_b.png"},
                                                {Textures::narcotraficante,"Resources/img/textures/sprites/player/narcotraficante.png"},
                                                {Textures::desmatador,"Resources/img/textures/sprites/player/desmatador.png"},
                                                {Textures::narcotraficante_desmatador,"Resources/img/textures/sprites/player/narcotraficante_desmatador.png"},
                                                {Textures::planta_venenosa,"Resources/img/textures/sprites/obstaculos/planta_venenosa.png"},
                                                {Textures::pedra,"Resources/img/textures/sprites/obstaculos/pedra.png"},
                                                {Textures::espinhos,"Resources/img/textures/sprites/obstaculos/espinhos.png"},
                                                {Textures::projetil,"Resources/img/textures/sprites/obstaculos/projetil.png"}
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
