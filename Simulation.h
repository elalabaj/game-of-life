#pragma once

#include "Board.h"

class Simulation {
	bool playing;
	int totalTime;
	int switchTime;
	Board& board;

public:
	Simulation(Board& board, int switchTime);

	bool isPlaying() { return playing; }

	void update(int deltaTime);
	void changeIsPlaying();
};

