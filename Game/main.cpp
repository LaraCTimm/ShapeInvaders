#include <SFML/Graphics.hpp>
#include "Game.h"

#include "MainMenu.h"
#include <iostream>
using std::cout;
using std::endl;
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int main()
{
	
    sf::RenderWindow window(sf::VideoMode(800, 800, 32), "Vleis Invaders",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);    
    
	MainMenu menu(window.getSize().x, window.getSize().y);
	
    Game newGame(5);

    //bool playing = false, menuScreen = true, endScreen = false;
	int gameState = 1; // 1 - Opening Menu; 2 - Game; 3 - Game Over Screen

    while(window.isOpen())
    {
		
		sf::Event event;
		
		// Main menu - 'Splash screen'
		while(gameState == 1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				gameState = 2;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
				return 0;
			}
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }
			sf::Texture texture;
			if (!texture.loadFromFile("mainMenu.png")){}
			sf::Sprite background(texture);
			window.draw(background);
			//window.clear();
			//menu.draw(window);
			window.display();
		}
		
		// Game over screen
		while(gameState == 3)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				gameState = 2;
			}
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
				return 0;
			}
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }
			sf::Texture endTexture;
			if (!endTexture.loadFromFile("endScreen.png")){}
			sf::Sprite background(endTexture);
			window.draw(background);
			window.display();
		}
		
        //window.setKeyRepeatEnabled(false); // doesnt seem to work
        
    // set repeat enabled to false to not allow holding down button to spawn more than one object
        while (gameState == 2)//window.isOpen())
        {
            sf::Event event;
            
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
					return 0;
                }
            }

            
            window.clear(sf::Color::White);

            // Move player on button press
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
            {
                newGame.MovePlayerObject(-1);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
            {
                newGame.MovePlayerObject(1);
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

            newGame.DecrementCooldowns();
            newGame.CreateGameObjects();
            newGame.CheckCollisions();
            newGame.ObjectCleanup();
            
            
            if (newGame.getGameObjectsVector().size() > 0 && newGame.getGameObjectsVector()[0]->getObjectType() != gameObjectType::Player)
            {
                newGame.SetNewHighScore();
                gameState = 3;
                ///// DISPLAY GAME OVER HERE /////
            }
            
            // update Game Objects' positions and draw to the window
            for (int i = 0u; i < newGame.getGameObjectsVector().size(); i++)
            {
                if (newGame.getGameObjectsVector()[i]->getObjectType() != gameObjectType::Player)
                {
                    newGame.MoveLineObject(i);
                }
                
                window.draw(newGame.getGameObjectsVector()[i]->getObjectShape());
            }
            
            for (int i = 0; i < newGame.getGameObjectsVector()[0]->getHealth(); i++)
            {
                window.draw(newGame.getLivesVector()[i]);
            }
            
//            sf::Font font;
//            if (!font.loadFromFile("charter-bt-roman-5933e85194471.ttf"))
//            {
//                // error...
//            }
//            sf::Text score;
//            score.setString("Hello");
//            //charter-bt-roman-5933e85194471.ttf
//            score.setFont(font);
//            score.setCharacterSize(100);
//            score.setColor(sf::Color::Black);
//            //_currentScoreText.setPosition(sf::Vector2f(SCREEN_WIDTH - 100, 0 + 30));
//            
//            score.setPosition(sf::Vector2f(400, 400));
//            window.draw(score);   
//            std::string datString(newGame.getCurrentScoreText().getString());
//            cout << datString << endl;
            
            newGame.CheckScores();
            
            sf::Text currentScore(newGame.getCurrentScoreText());
            sf::Text highScore(newGame.getHighScoreText());
            sf::Font font;
            if (!font.loadFromFile("charter-bt-roman.ttf"))
            { 
                // error...
            }
            currentScore.setFont(font);
            highScore.setFont(font);
            
            std::string newString1 = "Score: " + std::to_string(*(newGame.getScore()));
            currentScore.setString(newString1);
            
            std::string newString2 = "High Score: " + std::to_string(*(newGame.getHighScore()));
            highScore.setString(newString2);
            
            window.draw(currentScore);
            window.draw(highScore);
            
            ///////////////////
            window.display();
            // end of current frame
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) 
        {
            newGame = Game(5);
            gameState = 2;
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
        {
            window.close();
        }
         
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

