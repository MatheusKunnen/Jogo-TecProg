//
//  Widget.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/4/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Widget_hpp
#define Widget_hpp

#include "Context.hpp"
#include "EventHandler.hpp"

namespace GUI {

class Widget {
protected:
    // Attributes
    const int           id;
    const Context&      context;
    EventHandler&       handler;
    RectangleShape      background;
    Texture             bg_texture;
    Font                font;
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
    
    // Methods
    void updateTextPos();
public:
    // Constructor & Destructor
    Widget(const int& id, Context& context, EventHandler& handler, const Font& font, const Vector2f& size, const Vector2f& pos);
    virtual ~Widget();
    // Methods
    virtual void update() = 0;
    virtual void render(RenderTarget* target = nullptr) = 0;
    // Getters & Setters
    const bool isPressed() const;
    const bool isHovered() const;
    const bool isEnabled() const;
    void setText(const string& text, const bool& update = true);
    void setTextColor(const Color& color);
    void setEnabled(const bool& enabled);
    // Const
    enum State{disabled = -1, enabled = 0, hovered, pressed};
};

}

#endif /* Widget_hpp */
