//
//  ConfigMenu.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef ConfigMenu_hpp
#define ConfigMenu_hpp

#include "Menu.hpp"

namespace Game { namespace Menus {

class ConfigMenu : public Menu {
private:
    // Init methods
    void initMenu();
    void initWidgets();
    void initButtons();
    
    // Const
    enum used_buttons{btn_exit};
public:
    // Constructor & Destructor
    ConfigMenu(RenderWindow& window);
    virtual ~ConfigMenu();
    // Methods
    void updateMenu(const float& dt);
    void renderMenu(RenderTarget* target) const;
    void onGuiEvent(int id, GUI::Events::Type event_id);
    virtual void onExit() = 0;
};

}}

#endif /* ConfigMenu_hpp */
