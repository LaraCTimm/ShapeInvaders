#include "Interface.h"

Interface::Interface()
: _window(sf::VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH), "Shape Invaders", sf::Style::Titlebar | sf::Style::Close)
, _shotFired(false)
, _rectSourceSprite(0,0,800,800)
, _frameCounter(0)
{
    _clock.restart();
    LoadFiles();
}

void Interface::LoadFiles()
{
    if(!_startTexture.loadFromFile("mainMenu_new.png"))
        throw FileNotFound();
    if(!_gameTexture.loadFromFile("backgroundSprite16.png"))
        throw FileNotFound();
    if(!_endTexture.loadFromFile("endScreen.png"))
        throw FileNotFound();
    if(!_font.loadFromFile("BADABB__.ttf"))
        throw FileNotFound();
}

void Interface::CreateLivesVector(const int numPlayerLives, float rectSize)
{
    _playerLivesCounter = numPlayerLives;
    for (int i = 0; i < numPlayerLives; i++)
    {
        sf::RectangleShape lifeRect(sf::Vector2f(rectSize, rectSize));
        lifeRect.setOutlineThickness(3);
        lifeRect.setOutlineColor(sf::Color::Blue);
        lifeRect.setFillColor(sf::Color::Black);
        lifeRect.setOrigin(sf::Vector2f(rectSize/2, rectSize/2));
        lifeRect.setPosition(rectSize*1.5 + rectSize*1.75*i, SCREEN_HEIGHT - rectSize*1.5);
        _livesVector.push_back(lifeRect);
    }
}

void Interface::CloseWindow()
{
    _window.close();
}

bool Interface::WindowOpen()
{
    bool open = _window.isOpen();
    return open;
}

vector<keyboardInput> Interface::GetGameEventsVector()
{
    return _gameEventVector;
}

void Interface::ProcessGameEvents()
{
    _gameEventVector.clear();
    
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _gameEventVector.push_back(keyboardInput::close_window);
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        _gameEventVector.push_back(keyboardInput::press_enter);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        _gameEventVector.push_back(keyboardInput::press_esc);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
    {
        _gameEventVector.push_back(keyboardInput::press_up);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
    {
        _gameEventVector.push_back(keyboardInput::press_down);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        _gameEventVector.push_back(keyboardInput::press_space);
    }
    
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        _gameEventVector.push_back(keyboardInput::release_space);
    }
}


void Interface::SplashScreen()
{
    sf::Sprite background(_startTexture);
    ClearWindow();
    _window.draw(background);
    _window.display();
}


void Interface::GameScreen()
{
    //ClearWindow();
    _window.clear(sf::Color::Black);
    sf::Sprite background(_gameTexture);
    _frameCounter++;
    
    if (_frameCounter%200 == 0)
    {
        _frameCounter = 0;
        if (_rectSourceSprite.left == 12000) {
            _rectSourceSprite.left = 0;
        }
        else {
            _rectSourceSprite.left += 800;
        }
    }
    
    background.setTextureRect(_rectSourceSprite);
    _window.draw(background);

}

void Interface::EndScreen()
{
    sf::Sprite background(_endTexture);
    ClearWindow();
    _window.draw(background);
    _window.display();
}

void Interface::ClearWindow()
{
    _window.clear(sf::Color::White);
}

void Interface::DisplayWindow()
{
    _window.display();
}


