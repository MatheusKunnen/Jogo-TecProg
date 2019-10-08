//
//  MainMenuState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef MainMenuState_hpp
#define MainMenuState_hpp

#include "base_includes.hpp"
#include "Button.hpp"
#include "State.hpp"

namespace Game { namespace States {

// GUI usings
using GUI::Button;

class MainMenuState : public State{
private:
    // Attributes
    sf::RectangleShape background;
    sf::Font font;
    
    Button* options_button;
    
    // Init methods
    void initValidKeys();
    void initFonts();
    void initButtons();
public:
    // Contructor & Destructor
    MainMenuState(RenderWindow* render_window, map<string, int>* supported_keys);
    ~MainMenuState();
    // Methods
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target);
};

}};

#endif /* MainMenuState_hpp */
