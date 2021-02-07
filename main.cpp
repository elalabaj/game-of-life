#include <SFML/Graphics.hpp>
#include "Board.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game of Life");

	Board board(window.getSize());

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				board.createNewGrid(window.getSize());
				break;
			}
		}

		window.clear();
		board.draw(window);
		window.display();
	}

	return 0;
}