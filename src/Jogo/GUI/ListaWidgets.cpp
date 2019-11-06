//
//  ListaWidgets.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/6/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "ListaWidgets.hpp"

namespace GUI {
ListaWidgets::ListaWidgets():
widgets()
{
    
}

ListaWidgets::~ListaWidgets(){
    this->clear();
}

// Methods
void ListaWidgets::update(const float &dt){
    for(auto widget : this->widgets)
        widget.second->update();
}

void ListaWidgets::render(RenderTarget *target) const {
    for(auto widget : this->widgets)
        widget.second->render(target);
}

void ListaWidgets::add(const int& id, Widget &widget){
    this->add(id, &widget);
}
void ListaWidgets::add(const int &id, Widget *widget){
    this->widgets[id] = widget;
}

Widget* ListaWidgets::get(const int &id) const {
    return this->widgets.at(id);
}

void ListaWidgets::clear(){
    for (auto widget: widgets)
        delete widget.second;
    widgets.clear();
}

// Operators
Widget* ListaWidgets::operator[](const int &id){
    return this->get(id);
}

}
