#include "Board.h"
#include <random>

Board::Board(sf::Vector2u windowSize) {
	//same as std::ceil((float) windowSize.x / Cell::SIZE);
	width = (windowSize.x + Cell::SIZE - 1) / Cell::SIZE;
	//same as std::ceil((float) windowSize.y / Cell::SIZE);
	height = (windowSize.y + Cell::SIZE - 1) / Cell::SIZE;

	cells.clear();
	for (int i = 0; i < width; i++) {
		cells.push_back(std::vector<Cell>());
		for (int j = 0; j < height; j++) {
			Cell cell(sf::Vector2u(i, j), false);
			cells[i].push_back(cell);
		}
	}
}

void Board::draw(sf::RenderWindow& window) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			//window.draw(cells[i][j]);
			cells[i][j].draw(window);
		}
	}
}

void Board::onMouseLeftClicked(sf::Vector2i mousePosition) {
	sf::Vector2i cellPosition = mousePosition / (int) Cell::SIZE;
	cells[cellPosition.x][cellPosition.y].changeState();
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
