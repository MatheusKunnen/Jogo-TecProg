//
//  FaseMontanha.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "FaseMontanha.hpp"
namespace Game { namespace Fases {

// Const
const string FaseMontanha::CONFIG_FILE("Resources/config/fase_b_config.json");


// Constructor && Destructor
FaseMontanha::FaseMontanha(Jogador* jogador_a, Jogador* jogador_b):
Fase(ID::fase_montanha, FaseMontanha::CONFIG_FILE, jogador_a, jogador_b)
{
    
}

FaseMontanha::~FaseMontanha(){
    this->l_entidades.clear();
}

// Init Methods
void FaseMontanha::initInimigos() {
    Inimigo* desmatador = nullptr;
    
    const vector<Vector2f>& lista = this->parametros.getListaPosInimigos();
    for (Vector2f pos : lista){
        if (rand() % 10 > 3){
            desmatador = new Narcotraficante(pos, &this->textures.get(Resources::Textures::narcotraficante), this->jogador_a, this->jogador_b, this);
            this->l_entidades += desmatador;
            this->g_colisoes += desmatador;
            
        }
    }
}

void FaseMontanha::initObstaculos() {
    Obstaculo* obstaculo = nullptr;
    const vector<Vector2f>& lista = this->parametros.getListaPosObstaculos();
    for (Vector2f pos : lista){
        if (rand() % 10 > 3) {
            if (rand() % 2 == 1)
                obstaculo = new Pedra(pos, &this->textures.get(Resources::Textures::planta_venenosa));
            else
                obstaculo = new Espinho(pos, &this->textures.get(Resources::Textures::espinhos));
            Vector2f ppos = obstaculo->getPosition();
            ppos.y -= obstaculo->getGlobalBounds().height;
            obstaculo->setPosition(ppos);
            this->l_entidades+= obstaculo;
            this->g_colisoes += obstaculo;
        }
        
    }
}

void FaseMontanha::initBoss(){
    Inimigo* inimigo = new NarcotraficanteDesmatador(this->parametros.getPosBoss(), &this->textures.get(Resources::Textures::narcotraficante_desmatador), this->jogador_a, this->jogador_b, this);
    this->l_entidades+= inimigo;
    this->g_colisoes += inimigo;
}

void FaseMontanha::onSavedFase() {
    // Inicia posicao jogadores
    vector<Vector2f> l_pos = this->salvadora.getPositions(Entidades::ID::jogador);
    this->jogador_a->setPosition(l_pos[0]);
    this->jogador_a->setNumVidas(this->salvadora.getVidaJogador(1));
    if (this->jogador_b && l_pos.size() > 1){
        this->jogador_b->setPosition(l_pos[1]);
        this->jogador_b->setNumVidas(this->salvadora.getVidaJogador(2));
    }
    
    l_pos = this->salvadora.getPositions(Entidades::ID::boss);
    for(Vector2f pos : l_pos)
        this->addEntidade(new NarcotraficanteDesmatador(pos, &this->textures.get(Resources::Textures::narcotraficante), this->jogador_a, this->jogador_b, this));
    
    l_pos = this->salvadora.getPositions(Entidades::ID::narcotraficante);
    for(Vector2f pos : l_pos)
        this->addEntidade(new Narcotraficante(pos, &this->textures.get(Resources::Textures::narcotraficante), this->jogador_a, this->jogador_b, this));
    
    l_pos = this->salvadora.getPositions(Entidades::ID::espinhos);
    for(Vector2f pos : l_pos)
        this->addEntidade(new Espinho(pos, &this->textures.get(Resources::Textures::espinhos)));
    
    l_pos = this->salvadora.getPositions(Entidades::ID::pedra);
    for(Vector2f pos : l_pos)
        this->addEntidade(new Pedra(pos, &this->textures.get(Resources::Textures::planta_venenosa)));
}

// Methods
void FaseMontanha::onInitFase(Jogador* jogador_a, Jogador* jogador_b, FaseEventHandler* event_handler){
    // Agrega mapa
    this->l_entidades.add(&mapa);
    // Atualiza ponteiros de jogadores
    this->jogador_a = jogador_a;
    this->jogador_b = jogador_b;
    // Inicia jogadores
    this->initJogadores();
    // Carrega salvadora
    this->salvadora.load();
    if (!this->salvadora.isSavedFase()){
        // Inicia boss
        this->initBoss();
        // Inicia Obstaculos
        this->initObstaculos();
        // Inicia Inimigos
        this->initInimigos();
        // Muda estado
        this->salvadora.setSavedFase(true);
    } else {
        this->onSavedFase();
    }
    // Retorna o mapa a sua posicao inicial
    this->mapa.reset();
    // Atualiza EventHandler
    this->setEventHandler(event_handler);
    // Adapta View para resolucoes maiores
    GerenciadorGrafico::getInstance()->moveView(0, - (GerenciadorGrafico::getInstance()->getView()->getSize().y - this->mapa.getHeight()));
    
}
}}
