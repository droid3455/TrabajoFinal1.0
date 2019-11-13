#include  <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Monedas.h"

using namespace sf;
using namespace std;
int main()
{
	RenderWindow window;
	window.create(VideoMode(1280, 720), "Prototipo1", Style::Titlebar | Style::Close);

	//Objeto jugador

	/*
	Player player({ 40,40 });
	player.fijarPos({ 0,500 });
	*/

	sf::RectangleShape jugador(sf::Vector2f(40,40));
	jugador.setPosition(0, 0);
	jugador.setFillColor(Color::Blue);

	//Objeto moneda

	vector<Moneda*> monedaVec;

	Moneda moneda({ 20,20 });
	Moneda moneda2({ 20,20 });
	monedaVec.push_back(&moneda);
	monedaVec.push_back(&moneda2);

	moneda.fijarPos({ 300,300 });
	moneda2.fijarPos({ 400,400 });

	//Variables de gravedad

	const int alturaPiso = 680;
	const float gravity = 0.5;
	float velocidadMov = 1.0f, velocidadSalto = 5.0f;
	Vector2f velocidad(Vector2f(0, 0));



	//Bucle principal

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			switch (event.type) {

			case Event::Closed:window.close();

			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			velocidad.x = velocidadMov;
		}

		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			velocidad.x = -velocidadMov;
		}
		else
			velocidad.x = 0;
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			velocidad.y = -velocidadSalto;
		}

		if (jugador.getPosition().y + jugador.getSize().y < alturaPiso || velocidad.y < 0) {
			velocidad.y = velocidad.y + gravity;
		}
		else {
			jugador.setPosition(jugador.getPosition().x, alturaPiso - jugador.getSize().y);
			velocidad.y = 0;
		}

		jugador.move(velocidad.x, velocidad.y);

		
		
		window.clear();
		window.draw(jugador);
		moneda.drawTo(window);
		moneda2.drawTo(window);
		window.display();
	}

	return 0;
}
 