#include "Cell.h"

Cell::Cell(sf::Vector2u gridPosition, bool alive) {
	this->alive = alive;
	setPosition(gridPosition.x * SIZE, gridPosition.y * SIZE);
	setSize(sf::Vector2f(SIZE, SIZE));
	setOutlineThickness(outlineThickness);
	setOutlineColor(outlineColor);
	setColor();
}

void Cell::setColor() {
	if (alive) setFillColor(aliveColor);
	else setFillColor(deadColor);
}
