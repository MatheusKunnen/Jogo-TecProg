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
using sf::Texture;
using sf::Font;
using sf::Text;
using sf::Color;
using sf::Vector2f;

namespace GUI {

class Button {
private:
    //Attributes
    RectangleShape      background;
    Texture             bg_texture;
    Font*               font;
    Text                text;
    
    Color               disabled_color;
    Color               normal_color;
    Color               hover_color;
    Color               pressed_color;
    Color               text_color;
    
    int8_t              state;
    
    // Consts
    const static Color DEFAULT_DISABLED_COLOR;
    const static Color DEFAULT_NORMAL_COLOR;
    const static Color DEFAULT_HOVER_COLOR;
    const static Color DEFAULT_PRESSED_COLOR;
    const static Color DEFAULT_TEXT_COLOR;
public: 
    Button(const Vector2f& back_size, const Vector2f& position, Font* font, const string& text,
           const Color& normal_color = Button::DEFAULT_NORMAL_COLOR, const Color& hover_color = Button::DEFAULT_HOVER_COLOR, const Color& pressed_color = Button::DEFAULT_PRESSED_COLOR);
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
