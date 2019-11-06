//
//  Widget.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/4/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Widget.hpp"

namespace GUI {
// Const
const Color Widget::DEFAULT_DISABLED_COLOR(255, 255, 255, 150);
const Color Widget::DEFAULT_NORMAL_COLOR(44, 84, 51, 150);
const Color Widget::DEFAULT_HOVER_COLOR(44, 84, 51, 200);
const Color Widget::DEFAULT_PRESSED_COLOR(44, 84, 51, 150);
const Color Widget::DEFAULT_TEXT_COLOR(255, 255, 255, 255);

// Cosntructor & Destructor
Widget::Widget(const int& id, Context& context, EventHandler& handler, const Font& font, const Vector2f& size, const Vector2f& pos):
id(id),
context(context),
handler(handler),
background(size),
bg_texture(),
font(font),
text("", this->font),
disabled_color(Widget::DEFAULT_DISABLED_COLOR),
normal_color(Widget::DEFAULT_NORMAL_COLOR),
hover_color(Widget::DEFAULT_HOVER_COLOR),
pressed_color(Widget::DEFAULT_PRESSED_COLOR),
text_color(Widget::DEFAULT_TEXT_COLOR),
state(enabled)
{
    this->background.setPosition(pos.x - size.x / 2.f, pos.y - size.y / 2.f);
    this->text.setFillColor(this->text_color);
    this->text.setCharacterSize(64);
    
    updateTextPos();
    
    this->text.setStyle(sf::Text::Style::Bold);
    this->text.setStyle(sf::Text::Style::Bold);
}
Widget::~Widget(){

}

// Getters & Setters
const bool Widget::isPressed() const {
    return this->state == pressed;
}

const bool Widget::isHovered() const {
    return this->state == hovered;
}

const bool Widget::isEnabled() const {
    return this->state != disabled;
}

void Widget::setEnabled(const bool& enabled) {
    if (enabled){
        state = enabled;
        this->background.setFillColor(this->normal_color);
    } else {
        state = disabled;
        this->background.setFillColor(this->disabled_color);
    }
}

void Widget::setText(const string& text){
    this->text.setString(text);
    this->updateTextPos();
}

// Methods
void Widget::updateTextPos(){
    this->text.setPosition(this->background.getPosition().x
    + this->background.getGlobalBounds().width / 2.f
    - this->text.getGlobalBounds().width/2.f,
    this->background.getPosition().y
    + this->background.getGlobalBounds().height / 2.f
    - this->text.getGlobalBounds().height/2.f - 25.f);
}
}
