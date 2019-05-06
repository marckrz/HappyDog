#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Window.hpp>

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace sf;
using namespace std;

int main()
{

	
	RenderWindow window(VideoMode(480, 322), "HappyDog");

	Texture t;
	t.loadFromFile("images/480x322.png");
	if (!t.loadFromFile("images/480x322.png")) { cout << "error\n"; }

	Sprite s;
	s.setTexture(t);


	Event e;

	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape) { window.close(); }

		}


	}

	window.clear(Color::Black);
	window.draw(s);
	window.display();


	return 0;
}