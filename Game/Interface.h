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

class FileNotFound
{   };

class Interface
{
public:

    static constexpr int NUM_FRAMES = 8;


    Interface();
    
    int CloseWindow();
    
    bool WindowOpen();
        
    void ProcessGameEvents();
    
    vector<keyboardInput> GetGameEventsVector();
    
    void SplashScreen();
        
    void GameScreen();

    void EndScreen();
    
    void DisplayWindow();
    
    void RenderGameObject(shared_ptr<GameObject> object);
    
    void RenderText(const shared_ptr<int> score , const shared_ptr<int> high_score );
    
    void RenderLives(const int numPlayerLives);
    
    void CreateLivesVector(const int numPlayerLives, float rectSize);
    
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