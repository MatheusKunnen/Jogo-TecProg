//
//  TexturesHolder.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/6/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef TexturesHolder_hpp
#define TexturesHolder_hpp

#include "../base_includes.hpp"
#include "../Resources/ResourcesHolder.hpp"

#include <SFML/Graphics.hpp>
namespace Game { namespace Textures{

enum ID {background_01, background_02, male_player};

class TextureHolder : public ResourceHolder<sf::Texture, Textures::ID>{
private:
    /*struct A {
        static map<ID, string> create_map() {
              map<ID, string> m;
              m[background_01] = "Resources/img/texture/sprites/player/male_player.png";
              m[background_02] = "Resources/img/texture/sprites/player/male_player.png";
              m[male_player] = "Resources/img/texture/sprites/player/male_player.png";
                return m;
        }
        static const map<ID, string> myMap;
    };
    // Attributes
    const map<ID, string> myMap =  A::create_map();*/
    static map<ID, string> default_filenames;
    // Const
    static const string DEFAULT_NOT_FILE;
public:
    TextureHolder();
    ~TextureHolder();
    // Methods
    static const string& getFilename(ID id);
    
};

};};
#endif /* TexturesHolder_hpp */
