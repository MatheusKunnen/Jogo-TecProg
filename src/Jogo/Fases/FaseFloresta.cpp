//
//  FaseFloresta.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "FaseFloresta.hpp"

namespace Game { namespace Fases {

// Const
const string FaseFloresta::CONFIG_FILE("Resources/config/fase_a_config.json");


// Constructor && Destructor
FaseFloresta::FaseFloresta(Jogador* jogador_a, Jogador* jogador_b):
Fase(ID::fase_floresta, FaseFloresta::CONFIG_FILE, jogador_a, jogador_b)
{
    
}

FaseFloresta::~FaseFloresta(){
    this->l_entidades.clear();
}

// Init Methods
void FaseFloresta::initInimigos() {
    Inimigo* desmatador = nullptr;
    const vector<Vector2f>& lista = this->parametros.getListaPosInimigos();
    for (Vector2f pos : lista){
        // Sorteia o nro e tipo de inimigos a instanciar
        //if (rand() % 2 == 1) {
            if (rand() % 2 == 1)
                desmatador = new Narcotraficante(pos, &this->textures.get(Resources::Textures::narcotraficante), this->jogador_a, this->jogador_b, this);
            else
                desmatador = new Desmatador(pos, &this->textures.get(Resources::Textures::desmatador), this->jogador_a, this->jogador_b);
            this->l_entidades += desmatador;
            this->g_colisoes += desmatador;
        //}
    }
}

void FaseFloresta::initObstaculos() {
    Obstaculo* obstaculo = nullptr;
    const vector<Vector2f>& lista = this->parametros.getListaPosObstaculos();
    for (Vector2f pos : lista){
        // Sorteia o nro e tipo de inimigos a instanciar
        if (rand() % 2 == 1){
            if (rand() % 2 == 1)
                obstaculo = new PlantaVenenosa(pos, &this->textures.get(Resources::Textures::planta_venenosa));
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

// Methods
void FaseFloresta::onSavedFase() {
    // Inicia posicao jogadores
    vector<Vector2f> l_pos = this->salvadora.getPositions(Entidades::ID::jogador);
    this->jogador_a->setPosition(l_pos[0]);
    this->jogador_a->setNumVidas(this->salvadora.getVidaJogador(1));
    if (this->jogador_b && l_pos.size() > 1){
        this->jogador_b->setPosition(l_pos[1]);
        this->jogador_b->setNumVidas(this->salvadora.getVidaJogador(2));
    }
    
    l_pos = this->salvadora.getPositions(Entidades::ID::desmatador);
    for(Vector2f pos : l_pos)
        this->addEntidade(new Desmatador(pos, &this->textures.get(Resources::Textures::desmatador), this->jogador_a, this->jogador_b));
    
    l_pos = this->salvadora.getPositions(Entidades::ID::narcotraficante);
    for(Vector2f pos : l_pos)
        this->addEntidade(new Narcotraficante(pos, &this->textures.get(Resources::Textures::narcotraficante), this->jogador_a, this->jogador_b, this));
    
    l_pos = this->salvadora.getPositions(Entidades::ID::espinhos);
    for(Vector2f pos : l_pos)
        this->addEntidade(new Espinho(pos, &this->textures.get(Resources::Textures::espinhos)));
    
    l_pos = this->salvadora.getPositions(Entidades::ID::planta_venenosa);
    for(Vector2f pos : l_pos)
        this->addEntidade(new PlantaVenenosa(pos, &this->textures.get(Resources::Textures::planta_venenosa)));
}

void FaseFloresta::onInitFase(Jogador* jogador_a, Jogador* jogador_b, FaseEventHandler* event_handler){
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
