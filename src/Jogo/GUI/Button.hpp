//
//  Button.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include "Widget.hpp"
namespace GUI {

class Button : public Widget{
private:
    
public: 
    Button(const int& id, Context& context, const Vector2f& back_size, const Vector2f& position, Font& font, const string& text = "");
    ~Button();
    
    // Methods
    void update();
    void render(RenderTarget* target);

};

}
#endif /* Button_hpp */
