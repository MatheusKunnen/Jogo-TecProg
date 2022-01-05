//
//  FaseTeste.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 11/10/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include "FaseTeste.hpp"

namespace Game {
	namespace Fases {

		// Const
		const string FaseTeste::CONFIG_FILE("Resources/config/fase_teste_config.json");


		// Constructor && Destructor
		FaseTeste::FaseTeste(Jogador* jogador_a, Jogador* jogador_b) :
			Fase(ID::fase_floresta, FaseTeste::CONFIG_FILE, jogador_a, jogador_b)
		{
		}

		FaseTeste::~FaseTeste() {
			this->l_entidades.clear();
		}

		void FaseTeste::update(const float& dt) {
			FrameTimer::GetInstance()->markUpdateDt();
			FrameTimer::GetInstance()->markUpdateStart();
			// Verifica colisoes
			g_colisoes.gerenciarColisoes();
			this->jogador_a->move(Vector2f(10, 0), dt);
			// Atualiza entidades
			l_entidades.update(dt);
			// Atualiza view do RenderWindow
			this->updateView(dt);
			// Verifica se um jogador Ganhou/Perdeu
			this->checkPlayerStatus();
			FrameTimer::GetInstance()->markUpdateFinished();
		}

		// Init Methods
		void FaseTeste::initInimigos() {
			Inimigo* desmatador = nullptr;
			const vector<Vector2f>& lista = this->parametros.getListaPosInimigos();
			int i = 0;
			for (Vector2f pos : lista) {
				if (i++ % 2 == 1)
					desmatador = new Narcotraficante(pos, &this->textures.get(Resources::Textures::narcotraficante), this->jogador_a, this->jogador_b, this);
				else
					desmatador = new Desmatador(pos, &this->textures.get(Resources::Textures::desmatador), this->jogador_a, this->jogador_b);
				this->l_entidades += desmatador;
				this->g_colisoes += desmatador;

			}
		}

		void FaseTeste::initObstaculos() {
			Obstaculo* obstaculo = nullptr;
			const vector<Vector2f>& lista = this->parametros.getListaPosObstaculos();
			int i = 0;
			for (Vector2f pos : lista) {
				if (i++ % 2 == 1)
					obstaculo = new PlantaVenenosa(pos, &this->textures.get(Resources::Textures::planta_venenosa));
				else
					obstaculo = new Espinho(pos, &this->textures.get(Resources::Textures::espinhos));
				Vector2f ppos = obstaculo->getPosition();
				ppos.y -= obstaculo->getGlobalBounds().height;
				obstaculo->setPosition(ppos);
				this->l_entidades += obstaculo;
				this->g_colisoes += obstaculo;

			}
		}

		// Methods
		void FaseTeste::onSavedFase() {
			// Desabilitado para Fase teste
		}

		void FaseTeste::onInitFase(Jogador* jogador_a, Jogador* jogador_b, FaseEventHandler* event_handler) {
			// Agrega mapa
			this->l_entidades.add(&mapa);
			// Atualiza ponteiros de jogadores
			this->jogador_a = jogador_a;
			this->jogador_b = jogador_b;
			// Inicia jogadores
			this->initJogadores();
			// Carrega salvadora
			this->salvadora.load();
			if (true || !this->salvadora.isSavedFase()) {
				// Inicia Obstaculos
				this->initObstaculos();
				// Inicia Inimigos
				this->initInimigos();
				// Muda estado
				this->salvadora.setSavedFase(true);
			}
			else {
				this->onSavedFase();
			}
			// Retorna o mapa a sua posicao inicial
			this->mapa.reset();
			// Atualiza EventHandler
			this->setEventHandler(event_handler);
			// Adapta View para resolucoes maiores
			GerenciadorGrafico::getInstance()->moveView(0, -(GerenciadorGrafico::getInstance()->getView()->getSize().y - this->mapa.getHeight()));
		}
	}
}
