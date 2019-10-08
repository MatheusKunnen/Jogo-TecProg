//
//  Button.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Button.hpp"
namespace GUI {

// Const
const Color Button::DEFAULT_DISABLED_COLOR(255, 255, 255, 150);
const Color Button::DEFAULT_NORMAL_COLOR(44, 84, 51, 150);
const Color Button::DEFAULT_HOVER_COLOR(44, 84, 51, 200);
const Color Button::DEFAULT_PRESSED_COLOR(44, 84, 51, 150);
const Color Button::DEFAULT_TEXT_COLOR(255, 255, 255, 255);

// Constructor & Destructor
Button::Button(const Vector2f& back_size, const Vector2f& position, Font* font, const string& text,
const Color& normal_color, const Color& hover_color, const Color& pressed_color):
background(back_size),
font(font),
text(text, *this->font),
disabled_color(DEFAULT_DISABLED_COLOR),
normal_color(normal_color),
hover_color(hover_color),
pressed_color(pressed_color),
text_color(Button::DEFAULT_TEXT_COLOR),
state(enabled)
{
    this->background.setPosition(position.x - back_size.x / 2.f, position.y - back_size.y / 2.f);
    this->text.setFillColor(this->text_color);
    this->text.setCharacterSize(64);
    
    this->text.setPosition(this->background.getPosition().x
                           + this->background.getGlobalBounds().width / 2.f
                           - this->text.getGlobalBounds().width/2.f,
                           this->background.getPosition().y
                           + this->background.getGlobalBounds().height / 2.f
                           - this->text.getGlobalBounds().height/2.f - 20.f); 
    
    this->text.setStyle(sf::Text::Style::Bold);
}

Button::~Button(){
    
}

// Methods
void Button::update(const Vector2f& mouse_pos){
    if(this->state == disabled)
        return;
    
    if(this->background.getGlobalBounds().contains(mouse_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            this->state = pressed;
            this->background.setFillColor(this->pressed_color);
        } else {
            this->state = hovered;
            this->background.setFillColor(this->hover_color);
        }
        this->text.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
    } else {
        this->state = enabled;
        this->background.setFillColor(this->normal_color);
        this->text.setStyle(sf::Text::Style::Bold);
    }
}

void Button::render(RenderTarget* target){
    target->draw(this->background);
    if (this->state != disabled)
        target->draw(this->text);
}

// Getters & Setters
const bool Button::isPressed() const {
    return this->state == pressed;
}

const bool Button::isHovered() const {
    return this->state == hovered;
}

const bool Button::isEnabled() const {
    return this->state != disabled;
}

void Button::setEnabled(const bool& enabled) {
    if (enabled){
        state = enabled;
        this->background.setFillColor(this->normal_color);
    } else {
        state = disabled;
        this->background.setFillColor(this->normal_color); // Criar disabled color
    }
}
};
