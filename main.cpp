#include <SFML/Graphics.hpp>
#include "Board.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game of Life");

	Board board(sf::Vector2u(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					board.onMouseLeftClicked(sf::Mouse::getPosition(window));
				}
				break;
			}
		}

		window.clear();
		board.draw(window);
		window.display();
	}

	return 0;
}