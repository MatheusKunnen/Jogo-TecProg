//
//  Context.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/4/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Context_hpp
#define Context_hpp

#include "base_gui_includes.hpp"

namespace GUI {

class Context {
private:
    Vector2i            mouse_pos_screen; // Trocar pela classe context
    Vector2i            mouse_pos_window;
    Vector2f            mouse_pos_view;
    
    RenderWindow*       window;
public:
    // Constructor & Destructor
    Context(RenderWindow& window);
    ~Context();
    // Methods
    void update(const float& dt);
    void updateMousePos();
    // Getters && Setters
    const Vector2f& getMousePosView() const;
};


}

#endif /* Context_hpp */
