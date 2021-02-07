#include "Simulation.h"
#include <stdio.h>

Simulation::Simulation(Board& board, float switchTime): board(board) {
    totalTime = 0;
    this->switchTime = switchTime;
}

void Simulation::update(float deltaTime) {
    totalTime += deltaTime;
    if (totalTime >= switchTime) {
        totalTime -= switchTime;
        board.nextTurn();
    }
}
