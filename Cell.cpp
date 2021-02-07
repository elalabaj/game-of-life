#include "Cell.h"

Cell::Cell(sf::Vector2u gridPosition, bool state) {
	setPosition(gridPosition.x * SIZE, gridPosition.y * SIZE);
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

void Cell::draw(sf::RenderWindow& window) {
	window.draw(*this);
}
