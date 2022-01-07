//
//  FrameTimer.hpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma.
//  Copyright © 2022 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef FrameTimer_hpp
#define FrameTimer_hpp
#include "./base_includes.hpp"
#include "Gerenciadores/GerenciadorArquivos.hpp"
#include <chrono>

using Game::Gerenciadores::json;

class FrameTimer {
private:
	static FrameTimer* defaultInstance;

	std::string saveFile;
	int fileCount;
	Game::Gerenciadores::GerenciadorArquivos gArquivos;

	Clock mainClock;
	Clock updateClock;
	Clock renderClock;

	vector<float> totalFrameTimes;
	vector<float> updateFrameTimes;
	vector<float> renderFrameTimes;
	vector<int> totalEntities;

public:
	FrameTimer(const string& saveFile);
	~FrameTimer();
	void markUpdateDt();
	void markUpdateStart();
	void markUpdateFinished();
	void markRenderStart();
	void markRenderFinished();
	void addEntitiesMark(const int& entities);
	void persist(const bool& nextFile = true);
	void clear();

	static FrameTimer* GetInstance(const string& saveFile = "./default");
};
#endif