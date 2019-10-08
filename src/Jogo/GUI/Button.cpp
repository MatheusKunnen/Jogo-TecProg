//
//  Button.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Button.hpp"
namespace GUI{
// Constructor & Destructor
Button::Button(const Vector2f& back_size, const Vector2f& position, Font* font, const string& text,
const Color& normal_color, const Color& hover_color, const Color& pressed_color):
background(back_size),
font(font),
text(text, *this->font),
normal_color(normal_color),
hover_color(hover_color),
pressed_color(pressed_color),
state(enabled)
{
    this->background.setPosition(position);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(12);
    
    this->text.setPosition(position.x / 2.f - this->text.getGlobalBounds().width,
                           position.y / 2.f - this->text.getGlobalBounds().height); // Mudar para funcao futuramente
}

Button::~Button(){
    
}

// Methods
void Button::update(const Vector2f& mouse_pos){
    if(this->state == disabled)
        return;
    
    if(this->background.getGlobalBounds().contains(mouse_pos)){
        this->state = (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) ? pressed : hovered;
        this->background.setFillColor((this->state == pressed) ? this->pressed_color : this->hover_color);
    } else{
        this->state = enabled;
        this->background.setFillColor(this->normal_color);
    }
}

void Button::render(RenderTarget* target){
    target->draw(this->background);
    if (this->state == enabled)
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
