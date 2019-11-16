//
//  RankingMenu.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef RankingMenu_hpp
#define RankingMenu_hpp

#include "Menu.hpp"

namespace Game { namespace Menus {

class RankingMenu : public Menu {
private:
    // Init methods
    void initMenu();
    void initWidgets();
    void initButtons();
    
    // Const
    enum widgets_ids{btn_exit};
public:
    // Constructor & Destructor
    RankingMenu(RenderWindow& window);
    virtual ~RankingMenu();
    // Methods
    void updateMenu(const float& dt);
    void renderMenu(RenderTarget* target) const;
    void onGuiEvent(int id, GUI::Events::Type event_id);
    virtual void onExit() = 0;
};

}}


#endif /* RankingMenu_hpp */
