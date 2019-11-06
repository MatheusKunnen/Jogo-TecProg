//
//  TextView.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/6/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef TextView_hpp
#define TextView_hpp

#include "Widget.hpp"

namespace GUI {

class TextView : public Widget{
public:
    // Constructor & Destructor
    TextView(const int& id, Context& context, EventHandler& handler, const Vector2f& size, const Vector2f& pos, Font& font, const string& text = "");
    ~TextView();
    // Methods
    void update();
    void render(RenderTarget* target = nullptr);
};

};

#endif /* TextView_hpp */
