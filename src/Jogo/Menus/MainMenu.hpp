//
//  MainMenu.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef MainMenu_hpp
#define MainMenu_hpp

#include "Menu.hpp"

namespace Game { namespace Menus {

class MainMenu : public Menu {
private:
    // Init methods
    void initMenu();
    void initWidgets();
    void initButtons();

    // Const
    enum widgets_ids{btn_new_game, btn_ranking, btn_config, btn_exit};
    
public:
    // Constructor & Destructor
    MainMenu(StateManager* handler);
    virtual ~MainMenu();
    
    // Methods
    void update(const float& dt);
    void render(RenderTarget* target= nullptr);
    void onGuiEvent(int id, GUI::Events::Type event_id);
    void onOpenNewGame();
    void onOpenRanking();
    void onOpenConfig();
    void onExit();
};

}}

#endif /* MainMenu_hpp */
