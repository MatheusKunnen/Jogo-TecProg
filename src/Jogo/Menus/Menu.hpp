//
//  Menu.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "../GUI/Button.hpp"
#include "../Resources/TexturesHolder.hpp"
#include "../Resources/FontHolder.hpp"
#include "../base_includes.hpp"

namespace Game { namespace Menus {

using GUI::Button;
using GUI::Context;
using GUI::EventHandler;

using Resources::FontHolder;
using Resources::TextureHolder;

class Menu : public EventHandler {
protected:
    // Attributes
    Context                 context;
    sf::RectangleShape      background;
    FontHolder              fonts;
    TextureHolder           textures;
    
    map<int, Button*>       buttons;
    
    // Init methods
    virtual void initMenu() = 0;
    virtual void initWidgets() = 0;
    virtual void initFonts() = 0;
public:
    // Contructor & Destructor
    Menu(RenderWindow& window);
    virtual ~Menu();
    // Methods
    virtual void updateMenu(const float& dt) = 0;
    virtual void renderMenu(RenderTarget* target) const = 0;
    virtual void onGuiEvent(int id, GUI::Events::Type event_id) = 0;
    virtual void onExit() = 0;
};

}};

#endif /* Menu_hpp */
