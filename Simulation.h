#pragma once

#include "Board.h"

class Simulation {
	bool playing;
	float totalTime;
	float switchTime;
	Board& board;

public:
	Simulation(Board& board, float switchTime);

	bool isPlaying() { return playing; }
	void changeSwitchTime(float delta) { switchTime = std::max(0.f, switchTime + delta); }

	void update(float deltaTime);
	void changeIsPlaying();
};

