#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "TileMap.h"

class Board {
	int width;
	int height;
	sf::Vector2u cellSize;
	std::vector<std::vector<bool>> cells;
	std::vector<std::vector<bool>> next;
	TileMap map;

public:
	Board(sf::Vector2u windowSize, sf::Vector2u cellSize);

	void draw(sf::RenderWindow& window);
	void onMouseLeftClicked(sf::Vector2f coords);
	void randomConfiguration();
	void reset();
	void nextTurn();

private:
	void setState(int x, int y, bool state);
	bool checkNextState(int x, int y);
};

