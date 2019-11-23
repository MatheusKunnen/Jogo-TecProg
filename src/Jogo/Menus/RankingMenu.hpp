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
    void initBackground();
    // Const Matheus
    enum widgets_ids{btn_exit, txt_header, txt_board};
public:
    // Constructor & Destructor
    RankingMenu(StateManager* handler, ListaRanking& l_ranking);
    virtual ~RankingMenu();
    
    // Methods
    void update(const float& dt);
    void render(RenderTarget* target);
    void onGuiEvent(int id, GUI::Events::Type event_id);
    void onExit();
};

}}


#endif /* RankingMenu_hpp */
