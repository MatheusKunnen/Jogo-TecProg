#include "Jogo.hpp"
#include "FaseMontanhaState.hpp"
#include "FaseState.hpp"

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
jogador_a(nullptr),
jogador_b(nullptr),
fase_floresta(GerenciadorGrafico::getInstance(), this->jogador_a, this->jogador_b),
fase_montanha(GerenciadorGrafico::getInstance(), this->jogador_a, this->jogador_b),
event_pool(),
main_clock(),
g_grafico(nullptr),
states(),
dt(0),
status_code(0)
{
    this->g_grafico = GerenciadorGrafico::getInstance(); // Instacia o gerenciador gradico
    this->initTextures();
    this->initJogadores();
    this->initFases();
    this->initKeys();
    this->initStates();
}

Jogo::~Jogo(){
    this->endGame();
    
    // Desaloca jogadores
    delete this->jogador_a;
    delete this->jogador_b;
}

// Init methods
void Jogo::initStates(){
    // Realiza o push do state base (Menu Principal)
    this->states.push(new MainMenuState(this, GerenciadorGrafico::getInstance(), &this->valid_keys));
}

void Jogo::initTextures(){
    // Carrega texturas de jogadores
    this->textures.load(Resources::Textures::player_a, textures.getFilename(    Resources::Textures::player_a));
        this->textures.load(Resources::Textures::player_b, textures.getFilename(    Resources::Textures::player_b));
}

void Jogo::initJogadores(){
    // Aloca jogadores
    this->jogador_a = new Jogador(Vector2f(g_grafico->getRenderWindow()->getSize().x/2,512.f), &this->textures.get(Resources::Textures::player_a));
    this->jogador_b = new Jogador(Vector2f(980.f,600.f), &this->textures.get(Resources::Textures::player_b));
}

void Jogo::initFases(){
    //this->fase_floresta.set
}

void Jogo::initKeys(){
    // Inicializa keys habilidas
    this->valid_keys["Escape"] = sf::Keyboard::Escape;
    this->valid_keys["A"] = sf::Keyboard::A;
    this->valid_keys["D"] = sf::Keyboard::D;
    this->valid_keys["W"] = sf::Keyboard::W;
    this->valid_keys["S"] = sf::Keyboard::S;
    this->valid_keys["UP"] = sf::Keyboard::Up;
    this->valid_keys["LEFT"] = sf::Keyboard::Left;
    this->valid_keys["RIGHT"] = sf::Keyboard::Right;
    this->valid_keys["Space"] = sf::Keyboard::Space;
}
// Methods
void Jogo::run() {
    this->is_running = true;
    this->g_grafico->getRenderWindow()->display();
    while(this->is_running){
        updateDt();
        update();
        render();
        if (30 - this->dt < 0)
            cout << this->dt << endl;
    }
}

void Jogo::endGame(){
    delete this->g_grafico;
    while(!this->states.empty())
        this->states.pop(); // Lista desaloca a memoria ao fazer o pop
}

void Jogo::updateDt(){
    this->dt = main_clock.restart().asSeconds();
}

void Jogo::handleEvents(){
    while(this->g_grafico->getRenderWindow()->pollEvent(event_pool)){
        // Close window : exit
        if (event_pool.type == sf::Event::Closed)
            this->is_running = false;
    }
}

void Jogo::update(){
    // Verifica Eventos
    this->handleEvents();
    // Atualiza estado se existir algum
    if (!this->states.empty()){
        this->states.top()->update(this->dt);
        if (this->states.top()->isQuitting()){
            this->states.top()->endState();
            this->states.pop();
        }
    } else
        // Para execucao se a pilha se estados encontra-se vazia
        this->is_running = false;
}

void Jogo::render(){
    // Limpa tela
    this->g_grafico->getRenderWindow()->clear();
    // Renderiza estado superior se existir
    if (!this->states.empty())
        this->states.top()->render();
    // Mostra a tela
    this->g_grafico->getRenderWindow()->display();
}

void Jogo::pushState(States::states_id id){
    State* state  = nullptr;
    switch (id) {
        case States::states_id::main_menu:
            state = new MainMenuState(this, GerenciadorGrafico::getInstance(), &this->valid_keys);
            break;
        case States::states_id::game_menu:
            state = new GameState(this, GerenciadorGrafico::getInstance(), &this->valid_keys);
            break;
        case States::states_id::ranking:
            this->fase_floresta.onInitFase(this->jogador_a, this->jogador_b); // Notifica inicio de estado à fase
            state = new FaseState(this, GerenciadorGrafico::getInstance(), &this->valid_keys, this->fase_floresta);
            break;
        case States::states_id::config:
            state = new FaseState(this, GerenciadorGrafico::getInstance(), &this->valid_keys, this->fase_montanha);
            break;
        case States::states_id::fase_floresta:
            //state = new FaseFlorestaState(this, GerenciadorGrafico::getInstance(), &this->valid_keys);
            break;
        case States::states_id::phase_b:
            //state = new FaseMontanhaState(this, GerenciadorGrafico::getInstance(), &this->valid_keys);
        default:
            cerr << "ERROR: Jogo::pushState(): Trying to push unidentified state." << endl;
            break;
    }
    if (state != nullptr)
        this->states.push(state);
}


// Getters & Setters
int Jogo::getStatusCode() const {
    return this->status_code;
}

const Jogador* Jogo::getJogadorA() const {
    return this->jogador_a;
}

const Jogador* Jogo::getJogadorB() const {
    return this->jogador_b;
}
}
