//
//  EndGameMenu.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/19/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef EndGameMenu_hpp
#define EndGameMenu_hpp

#include "Menu.hpp"

namespace Game { namespace Menus {

class EndGameMenu : public Menu {
private:
    // Init methods
    void initMenu();
    void initWidgets();
    void initButtons();
    void initTextViews();
    
    // Const
    enum widgets_ids{btn_exit, txt_01};
    
public:
    // Constructor & Destructor
    EndGameMenu(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys, States::states_id id, const bool& win);
    virtual ~EndGameMenu();
    
    // Methods
    void update(const float& dt);
    void render(RenderTarget* target);
    void onGuiEvent(int id, GUI::Events::Type event_id);
    void onExit();
};

}}

#endif /* EndGameMenu_hpp */
