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
    DisplayWindow();
}


void Interface::GameScreen()
{
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
    DisplayWindow();
}

void Interface::ClearWindow()
{
    _window.clear(sf::Color::White);
}

void Interface::Render(vector<shared_ptr<GameObject>> object_vector, const shared_ptr<int> score , const shared_ptr<int> high_score, shared_ptr<int> numPlayerLives)
{
    for(shared_ptr<GameObject> element: object_vector)
    {
        RenderGameObject(element);
    }
    RenderText(score, high_score);
    RenderLives(numPlayerLives);
    DisplayWindow();
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
    vector<float> properties = object->getShapeProperties();
    float outlineThickness = properties[0];
    sf::Color colour(properties[1], properties[2], properties[3]);
    sf::Color outlineColor = colour;
    sf::Color fillColor = colour;
    
    
    switch (object->getObjectType())
    {
    
    case gameObjectType::Player:
    case gameObjectType::PlayerBullet:
    case gameObjectType::Enemy:
    case gameObjectType::EnemyBullet:
    case gameObjectType::ArcSegment:
    case gameObjectType::LaserGenerator:
    {
        sf::RectangleShape _rect;
        break;
    }  
    case gameObjectType::Asteriod:
    {
        float hexRaduis = height*scale;
        sf::CircleShape _hexagon(hexRaduis, 6);
        _hexagon.setOrigin(sf::Vector2f(hexRaduis,hexRaduis));
        _hexagon.setRotation(angle);
        _hexagon.setPosition(sf::Vector2f(xCoord, yCoord));
        _hexagon.setOutlineThickness(outlineThickness);
        _hexagon.setOutlineColor(outlineColor);
        _hexagon.setFillColor(fillColor);
        _window.draw(_hexagon);
        break;
    }

    case gameObjectType::Satellite:
    {
        float triRaduis = (height + 5)*scale;
        sf::CircleShape _triangle(triRaduis, 3);
        _triangle.setOrigin(sf::Vector2f(triRaduis,triRaduis));
        _triangle.setRotation(angle+90);
        _triangle.setPosition(sf::Vector2f(xCoord, yCoord));
         outlineColor = sf::Color(182,0,255);
         fillColor = sf::Color(182,0,255);    
        _triangle.setOutlineThickness(outlineThickness);
        _triangle.setOutlineColor(fillColor);
        _triangle.setFillColor(outlineColor);
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

void Interface::RenderLives(shared_ptr<int> numPlayerLives)
{   
    if(*numPlayerLives < _playerLivesCounter) {
        _window.clear(sf::Color::Red);
        _playerLivesCounter = *numPlayerLives;
    }
        
    for (auto i = 0; i < *numPlayerLives; i++)
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