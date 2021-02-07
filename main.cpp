#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game of Life");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}
	}

	return 0;
}