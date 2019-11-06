//
//  Button.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Button.hpp"
namespace GUI {

// Constructor & Destructor
Button::Button(const int& id, Context& context, EventHandler& handler, const Vector2f& size, const Vector2f& pos, Font& font, const string& text):
Widget(id, context, handler, font, size, pos)
{
    this->setText(text);
}

Button::~Button(){
    
}

// Methods
void Button::update(){
    if(this->state == disabled)
        return;
    
    if(this->background.getGlobalBounds().contains(this->context.getMousePosView())){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            this->state = pressed;
            this->background.setFillColor(this->pressed_color);
            this->handler.onGuiEvent(this->id, Events::Type::CLICK);
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

};
