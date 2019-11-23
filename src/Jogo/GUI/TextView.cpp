//
//  TextView.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/6/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "TextView.hpp"

namespace GUI {
// Contructor & Destructor
TextView::TextView(const int& id, Context& context, EventHandler& handler, const Vector2f& size, const Vector2f& pos, Font& font, const string& text):
Widget(id, context, handler, font, size, pos){
    this->setText(text);
    this->background.setFillColor(sf::Color::Transparent);
}

TextView::~TextView(){
    
}

// Methods
void TextView::update() {
    
}

void TextView::render(RenderTarget* target){
  if (target == nullptr)
      target = this->context.getRenderWindow();
    target->draw(this->background);
    target->draw(this->text);
}

}
