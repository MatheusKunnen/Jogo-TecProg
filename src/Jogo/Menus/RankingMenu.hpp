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
#include "../TADs/ListaRanking.hpp"

namespace Game { namespace Menus {

using TADs::ListaRanking;

class RankingMenu : public Menu {
private:
    // Attributes
    ListaRanking&       l_ranking;
    
    // Init methods
    void initMenu();
    void initWidgets();
    void initButtons();
    void initTextViews();
    void initRankingBoard();
    
    // Const Matheus
    enum widgets_ids{btn_exit, txt_header, txt_board};
public:
    // Constructor & Destructor
    RankingMenu(RenderWindow& window, ListaRanking& l_ranking);
    virtual ~RankingMenu();
    // Methods
    void updateMenu(const float& dt);
    void renderMenu(RenderTarget* target) const;
    void onGuiEvent(int id, GUI::Events::Type event_id);
    virtual void onExit() = 0;
};

}}


#endif /* RankingMenu_hpp */
