#pragma once

#include "Board.h"

class Simulation {
	float totalTime;
	float switchTime;
	Board board;

public:
	Simulation(Board& board, float switchTime);

	void update(float deltaTime);
};

