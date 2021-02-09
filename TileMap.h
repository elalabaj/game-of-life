#pragma once

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable {
	int width;
	int height;
	sf::VertexArray vertices;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	TileMap(sf::Vector2u tileSize, int width, int height);

	void load(sf::Vector2u tileSize, int width, int height);
	void setColor(int i, int j, sf::Color color);
};

