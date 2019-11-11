#ifndef Jogo_hpp
#define Jogo_hpp

#include "TADs/StateStack.hpp"

#include "States/StateManager.hpp"
#include "States/MainMenuState.hpp"
#include "States/GameState.hpp"
#include "States/FaseFlorestaState.hpp"
#include "States/FaseMontanhaState.hpp"

#include "GerenciadorGrafico.hpp"

#include "Resources/TexturesHolder.hpp"
#include "Entidades/Jogador.hpp"

namespace Game {

namespace States {

class FaseFlorestaState;
class FaseMontanhaState;

}

// Usings
using sf::Clock;
using sf::Event;

using States::State;
using States::StateManager;
using States::MainMenuState;
using States::GameState;
using States::FaseFlorestaState;
using States::FaseMontanhaState;

using Resources::TextureHolder;

using Entidades::Personagens::Jogador;

using TADs::StateStack;

class Jogo : public StateManager {
private:
    // Sigleton instance pointer
    static Jogo*                main_instance; // Instancia do jogo para o Singleton
    // Attributes
    Event                       event_pool; // Eventos de SFML
    Clock                       main_clock; // Relogio principal do jogo
    GerenciadorGrafico*         g_grafico; // Referencia ao gerenciador grafico
    
    StateStack                  states; // Pilha de estados
    map<string, int>            valid_keys; // Mapa Keys habilidas
    float                       dt; // Variacao do tempo
    int                         status_code; // Estado da execucao
    bool                        is_running; // Bandeira de execicao
    
    Jogador*                    jogador_a; // Ponteiro para jogador A
    Jogador*                    jogador_b; // Ponteiro para jogador B
    TextureHolder               textures; // Contenedor de texturas
    
    // Init methods
    void initStates();
    void initTextures();
    void initJogadores();
    void initKeys();
    
    // Private Constructor (para o Singleton)
    Jogo();
public:
    // Destructor
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
    Jogador* getJogadorA() const;
    Jogador* getJogadorB() const;
	int getStatusCode() const;

};
};

#endif
