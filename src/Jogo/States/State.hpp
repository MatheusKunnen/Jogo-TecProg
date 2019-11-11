//
//  State.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include "../GerenciadorGrafico.hpp"
#include "../Entidades/Entidade.hpp"
#include "../Resources/TexturesHolder.hpp"
#include "../base_includes.hpp"

namespace Game { namespace States {
// Const
enum states_id{main_menu, game_menu, config, ranking, pause_menu, fase_floresta, phase_b};

using Resources::TextureHolder;

class StateManager;

class State {
protected:
    // Attributes
    TextureHolder               textures;
    
    map<string, int>*           supported_keys;
    map<string, int>            used_keys;
    
    GerenciadorGrafico*         g_grafico;
    StateManager*               manager;
    const states_id             id;
    bool                        quit;
    
    // Methods
    virtual void initValidKeys() = 0;
public:
    // Constructor & Destructor
    State(StateManager* handler, GerenciadorGrafico* g_grafico, map<string, int>* supported_keys, states_id id);
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
