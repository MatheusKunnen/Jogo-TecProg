#ifndef Jogo_hpp
#define Jogo_hpp

#include "TADs/StateStack.hpp"

#include "States/StateManager.hpp"
#include "States/GameState.hpp"
#include "States/MainMenuState.hpp"
#include "States/RankingMenuState.hpp"
#include "States/ConfigMenuState.hpp"
#include "States/FaseState.hpp"
#include "States/PauseMenuState.hpp"
#include "States/WinMenuState.hpp"
#include "States/FailedMenuState.hpp"

#include "GerenciadorGrafico.hpp"

#include "Resources/TexturesHolder.hpp"
#include "Entidades/Jogador.hpp"
#include "Fases/FaseFloresta.hpp"
#include "Fases/FaseMontanha.hpp"

namespace Game {

// Usings
using sf::Clock;
using sf::Event;

using States::State;
using States::StateManager;
using States::MainMenuState;
using States::RankingMenuState;
using States::ConfigMenuState;
using States::PauseMenuState;
using States::WinMenuState;
using States::FailedMenuState;
using States::GameState;
using States::FaseState;

using Resources::TextureHolder;

using Entidades::Personagens::Jogador;
using Fases::FaseFloresta;
using Fases::FaseMontanha;

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
    int                         states_2_pop; // Nro estados a ser removidos
    map<string, int>            valid_keys; // Mapa Keys habilidas
    float                       dt; // Variacao do tempo
    int                         status_code; // Estado da execucao
    bool                        is_running; // Bandeira de execicao
    
    Jogador*                    jogador_a; // Ponteiro para jogador A
    Jogador*                    jogador_b; // Ponteiro para jogador B
    
    FaseFloresta                fase_floresta;
    FaseMontanha                fase_montanha;
    
    TextureHolder               textures; // Contenedor de texturas
    
    // Init methods
    void initStates();
    void initTextures();
    void initJogadores();
    void initFases();
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
    
    // State Manager Methods
    void pushTopState(States::states_id id);
    void popTopState();
    void addStatePop(int n_states = 1);
    
    // Getters & Setters
    Jogador* getJogadorA() const;
    Jogador* getJogadorB() const;
	int getStatusCode() const;

};
};

#endif
