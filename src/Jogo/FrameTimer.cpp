//
//  FrameTimer.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma.
//  Copyright © 2022 Matheus Kunnen Ledesma. All rights reserved.
//

#include "./FrameTimer.hpp"

FrameTimer* FrameTimer::defaultInstance = nullptr;

FrameTimer::FrameTimer(const string& saveFile) :
	saveFile(saveFile),
	fileCount(0),
	mainClock(),
	updateClock(),
	renderClock(),
	totalFrameTimes(),
	updateFrameTimes(),
	renderFrameTimes(),
	totalEntities(),
	gArquivos(saveFile + "-" + std::to_string(this->fileCount)) {
	this->gArquivos.setFilename(saveFile + "-" + std::to_string(this->fileCount) + ".json");

}

FrameTimer::~FrameTimer() {
}
void FrameTimer::markUpdateDt() {
	this->totalFrameTimes.push_back(this->mainClock.getElapsedTime().asSeconds());
	this->mainClock.restart();
};

void FrameTimer::markUpdateStart() {
	this->updateClock.restart();
};

void FrameTimer::markUpdateFinished() {
	this->updateFrameTimes.push_back(this->updateClock.restart().asSeconds());
};

void FrameTimer::markRenderStart() {
	this->renderClock.restart();
};

void FrameTimer::markRenderFinished() {
	this->renderFrameTimes.push_back(this->updateClock.restart().asSeconds());
};

void FrameTimer::addEntitiesMark(const int& entities) {
	this->totalEntities.push_back(entities);
}

void FrameTimer::persist(const bool& nextFile) {
	/*cout << "Guardando" << endl;
	int count = this->updateFrameTimes.size();
	for (int i = 0; i < count; i++)
		cout << this->updateFrameTimes[i] << endl;*/
	json data;
	data["total_frame_time"] = this->totalFrameTimes;
	data["update_frame_time"] = this->updateFrameTimes;
	data["render_frame_time"] = this->renderFrameTimes;
	data["entities_frame"] = this->totalEntities;
	this->gArquivos.setData(data);
	this->gArquivos.save();
	if (nextFile)
		this->gArquivos.setFilename(this->saveFile + "-" + std::to_string(++this->fileCount) + ".json");

}

void FrameTimer::clear() {
	this->totalFrameTimes.clear();
	this->updateFrameTimes.clear();
	this->renderFrameTimes.clear();
	this->totalEntities.clear();
	this->mainClock.restart();
	this->updateClock.restart();
	this->renderClock.restart();
}

FrameTimer* FrameTimer::GetInstance(const string& saveFile) {
	if (FrameTimer::defaultInstance == nullptr)
		FrameTimer::defaultInstance = new FrameTimer(saveFile);
	return FrameTimer::defaultInstance;
}