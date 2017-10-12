#ifndef INTERFACE_H
#define INTERFACE_H

#include "keyboardInput.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>
#include <list>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::list;

/**
 * @class FileNotFound
 * @brief Throws and error if the files which are trying to be loaded cannot be found 
 */
class FileNotFound
{   };

/**
 * @class Interface
 * @breif Class which handles all interface functionality and makes use of SFML 2.3.2.
 * Interface deals predominantly with rendering the game to the window and handling user inputs.
 */
class Interface
{
public:
    /**
     * @brief Defailt Constructor.
     * Creates a new window and initialises private variables
     */
    Interface();
    
    /**
     * @brief Closes the SFML window.
     */
    void CloseWindow();
    
    /**
     * @brief Allows the Game class to know if the window is open.
     * @return bool true if the window is open and false otherwise
     */
    bool WindowOpen();
    
    /**
     * @brief Detects a user inputs during the game.
     * This function allows separation of the logic and interface layers by 
     * converting SFML inputs to a vector of enums to be passed back to the
     * Game class.
     */
    void ProcessGameEvents();
    
    /**
     * @brief Passes the Game class a vector of detected user inputs.
     * All detected inputs of a relevnt type are added to a vector of keyboard inputs.
     * @return vector of Enums containing the representation of user keyboard inputs.
     */
    vector<keyboardInput> GetGameEventsVector();
    
    /**
     * @brief Rrenders the splash screen on game start.
     */
    void SplashScreen();
    
    /**
     * @brief Renders the game screen animation during play.
     */
    void GameScreen();

    /**
     * @brief Renders the game over screen when the game is lost. 
     */
    void EndScreen();
    /**
     * @brief Allows rendered objects to be displayed on the screen.
     */
    void DisplayWindow();
    /**
     * @brief Renders each game object on the screen.
     * All game objects contained within the GameObjectsVector at the current 
     * time are rendered to the screen according to their type.
     * @param object - a shared pointer to the game object to be rendered.
     */
    void RenderGameObject(shared_ptr<GameObject> object);
    
    /**
     * @brief Renders the current and high scores to the window.
     * @param score -  integer value representing the current score that the player has achieved.
     * @param high_score - integer value representing the largest high score ever recorded.
     */
    void RenderText(const shared_ptr<int> score , const shared_ptr<int> high_score );
    
    /**
     * @brief Renders the visual representation of the number of lives the play has remaining.
     * @param numPlayerLives - integer value representing the current number of lives that the 
     * player has.
     */
    void RenderLives(const int numPlayerLives);
    /**
     * @brief Generates the vector of lives for the player on game start.
     * @param numPlayerLives - integer number of lives that the player starts the game with.
     * @param rectSize - desired size of the rectangles representing the payer lives.
     */
    void CreateLivesVector(const int numPlayerLives, float rectSize);
    /**
     * @brief Function responsible for setting the frame rate of the game.
     * Using the SFML clock, this function returns true if it is the correct time to 
     * render a new frame.
     * @return bool indicating if it is time to render the next frame of the game.
     */
    bool CheckClock();
    
private:

    static constexpr float SCREEN_HEIGHT = 800.0f;
    static constexpr float SCREEN_WIDTH = 800.0f;
    
    vector<keyboardInput> _gameEventVector;
    sf::RenderWindow _window;
    sf::Texture _startTexture;
    sf::Texture _gameTexture;
    sf::Texture _endTexture;
    sf::IntRect _rectSourceSprite;
    sf::Font _font;
    vector<sf::RectangleShape> _livesVector;
    sf::Clock _clock;
    bool _shotFired;
    int _frameCounter;
    int _playerLivesCounter;
    
    void LoadFiles();
    void ClearWindow();
    
};

#endif