#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
using std::cout;
using std::endl;
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int main()
{
    
	
    sf::RenderWindow window(sf::VideoMode(800, 800, 32), "SFML Vleis Invaders",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);    
    
    Game newGame(5);
    
    //srand(time(NULL));
    const float _RAND_FLOAT_MAX = 150.0f;
    const float _RAND_FLOAT_MIN = 75.0f;
    //srand (time(0));         // seed randomness for enemy spawning

    bool playing = true;
    bool spawned = false;
    window.setKeyRepeatEnabled(false);

    while(window.isOpen())
    {
    // set repeat enabled to false to not aallow holding down button to spawn more than one object
        while (playing)//window.isOpen())
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

            // Move player on button press
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
            {
                newGame.movePlayerObject(-1);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
            {
                newGame.movePlayerObject(1);
            }

            // Fire a bullet
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !newGame.getShotFired()) 
            {
                newGame.AddGameObject(gameObjectType::PlayerBullet, 0);
                newGame.setShotFired(true);
            }
            
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && newGame.getShotFired()) 
            {
                newGame.setShotFired(false);
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !spawned) 
            {
                spawned = true;
                newGame.AddGameObject(gameObjectType::LaserGenerator, 0);
            }
            
            
            newGame.decrementEnemyCooldown();
            newGame.decrementAsteriodCooldown();
            newGame.decrementBulletCooldowns();
            
            if (newGame.getEnemyCooldown() <= 0)
            {
                newGame.AddGameObject(gameObjectType::Enemy, 0);
                newGame.setEnemyCooldown(newGame.generateRandomNumber(75.0f, 150.0f));
            }
            
            if (newGame.getAsteriodCooldown() <= 0)
            {
                newGame.AddGameObject(gameObjectType::Asteriod, 0);
                newGame.setAsteriodCooldown(newGame.generateRandomNumber(100.0f, 150.0f));
            }
            
            newGame.CheckCollisions();
            newGame.ObjectCleanup();
            
            if (newGame.getGameObjectsVector().size() > 0 && newGame.getGameObjectsVector()[0].getObjectType() != gameObjectType::Player)
            {
                playing = false;//return 0;
                
                ///// DISPLAY GAME OVER HERE /////
            }
            
            for (int i = 0u; i < newGame.getGameObjectsVector().size(); i++)
            {
                if (newGame.getGameObjectsVector()[i].getObjectType() != gameObjectType::Player)
                {
                    newGame.moveLineObject(i);
                }
                
                window.draw(newGame.getGameObjectsVector()[i].getObjectShape());
                
            }
            
            //(auto z = begin(even_numbers); z != end(even_numbers); ++z
            //// FIGURE OUT ITERATORS //
            //for (auto z = newGame.getLaserPointerVector().begin(); z != newGame.getLaserPointerVector().end(); z++)
            for (int i = 0; i < newGame.getLaserPointerVector().size(); i++)

            {
                newGame.movePointerLineObject(i);
                window.draw(newGame.getLaserPointerVector()[i]->getObjectShape());
            }
            
            
            ///////////////////
            window.display();
            // end of current frame
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) 
        {
            newGame = Game(5);
            playing = true;
            spawned = false;
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
        {
            window.close();
        }
        
        sf::Event event;
            
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    return 0;
}

