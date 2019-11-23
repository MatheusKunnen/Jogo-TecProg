#ifndef Jogo_hpp
#define Jogo_hpp

#include "TADs/ListaRanking.hpp"

#include "Gerenciadores/GerenciadorGrafico.hpp"

#include "Parametros/ParametrosJogo.hpp"

#include "States/StateManager.hpp"

#include "Fases/FaseFloresta.hpp"
#include "Fases/FaseMontanha.hpp"

#include "Resources/TexturesHolder.hpp"
#include "Entidades/Jogador.hpp"


namespace Game {

// Usings
using States::State;
using States::StateManager;
using Menus::MainMenu;
using Menus::RankingMenu;
using Menus::ConfigMenu;
using Menus::PauseMenu;
using Menus::EndGameMenu;
using Menus::GameMenu;
using States::FaseState;

using Fases::FaseFloresta;
using Fases::FaseMontanha;

using Resources::TextureHolder;
using Parametros::ParametrosJogo;
using Gerenciadores::GerenciadorGrafico;
using Entidades::Personagens::Jogador;

using TADs::StateStack;
using TADs::ListaRanking;

class Jogo : public StateManager {
private:
    // Sigleton instance pointer
    static Jogo*                main_instance;  // Instancia do jogo para o Singleton
    
    // Attributes
    Event                       event_pool; // Eventos de SFML
    Clock                       main_clock; // Relogio principal do jogo
    GerenciadorGrafico*         g_grafico; // Referencia ao gerenciador grafico
    ParametrosJogo              par_jogo; // Parametros do jogo
    ListaRanking                l_ranking; // Lista de Ranking
    
    float                       dt; // Variacao do tempo
    int                         status_code; // Estado da execucao
    bool                        is_running; // Bandeira de execicao
    
    Jogador*                    jogador_a; // Ponteiro para jogador A
    Jogador*                    jogador_b; // Ponteiro para jogador B
    
    FaseFloresta                fase_floresta; // Instancia fase floresta
    FaseMontanha                fase_montanha; // Instancia fase montanha
    
    TextureHolder               textures; // Contenedor de texturas
    
    // Init methods
    void initParametros();
    void initStates();
    void initTextures();
    void initJogadores();
    void initKeys();
    
    // Private Constructor (para o Singleton)
    Jogo(const string& nome_jogador);
public:
    // Destructor
    ~Jogo();
    
    // Singleton intancer
    static Jogo* getInstance(const string& nome_jogador = "Sem nome");
    
    // Methods
    void run();
    void endGame();
    void updateDt();
    void handleEvents();
    void update();
    void render();
    
    void onWin();
    
    // State Manager Methods
    void pushTopState(States::states_id id);
    void popTopState();
    void addStatePop(int n_states = 1);
    
    // Getters & Setters
    int getStatusCode() const;
    Jogador* getJogadorA() const;
    Jogador* getJogadorB() const;
    const ParametrosJogo* getParametrosJogo() const;
};
};

#endif
