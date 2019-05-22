#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 3


using namespace sf;

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex };

private:
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];

};

Menu::Menu(float width, floa height)
{
	if (!fontloadFromFile("arial.ttf"))
	{
		//handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(Color::Red);
	menu[0].setString("Graj");
	menu[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(Color::White);
	menu[1].setString("Opcje");
	menu[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(Color::White);
	menu[2].setString("Wyjdz");
	menu[2].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Menu::~Menu()
{

}

void Menu::draw(RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}

}


void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(Color::Red);
	}
}


void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS )
	{
		menu[selectedItemIndex].setColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(Color::Red);
	}
}



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
				case::Event::KeyReleased;

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