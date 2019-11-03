//
//  MainMenuState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef MainMenuState_hpp
#define MainMenuState_hpp

#include "State.hpp"
#include "../GUI/Button.hpp"

namespace Game { namespace States {

// GUI usings
using GUI::Button;

class MainMenuState : public State{
private:
    // Attributes        
    sf::RectangleShape      background;
    sf::Font                font; // Trocar para font holder
    
    map<int, Button*>       buttons; // Trocar para lista de buttons
    
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
    MainMenuState(StateHandler* handler, MediaEngine* g_grafico, map<string, int>* supported_keys);
    ~MainMenuState();
    // Methods
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target);
};

}};

#endif /* MainMenuState_hpp */
