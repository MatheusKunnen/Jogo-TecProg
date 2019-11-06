//
//  EventHandler.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/5/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef EventHandler_hpp
#define EventHandler_hpp

#include "base_gui_includes.hpp"

namespace GUI {

namespace Events {
    enum Type {CLICK, HOVER, ENABLED, DISABLED};
}

class EventHandler{
public:
    // Constructor & Destructor
    EventHandler();
    virtual ~EventHandler();
    // Methods
    virtual void onGuiEvent(int id, Events::Type event_id) = 0;
};
}

#endif /* EventHandler_hpp */