void Interface::RenderGameObject(shared_ptr<GameObject> object)
{
    sf::RectangleShape _rect;
    sf::CircleShape _hexagon;
    sf::CircleShape _triangle;
    

    float xCoord = object->getXCoord();
    float yCoord = object->getYCoord();
    float height = object->getObjectHeight();
    float width = object->getObjectWidth();
    float scale = object->getScale();
    float angle = object->getAngle();
    
    float outlineThickness;
    sf::Color outlineColor;
    sf::Color fillColor;
    
    
    switch (object->getObjectType())
    {
    
    case gameObjectType::Player:
    {
        sf::RectangleShape _rect;
        outlineThickness = 3.0f;
        outlineColor = sf::Color(24,0,255);
        fillColor = sf::Color(24,0,255);
        break;
    }
    case gameObjectType::PlayerBullet:
    {
        sf::RectangleShape _rect;
        outlineThickness = 3.0f;
        outlineColor = sf::Color(255,38,0);
        fillColor = sf::Color(255,38,0);
        break;
    }    
    case gameObjectType::Enemy:
    {
        sf::RectangleShape _rect;
        outlineThickness = 3.0f;
        outlineColor = sf::Color(0,255,65);
        fillColor = sf::Color(0,255,65);
        break;
    }    
    case gameObjectType::EnemyBullet:
    {
        sf::RectangleShape _rect;
        outlineThickness = 3.0f;
        outlineColor = sf::Color::White;
        fillColor = sf::Color::White;
        break;
    }    
    case gameObjectType::Asteriod:
    {
        float hexRaduis = height*2/3;
        sf::CircleShape _hexagon(hexRaduis, 6);
        _hexagon.setOrigin(sf::Vector2f(hexRaduis,hexRaduis));
        _hexagon.setRotation(angle);
        _hexagon.setPosition(sf::Vector2f(xCoord, yCoord));
        outlineThickness = 3.0f;
        outlineColor = sf::Color::Red;
        fillColor = sf::Color::Red;
        _hexagon.setOutlineThickness(outlineThickness);
        _hexagon.setOutlineColor(outlineColor);
        _hexagon.setFillColor(fillColor);
        _window.draw(_hexagon);
        break;
    }
        
    case gameObjectType::ArcSegment:
    {
        sf::RectangleShape _rect;
        outlineThickness = 3.0f;
        outlineColor = sf::Color(255,255,50);
        fillColor = sf::Color(255,255,50);
        break;
    }    
    case gameObjectType::LaserGenerator:
    {
        sf::RectangleShape _rect;
        outlineThickness = 3.0f;
        outlineColor = sf::Color(255,52,0);
        fillColor = sf::Color(255,52,0);
        break;
    }    
    case gameObjectType::Satellite:
    {
        float triRaduis = height+5;//*2/3;
        sf::CircleShape _triangle(triRaduis, 3);
        _triangle.setOrigin(sf::Vector2f(triRaduis,triRaduis));
        _triangle.setRotation(angle+90);
        _triangle.setPosition(sf::Vector2f(xCoord, yCoord));
        outlineThickness = 2.0f;
        outlineColor = sf::Color(182,0,255);
        fillColor = sf::Color(182,0,255);    
        _triangle.setOutlineThickness(outlineThickness);
        _triangle.setFillColor(outlineColor);
        _triangle.setOutlineColor(fillColor);
        _window.draw(_triangle);
        break;
    }    
    default:
        break;
    }
    
    _rect.setSize(sf::Vector2f(scale*width, scale*height));
    _rect.setOrigin(sf::Vector2f(scale*width/2, scale*height/2));
    _rect.setRotation(angle);
    _rect.setPosition(sf::Vector2f(xCoord, yCoord));
    _rect.setOutlineThickness(outlineThickness);
    _rect.setOutlineColor(outlineColor);
    _rect.setFillColor(fillColor);

    _window.draw(_rect);
        
}

void Interface::RenderText(shared_ptr<int> score, shared_ptr<int> high_score)
{   
    sf::Text _currentScoreText;
    sf::Text _highScoreText;
    
    std::string scoreString = "Score: " + std::to_string(*score);
    _currentScoreText.setString(scoreString);
    _currentScoreText.setCharacterSize(40);
    _currentScoreText.setColor(sf::Color::White);
    _currentScoreText.setPosition(sf::Vector2f(30, 30));
    _currentScoreText.setFont(_font);
    
    std::string highScoreString = "High Score: " + std::to_string(*high_score);
    _highScoreText.setString(highScoreString);
    _highScoreText.setCharacterSize(40);
    _highScoreText.setColor(sf::Color::White);
    _highScoreText.setPosition(sf::Vector2f(SCREEN_WIDTH-300, 30));
    _highScoreText.setFont(_font);
    
    _window.draw(_currentScoreText);
    _window.draw(_highScoreText);
    
}

void Interface::RenderLives(const int numPlayerLives)
{   
//    if(numPlayerLives < _playerLivesCounter) {
//        _window.clear(sf::Color::Red);
//        _playerLivesCounter = numPlayerLives;
//    }
        
    for (auto i = 0; i < numPlayerLives; i++)
    {
        _window.draw(_livesVector[i]);
    }
    
}

bool Interface::CheckClock()
{
    if(_clock.getElapsedTime().asMilliseconds() >= 1000/75)
    {
        _clock.restart();
        return true;
    }
    
    return false;
}