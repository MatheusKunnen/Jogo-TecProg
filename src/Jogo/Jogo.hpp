#ifndef Jogo_hpp
#define Jogo_hpp

#include "base_includes.hpp"
#include "TADs/StateStack.hpp"
#include "States/StateHandler.hpp"
#include "States/MainMenuState.hpp"
#include "States/GameState.hpp"
#include "GerenciadorGrafico.hpp"

namespace Game {
// Usings
using sf::Clock;
using sf::Event;

using States::State;
using States::StateHandler;
using States::MainMenuState;
using States::GameState;

using TADs::StateStack;

class Jogo : public StateHandler {
private:
    // Sigleton instance pointer
    static Jogo*        main_instance;
    // Attributes
    Event               event_pool;
    Clock               main_clock;
    GerenciadorGrafico*        main_mEngine;
    
    StateStack          states;
    map<string, int>    valid_keys;
    float               dt;
    int                 status_code;
    bool                mRunning;
    
    // Init methods
    void initStates();
    void initKeys();
public:
    // Constructor & Destructor
    Jogo();
    ~Jogo();
    // Singleton intancer
    static Jogo* getInstance();
    // Methods
    void run();
    void endGame();
    void updateDt();
    void handleEvents();
    void update();
    void render();
    void pushState(States::states_id id);
    // Getters & Setters
	int getStatusCode() const;

};
};

#endif
