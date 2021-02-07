#include "Board.h"
#include <random>

Board::Board(sf::Vector2u windowSize) {
	createNewGrid(windowSize);
}

void Board::createNewGrid(sf::Vector2u windowSize) {
	//same as std::ceil((float) windowSize.x / Cell::SIZE);
	width = (windowSize.x + Cell::SIZE - 1) / Cell::SIZE;
	//same as std::ceil((float) windowSize.y / Cell::SIZE);
	height = (windowSize.y + Cell::SIZE - 1) / Cell::SIZE;

	cells.clear();
	for (int i = 0; i < width; i++) {
		cells.push_back(std::vector<Cell>());
		for (int j = 0; j < height; j++) {
			cells[i].push_back(Cell(sf::Vector2u(i, j), false));
		}
	}
}

void Board::draw(sf::RenderWindow& window) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			window.draw(cells[i][j]);
		}
	}
}

void Board::onMouseLeftClicked(sf::Vector2i mousePosition) {
	sf::Vector2i cellPosition = mousePosition / (int) Cell::SIZE;
	cells[cellPosition.x][cellPosition.y].changeState();
}
