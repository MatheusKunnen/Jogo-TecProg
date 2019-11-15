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
    enum used_buttons{btn_resume_game, btn_exit};
public:
    // Constructor & Destructor
    PauseMenu(RenderWindow& window);
    virtual ~PauseMenu();
    // Methods
    void updateMenu(const float& dt);
    void renderMenu(RenderTarget* target) const;
    void onGuiEvent(int id, GUI::Events::Type event_id);
    virtual void onResumeGame() = 0;
    virtual void onExit() = 0;
};

}}

#endif /* PauseMenu_hpp */
