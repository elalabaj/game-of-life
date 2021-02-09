#include "TileMap.h"

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(vertices, states);
}

void TileMap::load(sf::Vector2u tileSize, int width, int height) {
	this->width = width;
	this->height = height;
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(width * height * 4);

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			sf::Vertex* quad = &vertices[(i + j * width) * 4];
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
			setColor(i, j, sf::Color::Black);
		}
	}
}

void TileMap::setColor(int x, int y, sf::Color color) {
	sf::Vertex* quad = &vertices[(x + y * width) * 4];
	for (int i = 0; i < 4; i++) {
		quad[i].color = color;
	}
}
