//
//  GameState.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/7/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

#include "State.hpp"
#include "../Resources/TexturesHolder.hpp"
#include "../Entidades/Jogador.hpp"
#include "../Entidades/level.hpp"
#include "../base_includes.hpp"
namespace Game { namespace States {

using Textures::TextureHolder;
using Entidades::Personagens::Jogador;
class GameState : public State {
private:
    // Attributes
    TextureHolder       textures_used;
    Jogador*            jogador; // DEBUG
    Level               lvl;
    // Init methods
    void initTextures();
    void initValidKeys();
    void initEntities();
public:
    // Contructor & Destructor
    GameState(StateHandler* handler, MediaEngine* g_grafico, map<string, int>* supported_keys);
    ~GameState();
    
    // Methods
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target);
};

}};

#endif /* GameState_hpp */
