#ifndef Jogo_hpp
#define Jogo_hpp

#include "base_includes.hpp"
#include "States/MainMenuState.hpp"
#include "States/GameState.hpp"
#include "MediaEngine.hpp"

namespace Game {
// Usings
using sf::Clock;
using sf::Event;

using States::State;
using States::MainMenuState;
using States::GameState;

class Jogo {
private:
    // Sigleton instance holder
    static Jogo*        main_instance;
    // Attributes
    Event               event_pool;
    Clock               main_clock;
    MediaEngine*        main_mEngine;
    
    stack<State*>       states;
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
    void pushState(State* state);
    // Getters & Setters
	int getStatusCode() const;

};
}

#endif
