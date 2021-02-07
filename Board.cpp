#include "Board.h"
#include <random>

Board::Board(sf::Vector2u windowSize) {
	width = (windowSize.x + Cell::SIZE - 1) / Cell::SIZE + 2;
	height = (windowSize.y + Cell::SIZE - 1) / Cell::SIZE + 2;

	cells.clear();
	for (int i = 0; i < width; i++) {
		cells.push_back(std::vector<Cell>());
		for (int j = 0; j < height; j++) {
			Cell cell(sf::Vector2i(i - 1, j - 1), false);
			cells[i].push_back(cell);
		}
	}
}

void Board::draw(sf::RenderWindow& window) {
	for (int i = 1; i < width - 1; i++) {
		for (int j = 1; j < height - 1; j++) {
			window.draw(cells[i][j]);
		}
	}
}

void Board::onMouseLeftClicked(sf::Vector2i mousePosition) {
	sf::Vector2i cellPosition = mousePosition / (int) Cell::SIZE;
	cells[cellPosition.x + 1][cellPosition.y + 1].changeState();
}

void Board::nextTurn() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			cells[i][j].setNextState(checkNextState(i, j));
		} 
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			cells[i][j].setState(cells[i][j].getNextState());
		}
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

			if (cells[i][j].getState()) aliveNeighbours++;
		}
	}

	if (cells[x][y].getState()) {
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
