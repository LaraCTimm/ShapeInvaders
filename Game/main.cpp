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
    
    const float _RAND_FLOAT_MAX = 150.0f;
    const float _RAND_FLOAT_MIN = 75.0f;

    bool playing = true;

    while(window.isOpen())
    {
        //window.setKeyRepeatEnabled(false); // doesnt seem to work
        //window.setKeyRepeatEnabled(false);
        
    // set repeat enabled to false to not allow holding down button to spawn more than one object
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
            
            /////////////////// HACK
            
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !newGame.getGeneratorFired()) 
//            {
//                newGame.AddGameObject(gameObjectType::LaserGenerator, 0);
//                newGame.setGeneratorFired(true);
//            }
//            
//            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && newGame.getGeneratorFired()) 
//            {
//                newGame.setGeneratorFired(false);
//            }
//            
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//            {
//                newGame.AddGameObject(gameObjectType::LaserGenerator, 0);
//            }

            newGame.DecrementCooldowns();
            newGame.SpawnGameObjects();
            newGame.CheckCollisions();
            newGame.ObjectCleanup();
            
            if (newGame.getGameObjectsVector().size() > 0 && newGame.getGameObjectsVector()[0]->getObjectType() != gameObjectType::Player)
            {
                playing = false;
                
                ///// DISPLAY GAME OVER HERE /////
            }
            
            // update Game Objects' positions and draw to the window
            for (int i = 0u; i < newGame.getGameObjectsVector().size(); i++)
            {
                if (newGame.getGameObjectsVector()[i]->getObjectType() != gameObjectType::Player)
                {
                    newGame.moveLineObject(i);
                }
                
                window.draw(newGame.getGameObjectsVector()[i]->getObjectShape());
            }
            
            ///////////////////
            window.display();
            // end of current frame
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) 
        {
            newGame = Game(5);
            playing = true;
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

