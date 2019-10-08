//
//  TexturesHolder.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/6/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef TexturesHolder_hpp
#define TexturesHolder_hpp

#include "base_includes.hpp"
#include "ResourcesHolder.hpp"

#include <SFML/Graphics.hpp>
namespace Game { namespace Textures{

enum ID {Land01, Land02, MalePlayer };

class TextureHolder : public ResourceHolder<sf::Texture, Textures::ID>{

};

};};
#endif /* TexturesHolder_hpp */
