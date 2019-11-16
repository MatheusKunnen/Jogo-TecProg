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
    GameMenu(RenderWindow& window);
    virtual ~GameMenu();
    // Methods
    void updateMenu(const float& dt);
    void renderMenu(RenderTarget* target) const;
    void onGuiEvent(int id, GUI::Events::Type event_id);
    virtual void onStartFaseFloresta() = 0;
    virtual void onStartFaseMontanha() = 0;
    virtual void onExit() = 0;
};

}}

#endif /* GameMenu_hpp */
