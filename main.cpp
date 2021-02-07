#include <SFML/Graphics.hpp>
#include "Board.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game of Life");

	Board board(window.getSize());

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}

		window.clear();
		board.draw(window);
		window.display();
	}

	return 0;
}