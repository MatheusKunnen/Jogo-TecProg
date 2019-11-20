//
//  PauseMenu.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef PauseMenu_hpp
#define PauseMenu_hpp

#include "Menu.hpp"

namespace Game { namespace Menus {

class PauseMenu : public Menu {
private:
    // Init methods
    void initMenu();
    void initWidgets();
    void initButtons();
    
    // Const
    enum widgets_ids{btn_resume_game, btn_exit};
public:
    // Constructor & Destructor
    PauseMenu(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys);
    virtual ~PauseMenu();
    
    // Methods
    void update(const float& dt);
    void render(RenderTarget* target);
    void onGuiEvent(int id, GUI::Events::Type event_id);
    void onResumeGame();
    void onExit();
};

}}

#endif /* PauseMenu_hpp */
