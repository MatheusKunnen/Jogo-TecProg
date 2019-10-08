//
//  Button.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include "base_gui_includes.hpp"
#include <SFML/Graphics.hpp>

using sf::RenderTarget;
using sf::RectangleShape;
using sf::Font;
using sf::Text;
using sf::Color;
using sf::Vector2f;

namespace GUI {

class Button {
private:
    //Attributes
    RectangleShape      background;
    Font*               font;
    Text                text;
    
    Color               normal_color;
    Color               hover_color;
    Color               pressed_color;
    
    int8_t              state;
public: 
    Button(const Vector2f& back_size, const Vector2f& position, Font* font, const string& text,
           const Color& normal_color = sf::Color::Red, const Color& hover_color = sf::Color::Blue, const Color& pressed_color = sf::Color::Yellow);
    ~Button();
    
    // Methods
    void update(const Vector2f& mouse_pos);
    void render(RenderTarget* target);
    // Getters & Setters
    const bool isPressed() const;
    const bool isHovered() const;
    const bool isEnabled() const;
    void setEnabled(const bool& enabled);
    
    // Const
    enum State{disabled = -1, enabled = 0, hovered, pressed};
};

}
#endif /* Button_hpp */
