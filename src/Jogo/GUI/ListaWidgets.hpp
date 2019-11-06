//
//  ListaWidgets.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/6/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef ListaWidgets_hpp
#define ListaWidgets_hpp

#include "Widget.hpp"

namespace GUI {

class ListaWidgets {
private:
    // Attributes
    map<int, Widget*> widgets;
public:
    // Constructor & Destructor
    ListaWidgets();
    ~ListaWidgets();
    // Methods
    void update(const float& dt);
    void render(RenderTarget* target) const;
    void add(const int& id, Widget& widget);
    void add(const int& id, Widget* widget);
    Widget* get(const int& id) const;
    void clear();
    // Operators
    Widget* operator[](const int& id);

};

}

#endif /* ListaWidgets_hpp */
