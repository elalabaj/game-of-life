#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include "TileMap.h"

class Board {
	static const int THREAD_COUNT = 4;
	std::thread threads[THREAD_COUNT];
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

