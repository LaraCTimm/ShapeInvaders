#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if(!font.loadFromFile("EraserRegular.ttf"))
	{
		//handle error
	}
	text[0].setFont(font);
	text[0].setColor(sf::Color::Cyan);
	text[0].setString("Play");
	text[0].setPosition(sf::Vector2f(width/2,height/4));
}

MainMenu::~MainMenu()
{
	
}

void MainMenu::draw(sf::RenderWindow &window)
{
	window.draw(text[0]);
}