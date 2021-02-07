#pragma once

#include <SFML/Graphics.hpp>

class Cell: public sf::RectangleShape {
public:
	static const unsigned int SIZE = 10;
	const sf::Color aliveColor = sf::Color::White;
	const sf::Color deadColor = sf::Color(100, 100, 100);
	const sf::Color outlineColor = sf::Color::Black;
	const float outlineThickness = -0.5f;

private:
	bool alive;

public:
	Cell(sf::Vector2u gridPosition, bool alive);

	void setColor();
};