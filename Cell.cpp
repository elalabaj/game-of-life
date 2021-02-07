#include "Cell.h"

Cell::Cell(sf::Vector2u gridPosition, bool state) {
	setPosition(gridPosition.x * SIZE, gridPosition.y * SIZE);
	setSize(sf::Vector2f(SIZE, SIZE));
	setOutlineThickness(outlineThickness);
	setOutlineColor(outlineColor);
	setState(state);	
}

void Cell::setState(bool state) {
	this->state = state;
	if (state) setFillColor(aliveColor);
	else setFillColor(deadColor);
}

void Cell::changeState() {
	setState(!state);
}
