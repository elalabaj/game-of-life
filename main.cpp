#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Simulation.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game of Life");

	Board board(sf::Vector2u(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));
	Simulation simulation(board, 1000);

	float deltaTime;
	sf::Clock clock;

	while (window.isOpen()) {
		deltaTime = clock.restart().asMilliseconds();

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
				if (event.mouseButton.button == sf::Mouse::Left && !simulation.isPlaying()) {
					board.onMouseLeftClicked(sf::Mouse::getPosition(window));
				}
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space) {
					simulation.changeIsPlaying();
				}
				if (event.key.code == sf::Keyboard::R && !simulation.isPlaying()) {
					board.randomConfiguration();
				}
				if (event.key.code == sf::Keyboard::Delete) {
					if (simulation.isPlaying()) {
						simulation.changeIsPlaying();
					}
					board.reset();
				}
				break;
			case sf::Event::MouseWheelScrolled:
				simulation.changeSwitchTime(event.mouseWheelScroll.delta * -50);
			}
		}

		simulation.update(deltaTime);

		window.clear();
		board.draw(window);
		window.display();
	}

	return 0;
}