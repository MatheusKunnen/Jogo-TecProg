//
//  MainMenuState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef MainMenuState_hpp
#define MainMenuState_hpp

#include "../base_includes.hpp"
#include "../GUI/Button.hpp"
#include "GameState.hpp"

namespace Game { namespace States {

// GUI usings
using GUI::Button;

class MainMenuState : public State{
private:
    // Attributes        
    sf::RectangleShape      background;
    sf::Font                font;
    
    map<int, Button*>       buttons;
    
    // Init methods
    void initValidKeys();
    void initTextures();
    void initFonts();
    void initBackground();
    void initButtons();
    
    // Const
    enum used_buttons{btn_new_game, btn_config, btn_exit};
public:
    // Contructor & Destructor
    MainMenuState(RenderWindow* render_window, map<string, int>* supported_keys, stack<State*>* states_stack);
    ~MainMenuState();
    // Methods
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target);
};

}};

#endif /* MainMenuState_hpp */
