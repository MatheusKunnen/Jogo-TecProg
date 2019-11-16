//
//  FailedMenu.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef FailedMenu_hpp
#define FailedMenu_hpp

#include "Menu.hpp"

namespace Game { namespace Menus {

class FailedMenu : public Menu {
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
    FailedMenu(RenderWindow& window);
    virtual ~FailedMenu();
    // Methods
    void updateMenu(const float& dt);
    void renderMenu(RenderTarget* target) const;
    void onGuiEvent(int id, GUI::Events::Type event_id);
    virtual void onExit() = 0;
};

}}


#endif /* FailedMenu_hpp */
