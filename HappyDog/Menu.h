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

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; };

private:
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];

};

Menu::Menu(float width, float height)
{
	//if (!loadFromFile("arial.ttf"))
	//{
	//	//handle error
	//}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Green);
	menu[0].setString("GRAJ");
	menu[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	//menu[1].setColor(2);
	menu[1].setString("Opcje");
	menu[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	//menu[2].setColor(3);
	menu[2].setString("Wyjdz");
	menu[2].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Menu::~Menu()
{

}

void Menu::draw(RenderWindow & window)
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
		//menu[selectedItemIndex].setColor(Color::White);
		selectedItemIndex--;
		//menu[selectedItemIndex].setColor(Color::Red);
	}
}


void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		//menu[selectedItemIndex].setColor(Color::White);
		selectedItemIndex++;
		//menu[selectedItemIndex].setColor(Color::Red);
	}
}
