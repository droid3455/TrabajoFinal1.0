#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Monedas.h"

class Player {
public:
	Player(sf::Vector2f size) {
		player.setSize(size);
		player.setFillColor(sf::Color::Green);
	}

	void drawTo(sf::RenderWindow &window) {
		window.draw(player);
	}

	void fijarPos(sf::Vector2f nuevaPos) {
		player.setPosition(nuevaPos);
	}



private:
	sf::RectangleShape player;
};