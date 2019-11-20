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
#include "../Parametros/ParametrosJogo.hpp"

namespace Game { namespace Menus {

using Parametros::ParametrosJogo;

class ConfigMenu : public Menu {
private:
    // Attributes
    ParametrosJogo*     parametros_jogo;
    
    // Init methods
    void initMenu();
    void initWidgets();
    void initButtons();
    void initTextViews();
    
    // Const
    enum widgets_ids{btn_exit, btn_single_player, btn_dual_player, btn_update_p_name, txt_player_name};
public:
    // Constructor & Destructor
    ConfigMenu(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys, ParametrosJogo* parametros_jogo);
    virtual ~ConfigMenu();
    
    // Methods
    void update(const float& dt);
    void render(RenderTarget* target);
    void onGuiEvent(int id, GUI::Events::Type event_id);
    void onUpdatePlayerName();
    void onExit();
    
    // Getters & Setters
    void setParametrosJogo(ParametrosJogo* parametros_jogo);
    const ParametrosJogo* getParametrosJogo() const;
};

}}

#endif /* ConfigMenu_hpp */
