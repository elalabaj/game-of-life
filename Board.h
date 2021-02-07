#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.h"

class Board {
	int width;
	int height;
	std::vector<std::vector<Cell>> cells;

public:
	Board(sf::Vector2u windowSize);

	void createNewGrid(sf::Vector2u windowSize);
	void draw(sf::RenderWindow& window);
};

