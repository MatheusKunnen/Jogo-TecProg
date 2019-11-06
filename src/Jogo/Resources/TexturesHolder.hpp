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
#include "ResourcesHolder.hpp"

namespace Game { namespace Resources{
namespace Textures {
    enum ID {background_01, background_02, male_player};
}
class TextureHolder : public ResourceHolder<sf::Texture, Textures::ID>{
private:
    // Attributes
    static map<Textures::ID, string> default_filenames;
    // Const
    static const string DEFAULT_NOT_FILE;
public:
    TextureHolder();
    ~TextureHolder();
    // Methods
    static const string& getFilename(Textures::ID id);
    
};

};};
#endif /* TexturesHolder_hpp */
