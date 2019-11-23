//
//  State.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include "../Gerenciadores/GerenciadorGrafico.hpp"
#include "../base_includes.hpp"

namespace Game { namespace States {
// Const
enum states_id{main_menu, game_menu, config_menu, ranking_menu, pause_menu, win_menu, failed_menu, fase_floresta, fase_montanha};

using Gerenciadores::GerenciadorGrafico;

class StateManager;

class State {
protected:
    // Attributes
    //TextureHolder               textures;
    StateManager*               manager;
    const states_id             id;
    bool                        quit;
    
public:
    // Constructor & Destructor
    State(StateManager* handler, states_id id);
    virtual ~State();
    // Methods
    virtual void endState();
    //virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(RenderTarget* target = nullptr) = 0;
    // Setters & Getters
    const bool& isQuitting() const;
};

}};

#endif /* State_hpp */
