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
    MainMenu(RenderWindow& window);
    virtual ~MainMenu();
    // Methods
    void updateMenu(const float& dt);
    void renderMenu(RenderTarget* target) const;
    void onGuiEvent(int id, GUI::Events::Type event_id);
    virtual void onOpenNewGame() = 0;
    virtual void onOpenRanking() = 0;
    virtual void onOpenConfig() = 0;
    virtual void onExit() = 0;
};

}}

#endif /* MainMenu_hpp */
