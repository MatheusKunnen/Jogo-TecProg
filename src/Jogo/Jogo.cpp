#include "Jogo.hpp"
namespace Game {
// Sigleton holder
Jogo* Jogo::main_instance = nullptr;

// Singleton instancer
Jogo* Jogo::getInstance() {
    if (Jogo::main_instance == nullptr)
        Jogo::main_instance = new Jogo();
    return Jogo::main_instance;
}

// Constructor && Destructor
Jogo::Jogo():
event_pool(),
main_clock(),
main_mEngine(nullptr),
states(),
dt(0),
status_code(0)
{
    this->main_mEngine = MediaEngine::getInstance();
    this->initKeys();
    this->initStates();

    
        sf::VideoMode mode = sf::VideoMode::getDesktopMode();
        std::cout << "Mode #"  << ": "
                  << mode.width << "x" << mode.height << " - "
                  << mode.bitsPerPixel << " bpp" << std::endl;
    
}

Jogo::~Jogo(){
    this->endGame();
}

// Init methods
void Jogo::initStates(){
    this->states.push(new MainMenuState(this->main_mEngine->getRenderWindow(), &this->valid_keys, &this->states));
}

void Jogo::initKeys(){
    this->valid_keys["Escape"] = sf::Keyboard::Escape;
    // Move Keys
    this->valid_keys["A"] = sf::Keyboard::A;
    this->valid_keys["D"] = sf::Keyboard::D;
    this->valid_keys["W"] = sf::Keyboard::W;
    this->valid_keys["S"] = sf::Keyboard::S;
    this->valid_keys["Space"] = sf::Keyboard::Space;
}
// Methods
void Jogo::run() {
    this->mRunning = true;
    this->main_mEngine->getRenderWindow()->display();
    while(this->mRunning){
        updateDt();
        update();
        render();
        if (30 - this->dt > 0)
            30;//sf::sleep(sf::milliseconds(20 - this->dt));
        else
            cout << this->dt << endl;
    }
    if (this->main_mEngine->getRenderWindow()->isOpen())
        this->main_mEngine->getRenderWindow()->close();
}

void Jogo::endGame(){
    delete this->main_mEngine;
    while(!this->states.empty()){
        delete this->states.top();
        this->states.pop();
    }
}

void Jogo::updateDt(){
    this->dt = main_clock.restart().asSeconds();
}

void Jogo::handleEvents(){
    while(this->main_mEngine->getRenderWindow()->pollEvent(event_pool)){
        // Close window : exit
        if (event_pool.type == sf::Event::Closed){
           // this->main_mEngine->getRenderWindow()->close();
            this->mRunning = false;
        }
    }
}

void Jogo::update(){
    this->handleEvents();
    if (!this->states.empty()){
        this->states.top()->update(this->dt);
        if (this->states.top()->isQuitting()){
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    } else {
       // this->main_mEngine->getRenderWindow()->close();
        this->mRunning = false;
    }
    
}

void Jogo::render(){
    this->main_mEngine->getRenderWindow()->clear();
    if (!this->states.empty())
        this->states.top()->render();
    this->main_mEngine->getRenderWindow()->display();
}

void Jogo::pushState(State *state){
    this->states.push(state);
}

int Jogo::getStatusCode() const {
    return this->status_code;
}

}
