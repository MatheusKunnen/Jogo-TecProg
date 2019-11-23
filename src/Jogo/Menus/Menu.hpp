//
//  Menu.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "../GUI/ListaWidgets.hpp"
#include "../GUI/Button.hpp"
#include "../GUI/TextView.hpp"
#include "../Resources/TexturesHolder.hpp"
#include "../Resources/FontHolder.hpp"
#include "../States/State.hpp"
#include "../base_includes.hpp"

namespace Game { namespace Menus {

using GUI::ListaWidgets;
using GUI::Button;
using GUI::TextView;
using GUI::Context;
using GUI::EventHandler;

using States::State;
using States::StateManager;

using Resources::FontHolder;
using Resources::TextureHolder;

using Gerenciadores::GerenciadorGrafico;

class Menu : public State, public EventHandler {
protected:
    // Attributes
    Context                 context; // Contexto para GUI
    RectangleShape          background; // Fundo
    FontHolder              fonts; // FlyWeight fontes
    TextureHolder           textures; // FlyWeight texturas
    
    ListaWidgets            widgets; // Lista elementos GUI
    
    // Init methods
    virtual void initMenu() = 0;
    virtual void initWidgets() = 0;
    virtual void initTextures();
    virtual void initFonts();
    virtual void initBackground();
    
public:
    // Contructor & Destructor
    Menu(StateManager* handler, States::states_id id);
    virtual ~Menu();
    
    // Methods
    virtual void onGuiEvent(int id, GUI::Events::Type event_id) = 0;

};

}};

#endif /* Menu_hpp */
