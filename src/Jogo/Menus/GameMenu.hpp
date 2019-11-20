//
//  GameMenu.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef GameMenu_hpp
#define GameMenu_hpp

#include "Menu.hpp"

namespace Game { namespace Menus {

class GameMenu : public Menu {
private:
    // Init methods
    void initMenu();
    void initWidgets();
    void initButtons();
    
    // Const
    enum widgets_ids{btn_start_floresta, btn_start_montanha, btn_exit};
public:
    // Constructor & Destructor
    GameMenu(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys);
    virtual ~GameMenu();
    
    // Methods
    void update(const float& dt);
    void render(RenderTarget* target);
    void onGuiEvent(int id, GUI::Events::Type event_id);
    void onStartFaseFloresta();
    void onStartFaseMontanha();
    void onExit();
};

}}

#endif /* GameMenu_hpp */
