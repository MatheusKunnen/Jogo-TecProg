//
//  FaseEventHandler.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/15/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef FaseEventHandler_hpp
#define FaseEventHandler_hpp

#include "../base_includes.hpp"

namespace Game { namespace Fases {
// Lista de Eventos
enum Event {win, failed};

class FaseEventHandler {
public:
    // Constructro & Destructor
    FaseEventHandler() { };
    virtual ~FaseEventHandler() { };
    // Methods
    virtual void onFaseEvent(Event event_id) = 0;
};

}}
#endif /* FaseEventHandler_hpp */
