//
//  MediaEngine.hpp
//  SFML-Test
//
//  Created by Matheus Kunnen Ledesma on 10/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef MediaEngine_hpp
#define MediaEngine_hpp

#include "base_includes.h"

#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::RenderTarget;
using sf::Event;

namespace Jogo {

class MediaEngine{
private:
    static MediaEngine* main_instance;
public:
    MediaEngine();
    ~MediaEngine();
    static MediaEngine* getInstance();
};

}
#endif /* MediaEngine_hpp */
