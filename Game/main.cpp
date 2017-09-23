#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	
    sf::RenderWindow window(sf::VideoMode(800, 800, 32), "SFML Vleis Invaders",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);    
    
    Game newGame(5);
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

		window.clear(sf::Color::White);

        // Move character on button press
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
		{
			newGame.movePlayerObject(-1);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
		{
			newGame.movePlayerObject(1);
		}
        
        newGame.DecrementBulletCooldown();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && newGame.getBulletCooldown() == 0) 
		{
			newGame.AddGameObject(gameObjectType::PlayerBullet);
            newGame.setBulletCooldown(20);
		}
        
        if (newGame.getClock().getElapsedTime().asSeconds() == 2.0f)
        {
            newGame.AddGameObject(gameObjectType::Enemy);
            cout << newGame.getGameObjectsVector().size() << endl;
            newGame.restartClock();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) 
		{
            newGame.AddGameObject(gameObjectType::Enemy);
		}
        
        newGame.ObjectCleanup();
        
        for (int i = 0u; i < newGame.getGameObjectsVector().size(); i++)
        {
            if (newGame.getGameObjectsVector()[i].getObjectType() == gameObjectType::PlayerBullet)
            {
                newGame.moveLineObject(i);
            }
            window.draw(newGame.getGameObjectsVector()[i].getObjectShape());
        }
        
        
        
        ///////////////////
        window.display();
		// end of current frame
    }

    return 0;
}

