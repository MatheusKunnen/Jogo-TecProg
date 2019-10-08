//
//  State.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include "base_includes.hpp"
#include "Entidade.hpp"

namespace Game { namespace States {

class State {
protected:
    // Attributes
    RenderWindow*       render_window;
    vector<Texture>     textures;
    Vector2i mouse_pos_screen;
    Vector2i mouse_pos_window;
    Vector2f mouse_pos_view;
    
    map<string, int>* supported_keys;
    map<string, int> used_keys;
    
    bool quit;
    
    // Methods
    virtual void initValidKeys() = 0;
public:
    // Constructor & Destructor
    State(RenderWindow* render_window, map<string, int>* supported_keys);
    virtual ~State();
    // Methods
    virtual void checkQuit();
    virtual void endState() = 0;
    virtual void updateMousePos();
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(RenderTarget* target = nullptr) = 0;
    // Setters & Getters
    void setRenderWindow(RenderWindow* render_window);
    const RenderWindow* getRenderWindow() const;
    const bool& isQuitting() const;
};

}};

#endif /* State_hpp */
