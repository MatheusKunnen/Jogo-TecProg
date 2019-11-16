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
void TextView::update(){
    sf::Event event;
    while(this->context.getRenderWindow()->pollEvent(event)){
        if(event.type == sf::Event::TextEntered){
            if (event.text.unicode < 128){
                cout << static_cast<char>(event.text.unicode) << endl;
            }
            
        }
    }
}

void TextView::render(RenderTarget* target){
  if (target == nullptr)
      target = this->context.getRenderWindow();
    target->draw(this->background);
    target->draw(this->text);
}

}
