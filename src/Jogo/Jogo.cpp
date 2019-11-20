#include "Jogo.hpp"

namespace Game {

// Sigleton pointer
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
parametros_jogo(),
dt(0),
status_code(0),
l_ranking()
{
    // Instacia o gerenciador gradico
    this->g_grafico = GerenciadorGrafico::getInstance();
    // Chama funcoes de inicio
    this->initParametros();
    this->initTextures();
    this->initJogadores();
    this->initKeys();
    this->initStates();
}

Jogo::~Jogo(){
    this->endGame();
}

// Init methods
void Jogo::initParametros(){
    this->parametros_jogo.loadFromFile();
}

void Jogo::initStates(){
    // Realiza o push do state base (Menu Principal)
    this->states.push(new MainMenu(this, GerenciadorGrafico::getInstance(), &this->valid_keys));
}

void Jogo::initTextures(){
    // Carrega texturas de jogadores
    this->textures.load(Resources::Textures::jogador_a, textures.getFilename(    Resources::Textures::jogador_a));
    this->textures.load(Resources::Textures::jogador_b, textures.getFilename(    Resources::Textures::jogador_b));
}

void Jogo::initJogadores(){
    // Aloca jogadores
    this->jogador_a = new Jogador(Vector2f(g_grafico->getRenderWindow()->getSize().x/2,512.f), &this->textures.get(Resources::Textures::jogador_a));
    this->jogador_b = new Jogador(Vector2f(980.f,600.f), &this->textures.get(Resources::Textures::jogador_b));
    
    this->jogador_a->setGGrafico(this->g_grafico);
    this->jogador_b->setGGrafico(this->g_grafico);
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
    // Atualiza bandeira de execução
    this->is_running = true;
    // Abre janela do RenderWindow
    this->g_grafico->getRenderWindow()->display();
    // Loop principal do jogo
    while(this->is_running){
        // Atualiza relogio
        updateDt();
        // Atualiza estados
        update();
        // Renderiza estados
        render();
        // Notifica quando a variação de tempo for muito alta
        if (1/50.f - this->dt < 0){
            cerr << "WARNING: " << this->dt << " Missed: " << 1/(this->dt-1/50.f)<<endl;
            // Limita maxima variacao do tempo
            this->dt = .10;
        }
    }
}

void Jogo::endGame(){
    // Desaloca gerenciador grafico
    delete this->g_grafico;
    while(!this->states.empty())
        // Pilha desaloca a elemento ao fazer o "pop"
        this->states.pop();
    // Desaloca jogadores
    delete this->jogador_a;
    delete this->jogador_b;
}

void Jogo::updateDt(){
    // Relogio principal do jogo
    // (determina variacao de tempo de cada loop)
    this->dt = main_clock.restart().asSeconds();
}

void Jogo::handleEvents(){
    //return;
    while(this->g_grafico->getRenderWindow()->pollEvent(event_pool)){
        // Verifica se a janela é fechada
        if (event_pool.type == sf::Event::Closed)
            this->is_running = false;
    }
}

void Jogo::update(){
    // Verifica Eventos
    this->handleEvents();
    // Verifica fila de estados a finalizar
    while(this->states_2_pop > 0){
        this->popTopState();
        this->states_2_pop--;
    }
    // Atualiza estado se existir algum
    if (!this->states.empty()){
        // Atualiza estado
        this->states.top()->update(this->dt);
        // Verifica se o estado quer finalizar
        if (this->states.top()->isQuitting())
            this->popTopState(); // Remove estado da pila (e é desalocado)
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

void Jogo::onWin(){
    this->l_ranking.add(this->parametros_jogo.getPlayerName(), this->jogador_a->getScore());
}

void Jogo::pushTopState(States::states_id id){
    State* state  = nullptr;
    // Aloca estado solicitado
    switch (id) {
        case States::states_id::main_menu:
            state = new MainMenu(this, GerenciadorGrafico::getInstance(), &this->valid_keys);
            break;
        case States::states_id::game_menu:
            state = new GameMenu(this, GerenciadorGrafico::getInstance(), &this->valid_keys);
            break;
        case States::states_id::config_menu:
            state = new ConfigMenu(this, GerenciadorGrafico::getInstance(), &this->valid_keys, &this->parametros_jogo);
            break;
        case States::states_id::ranking_menu:
            state = new RankingMenu(this, GerenciadorGrafico::getInstance(), &this->valid_keys, this->l_ranking);
            break;
        case States::states_id::pause_menu:
            state = new PauseMenu(this, GerenciadorGrafico::getInstance(), &this->valid_keys);
            break;
        case States::states_id::win_menu:
            this->onWin();
            state = new WinMenu(this, GerenciadorGrafico::getInstance(), &this->valid_keys);
            break;
        case States::states_id::failed_menu:
            state = new FailedMenu(this, GerenciadorGrafico::getInstance(), &this->valid_keys);
            break;
        case States::states_id::fase_floresta:
            state = new FaseState(this, GerenciadorGrafico::getInstance(), &this->valid_keys, this->fase_floresta, this->getJogadorA(), this->getJogadorB());
            break;
        case States::states_id::fase_montanha:
            state = new FaseState(this, GerenciadorGrafico::getInstance(), &this->valid_keys, this->fase_montanha, this->getJogadorA(), this->getJogadorB());
        default:
            // Caso o ID seja inválido
            cerr << "ERROR: Jogo::pushState(): Trying to push unidentified state." << endl;
            break;
    }
    // Se um estado foi alocado o agrega à pilha
    if (state != nullptr)
        this->states.push(state);
    // Delay para evitar falsos eventos
    sf::sleep(sf::milliseconds(150));
}

void Jogo::popTopState(){
    if (!this->states.empty())
        this->states.top()->endState(); // Notifica termino
        this->states.pop(); // Remove da pilha e desaloca
}

void Jogo::addStatePop(int n_states){
    this->states_2_pop = n_states;
    // Delay para evitar falsos eventos
    sf::sleep(sf::milliseconds(150));
}

// Getters & Setters
int Jogo::getStatusCode() const {
    return this->status_code; // Retorna estado final da execução
}

Jogador* Jogo::getJogadorA() const {
    return this->jogador_a;
}

Jogador* Jogo::getJogadorB() const {
    return (parametros_jogo.isDualPlayer()) ? this->jogador_b : nullptr;
}

const ParametrosJogo* Jogo::getParametrosJogo() const {
    return &this->parametros_jogo;
}

}
