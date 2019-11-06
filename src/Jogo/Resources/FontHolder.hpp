//
//  FontHolder.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef FontHolder_hpp
#define FontHolder_hpp
#include "ResourcesHolder.hpp"
namespace Game { namespace Resources {

namespace Fonts{
    enum ID {font_01};
};


class FontHolder : public ResourceHolder<sf::Font, Fonts::ID>{
private:
    static map<Fonts::ID, string> default_filenames;
    // Const
    static const string DEFAULT_NOT_FILE;
public:
    FontHolder();
    ~FontHolder();
    // Methods
    static const string& getFilename(Fonts::ID id);
    
};

}};

#endif /* FontHolder_hpp */
