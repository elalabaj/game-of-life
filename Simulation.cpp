#include "Simulation.h"
#include <stdio.h>

Simulation::Simulation(Board& board, float switchTime): board(board) {
    playing = false;
    totalTime = 0;
    this->switchTime = switchTime;
}

void Simulation::update(float deltaTime) {
    if (playing) {
        totalTime += deltaTime;
        if (totalTime >= switchTime) {
            totalTime -= switchTime;
            board.nextTurn();
        }
    }
}

void Simulation::changeIsPlaying() {
    playing = !playing;
}
