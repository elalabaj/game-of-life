#include "Simulation.h"
#include <stdio.h>

Simulation::Simulation(Board& board, int switchTime): board(board) {
    playing = false;
    totalTime = 0;
    this->switchTime = switchTime;
}

void Simulation::update(int deltaTime) {
    if (playing) {
        if (deltaTime >= switchTime) {
            board.nextTurn();
        }
        else {
            totalTime += deltaTime;
            if (totalTime >= switchTime) {
                totalTime -= switchTime;
                board.nextTurn();
            }
        }
    }
}

void Simulation::changeIsPlaying() {
    playing = !playing;
}
