#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Moneda {
public:
	Moneda(sf::Vector2f size) {
		moneda.setSize(size);
		moneda.setFillColor(sf::Color::Yellow);
	}

	void drawTo(sf::RenderWindow &window) {
		window.draw(moneda);
	}

	sf::FloatRect getGlobalBounds() {
		return moneda.getGlobalBounds();
	}

	void fijarPos(sf::Vector2f nuevaPos) {
		moneda.setPosition(nuevaPos);
	}
private:
	sf::RectangleShape moneda;
};