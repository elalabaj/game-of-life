#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Simulation.h"

const unsigned int BOARD_WIDTH = sf::VideoMode::getDesktopMode().width;
const unsigned int BOARD_HEIGHT = sf::VideoMode::getDesktopMode().height;
const unsigned int CELL_SIZE = 7;

void zoomViewAt(sf::Vector2i pixel, sf::View& view, sf::RenderWindow& window, float zoom) {
	const sf::Vector2f beforeCoord{ window.mapPixelToCoords(pixel) };
	view.zoom(zoom);
	window.setView(view);
	const sf::Vector2f afterCoord{ window.mapPixelToCoords(pixel) };
	const sf::Vector2f offsetCoords{ beforeCoord - afterCoord };
	view.move(offsetCoords);
	window.setView(view);

	int width = window.getSize().x;
	int height = window.getSize().y;
	sf::Vector2f topLeftCoord = window.mapPixelToCoords(sf::Vector2i(0, 0));
	sf::Vector2f topRightCoord = window.mapPixelToCoords(sf::Vector2i(width - 1, 0));
	sf::Vector2f bottomLeftCoord = window.mapPixelToCoords(sf::Vector2i(0, height - 1));
	sf::Vector2f bottomRightCoord = window.mapPixelToCoords(sf::Vector2i(width - 1, height - 1));
	if (topLeftCoord.x < 0 || topLeftCoord.y < 0 ||
		topRightCoord.x >= BOARD_WIDTH || topRightCoord.y < 0 ||
		bottomLeftCoord.x < 0 || bottomLeftCoord.y >= BOARD_HEIGHT ||
		bottomRightCoord.x >= BOARD_WIDTH || bottomRightCoord.y >= BOARD_HEIGHT) {

		view.reset(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
	}
}

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game of Life");
	sf::View view(sf::FloatRect(0, 0, 800, 600));

	Board board(sf::Vector2u(BOARD_WIDTH, BOARD_HEIGHT), sf::Vector2u(CELL_SIZE, CELL_SIZE));
	Simulation simulation(board, 0);

	int deltaTime;
	sf::Clock clock;
	float zoomAmount = 1.1f;

	while (window.isOpen()) {
		deltaTime = clock.restart().asMilliseconds();

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				view.reset(sf::FloatRect(0, 0, event.size.width, event.size.height));
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left && !simulation.isPlaying()) {
					board.onMouseLeftClicked(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
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
				if (simulation.isPlaying()) break;
				if (event.mouseWheelScroll.delta > 0)
					zoomViewAt({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, view, window, (1.f / zoomAmount));
				else if (event.mouseWheelScroll.delta < 0)
					zoomViewAt({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, view, window, zoomAmount);
				break;
			}
		}

		simulation.update(deltaTime);

		window.setView(view);
		window.clear();
		board.draw(window);
		window.display();
	}

	return 0;
}