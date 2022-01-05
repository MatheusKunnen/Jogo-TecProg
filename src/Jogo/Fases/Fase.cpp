//
//  Fase.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/8/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "Fase.hpp"

namespace Game { namespace Fases {

// Consts
const int Fase::BG_TEXTURE(1);

// Constructor & Destructor
Fase::Fase(ID id, const string& f_parametros, Jogador* jogador_a, Jogador* jogador_b):
l_entidades(),
salvadora(this->l_entidades, id),
jogador_a(jogador_a),
jogador_b(jogador_b),
mapa(),
textures(),
g_colisoes(mapa),
g_grafico(GerenciadorGrafico::getInstance()),
parametros(f_parametros),
event_handler(nullptr)
{
    initParametros();
    initTextures();
    initMapa();
    FrameTimer::GetInstance()->clear();
}

Fase::~Fase(){
    this->l_entidades.clear();
}

// Init methods
void Fase::initParametros(){
    // Carrega Parametros
    this->parametros.loadFromFile();
}

void Fase::initTextures(){
    this->textures.load(Resources::Textures::bg_fase, this->parametros.getArquivoBackground());
    // Texturas Obstaculos
    this->textures.load(Resources::Textures::planta_venenosa, this->textures.getFilename(Resources::Textures::planta_venenosa));
    this->textures.load(Resources::Textures::espinhos, this->textures.getFilename(Resources::Textures::espinhos));
    this->textures.load(Resources::Textures::pedra, this->textures.getFilename(Resources::Textures::pedra));
    this->textures.load(Resources::Textures::projetil, this->textures.getFilename(Resources::Textures::projetil));
    // Texturas Inimigos
    this->textures.load(Resources::Textures::desmatador, this->textures.getFilename(Resources::Textures::desmatador));
    this->textures.load(Resources::Textures::narcotraficante, this->textures.getFilename(Resources::Textures::narcotraficante));
        this->textures.load(Resources::Textures::narcotraficante_desmatador, this->textures.getFilename(Resources::Textures::narcotraficante_desmatador));
}

void Fase::initMapa(){
    // Coloca textura de fundo
    this->mapa.setTexture(&this->textures.get(Resources::Textures::bg_fase));
    // Carrega Mapa
    this->mapa.load(this->parametros.getArquivoMapa(), this->parametros.getArquivoTileSet());
}

void Fase::initJogadores(){
    if (this->jogador_a != nullptr){
        this->jogador_a->reset();
        this->l_entidades.add(this->jogador_a, false);
        this->g_colisoes += this->jogador_a;
        this->jogador_a->setPosition(this->parametros.getPosPlayerA());
    }
    if (this->jogador_b != nullptr) {
        this->jogador_b->reset();
        this->l_entidades.add(this->jogador_b, false);
        this->g_colisoes += this->jogador_b;
        this->jogador_b->setPosition(this->parametros.getPosPlayerB());
        this->g_grafico->resetDefaultView();
    }
}

// Methods
void Fase::update(const float &dt){
    FrameTimer::GetInstance()->markUpdateDt();
    FrameTimer::GetInstance()->markUpdateStart();
    // Verifica colisoes
    g_colisoes.gerenciarColisoes();
    // Atualiza entidades
    l_entidades.update(dt);
    // Atualiza view do RenderWindow
    this->updateView(dt);
    // Verifica se um jogador Ganhou/Perdeu
    this->checkPlayerStatus();
    FrameTimer::GetInstance()->markUpdateFinished();
}

void Fase::render(RenderTarget *target) {
    FrameTimer::GetInstance()->markRenderStart();
    // Renderiza todas as entidades
    this->l_entidades.render(target);
    FrameTimer::GetInstance()->markRenderFinished();
}

void Fase::updateView(const float &dt){
    if (this->jogador_a != nullptr){
        this->mapa.setPosition(this->jogador_a->getPosition().x, this->g_grafico->getView()->getCenter().y);
    }
}

void Fase::checkPlayerStatus(){
    // Verifica vida de jogadores
    if (this->jogador_a->getNumVidas() <= 0 || (this->jogador_b && this->jogador_b->getNumVidas() <= 0)){
        this->salvadora.setSavedFase(false);
        this->event_handler->onFaseEvent(Event::failed);
        this->g_grafico->resetDefaultView();
    }
    // Verifica se algum jogador chegou ao final
    if ((this->jogador_a->getPosition().x >= this->parametros.getPosXWin()) ||
        (this->jogador_b && this->jogador_b->getPosition().x >= this->parametros.getPosXWin())){
        this->salvadora.setSavedFase(false);
        if (this->event_handler)
            this->event_handler->onFaseEvent(Event::win);
        this->g_grafico->resetDefaultView();
    }
    // Verifica se nenhum jogador caiu pela borda
    if ((this->jogador_a->getPosition().y >= this->g_grafico->getRenderWindow()->getSize().y) ||
        (this->jogador_b && this->jogador_b->getPosition().y >= this->g_grafico->getRenderWindow()->getSize().y)){
        this->salvadora.setSavedFase(false);
        if (this->event_handler)
            this->event_handler->onFaseEvent(Event::failed);
        this->g_grafico->resetDefaultView();
    }

}

void Fase::addEntidade(Gerenciadores::Personagem* personagem){
    this->l_entidades += personagem;
    this->g_colisoes += personagem;
}

void Fase::addEntidade(Gerenciadores::Obstaculo* obstaculo){
    this->l_entidades += obstaculo;
    this->g_colisoes += obstaculo;
}

void Fase::createProjetil(const Vector2f& position, const short &direction, const int &damage, const float& speed) {
    this->addEntidade(new Projetil(position, &this->textures.get(Resources::Textures::projetil), damage, direction, speed));
}

void Fase::onKeyInput(eventos_jogador::Tipo tipo, const float& dt){
    switch (tipo) {
        case eventos_jogador::Tipo::M_LEFT_A:
            if (this->jogador_a)
                this->jogador_a->move(Vector2f(-1.f,0), dt);
            break;
        case eventos_jogador::Tipo::M_RIGHT_A:
            if (this->jogador_a)
                 this->jogador_a->move(Vector2f(1.f,0), dt);
            break;
        case eventos_jogador::Tipo::JUMP_A:
             if (this->jogador_a)
                 this->jogador_a->jump(10);
            break;
        case eventos_jogador::Tipo::M_LEFT_B:
             if (this->jogador_b)
                 this->jogador_b->move(Vector2f(-1.f,0), dt);
            break;
        case eventos_jogador::Tipo::M_RIGHT_B:
            if (this->jogador_b)
                this->jogador_b->move(Vector2f(1.f,0), dt);
            break;
        case eventos_jogador::Tipo::JUMP_B:
            if (this->jogador_b)
                this->jogador_b->jump(10);
            break;
        default:
            break;
    }
}

void Fase::onCloseFase(){
    // Guarda timer
    FrameTimer::GetInstance()->persist(true);
    // Atualiza vida jogadores
    this->salvadora.setVidaJogador(1, this->jogador_a->getNumVidas());
    if (this->jogador_b)
        this->salvadora.setVidaJogador(2, this->jogador_b->getNumVidas());
    // Salva parametros fase
    this->parametros.saveToFile();
    // Salva fase se for necessario
    this->salvadora.save();
    // Limpa entidades
    this->l_entidades.clear();
    // Limpa gerenciador de colisoes
    this->g_colisoes.clear();
    // Retorna à View original
    this->g_grafico->resetDefaultView();

}

// Getters & Setters
void Fase::setEventHandler(FaseEventHandler *event_handler){
    this->event_handler = event_handler;
}

FaseEventHandler* Fase::getEventHandler() const {
    return this->event_handler;
}



}}
