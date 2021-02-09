#include "Board.h"
#include <random>
#include <ctime>

Board::Board(sf::Vector2u windowSize, sf::Vector2u cellSize) {
	srand(time(NULL));

	this->cellSize = cellSize;

	width = (windowSize.x + cellSize.x - 1) / cellSize.x + 2;
	height = (windowSize.y + cellSize.y - 1) / cellSize.y + 2;

	cells.resize(width);
	next.resize(width);
	for (int i = 0; i < width; i++) {
		cells[i].resize(height);
		next[i].resize(height);
	}

	map.load(cellSize, width - 2, height - 2);
}

void Board::draw(sf::RenderWindow& window) {
	window.draw(map);
}

void Board::onMouseLeftClicked(sf::Vector2i mousePosition) {
	int x = mousePosition.x / cellSize.x + 1;
	int y = mousePosition.y / cellSize.y + 1;
	setState(x, y, !cells[x][y]);
}

void Board::randomConfiguration() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			setState(i, j, rand() % 2);
		}
	}
}

void Board::reset() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			setState(i, j, false);
		}
	}
}

void Board::nextTurn() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			next[i][j] = checkNextState(i, j);
		} 
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			setState(i, j, next[i][j]);
		}
	}
}

void Board::setState(int x, int y, bool state) {
	cells[x][y] = state;
	if (x > 0 && x < width - 1 && y > 0 && y < height - 1) {
		map.setColor(x - 1, y - 1, cells[x][y] ? sf::Color::White : sf::Color::Black);
	}
}

bool Board::checkNextState(int x, int y) {
	int aliveNeighbours = 0;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 && dy == 0) continue;

			int i = x + dx;
			int j = y + dy;
			if (i < 0 || i >= width || j < 0 || j >= height) continue;

			if (cells[i][j]) aliveNeighbours++;
		}
	}

	if (cells[x][y]) {
		if (aliveNeighbours == 2 || aliveNeighbours == 3) {
			return true;
		}
	}
	else {
		if (aliveNeighbours == 3) {
			return true;
		}
	}

	return false;
}
