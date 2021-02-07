#include "Cell.h"

Cell::Cell(sf::Vector2i gridPosition, bool state) {
	if (gridPosition.x >= 0 && gridPosition.y >= 0) {
		setPosition(gridPosition.x * SIZE, gridPosition.y * SIZE);
	}
	setSize(sf::Vector2f(SIZE, SIZE));
	setOutlineThickness(outlineThickness);
	setOutlineColor(outlineColor);
	setState(state);	
}

void Cell::setNextState(bool nextState) {
	this->nextState = nextState;
}

void Cell::setState(bool state) {
	this->state = state;
	if (state) setFillColor(aliveColor);
	else setFillColor(deadColor);
}

void Cell::changeState() {
	setState(!state);
}
