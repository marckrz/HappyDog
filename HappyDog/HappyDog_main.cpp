#include <SFML/Graphics.hpp>
//#include <math.h>
#include <SFML/Window.hpp>
#include "Menu.h"

#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

//int main()
//{
	//:))))))))))))))))))))
	//
	//RenderWindow window(VideoMode(480, 322), "HappyDog");

	//Texture t;
	//t.loadFromFile("images/480x322.png");
	//if (!t.loadFromFile("images/480x322.png")) { cout << "error\n"; }

	//Sprite s;
	//s.setTexture(t);


	//Event e;

	//while (window.isOpen())
	//{
	//	while (window.pollEvent(e))
	//	{
	//		if (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape) { window.close(); }

	//	}


	//}

	//window.clear(Color::Black);
	//window.draw(s);
	//window.display();

int main()
{
	RenderWindow window(VideoMode(800, 800), "HAPPY DOG");

	Menu menu(window.getSize().x, window.getSize().y);
	
	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case::Event::KeyReleased:

					switch (event.key.code)
					{
					case Keyboard::Up:
						menu.MoveUp();
						break;

					case Keyboard::Down:
						menu.MoveDown();
						break;

					case Keyboard::Return:
						switch (menu.GetPressedItem())
						{
						case 0:
							cout << "Nacisnieto przycisk GRAJ" << endl;
								break;

						case 1:
							cout << "Nacisnieto przycisk OPCJE" << endl;
								break;


						case 3:
							window.close();
								break;

							
						}
							break;
					}
			case Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();
		menu.draw(window);
		window.display();
	}
}