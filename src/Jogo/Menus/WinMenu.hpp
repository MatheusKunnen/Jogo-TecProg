//
//  WinMenu.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef WinMenu_hpp
#define WinMenu_hpp

#include "Menu.hpp"

namespace Game { namespace Menus {

class WinMenu : public Menu {
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
    WinMenu(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys);
    virtual ~WinMenu();
    
    // Methods
    void update(const float& dt);
    void render(RenderTarget* target);
    void onGuiEvent(int id, GUI::Events::Type event_id);
    void onExit();
};

}}

#endif /* WinMenu_hpp */
