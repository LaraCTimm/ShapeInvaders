#include "Game.h"


// Pass in the previous high score from a text file
Game::Game(int highScore)
//: _enemyCooldown(10)
//, _asteriodCooldown(400)
//, _laserGeneratorCooldown(800)
//, _shotFired(false)
//, _score(new int(0))
//, _player_ptr(new Player())
//, _gameState(1)
//, _inGame(false)
{
    InitialiseGame();
//    _GameObjectsVector.clear();
//    _GameObjectsVector.push_back(_player_ptr);
//
//    srand (time(0));
//    
//    FileReader file("scores.txt");
//    _highScore = make_shared<int>(file.getHighScore());
//    
//    _interface.CreateLivesVector(_player_ptr->getHealth(), LIFE_RECT_SIZE);
    
    GameLoop();
}

void Game::InitialiseGame()
{
    _enemyCooldown = 10;
    _asteriodCooldown = 400;
    _laserGeneratorCooldown = 800;
    _shotFired = false;
    _score = make_shared<int>(0);
    shared_ptr<GameObject> ptr(new Player());
    _player_ptr = ptr;
    _gameState = 1;
    _inGame = false;
    
    _GameObjectsVector.clear();
    _GameObjectsVector.push_back(_player_ptr);

    srand (time(0));
    
    FileReader file("scores.txt");
    _highScore = make_shared<int>(file.getHighScore());
    
    _interface.CreateLivesVector(_player_ptr->getHealth(), LIFE_RECT_SIZE);
}

void Game::GameLoop()
{
    while(_interface.WindowOpen())
    {
        while(_gameState == 1)
        {
            _interface.SplashScreen();
            _interface.ProcessGameEvents();

            vector<keyboardInput> keysPressed = _interface.GetGameEvents();
            
            if (!keysPressed.empty())
            {
                CheckGameState(keysPressed);
            }
        }
                
        while(_gameState == 2)
        {
            _interface.GameScreen();
            _interface.ProcessGameEvents();
            vector<keyboardInput> keysPressed = _interface.GetGameEvents();

            if(_interface.CheckClock())
            {
                Update(keysPressed);
                Render();
                _interface.DisplayWindow();
                _inGame = true;
            }
        }
        
        while (_gameState == 3)
        {
            _interface.EndScreen();
            _interface.ProcessGameEvents();
            vector<keyboardInput> keysPressed = _interface.GetGameEvents();
            CheckGameState(keysPressed);
        }
    }
}

void Game::CheckGameState(vector<keyboardInput> keysPressed)
{
    //cout<< "HELLOOOO" << endl;
    for (auto element: keysPressed)
    {
        if (element == keyboardInput::press_enter) 
        {
            if (_inGame)
            {
                InitialiseGame();
            }
            
            _gameState = 2;
        }
        else if (element == keyboardInput::press_esc || element == keyboardInput::close_window)
        {
            _interface.CloseWindow();
            _gameState = 4;
        }
        
        if(_gameState == 4)
        {
            break;
        }
    }
}

void Game::Update(vector<keyboardInput> keysPressed)
{
    for (auto element: keysPressed)
    {
        switch(element)
        {
            case keyboardInput::press_up:
                MovePlayerObject(-1);
                break;
            case keyboardInput::press_down:
                MovePlayerObject(1);
                break;
            case keyboardInput::press_space:
                if (!_shotFired) 
                {
                    AddGameObject(gameObjectType::PlayerBullet, 0);
                    _shotFired = true;
                }
                break;
            case keyboardInput::release_space:
                _shotFired = false;
                break;
            case keyboardInput::close_window:
                _interface.CloseWindow();
                break;
            default:
                break;  
        }
    }
    
    DecrementCooldowns();
    CreateGameObjects();
    CheckCollisions();
    CheckScoreStatus();
    ObjectCleanup();
    CheckGameOver();
    
    for (auto i = 0; i < _GameObjectsVector.size(); i++)
    {
        if (_GameObjectsVector[i]->getObjectType() != gameObjectType::Player)
        {
            MoveLineObject(i);
        }
    }
}

void Game::Render()
{
    for (shared_ptr<GameObject> element: _GameObjectsVector)
    {
        //cout << "RENDERING..." << int(element->getObjectType()) << endl;
        _interface.RenderGameObject(element);
    }
    
    //cout << "RENDERING DONE" << endl;
    _interface.RenderText(_score, _highScore);
    _interface.RenderLives(_player_ptr->getHealth());
    
    //_interface.DisplayWindow();
}

shared_ptr<GameObject> Game::SpawnGameObject(gameObjectType type, int index) 
{
    switch (type) 
    {
//        case gameObjectType::Player:
//            return shared_ptr<GameObject>(new Player());
            
        case gameObjectType::Enemy:
        // enemies may spawn from a position other than the origin if further movement patterns are developed
            return shared_ptr<GameObject>(new Enemy(ORIGIN_X, ORIGIN_Y, GenerateRandomNumber(0, 360)));
            
        case gameObjectType::PlayerBullet:
            return shared_ptr<GameObject>(new PlayerBullet(_GameObjectsVector[0]->getXCoord(), _GameObjectsVector[0]->getYCoord(), _GameObjectsVector[0]->getPathVector(), _GameObjectsVector[0]->getAngle()));
            
        case gameObjectType::EnemyBullet:
            return shared_ptr<GameObject>(new EnemyBullet(_GameObjectsVector[index]->getXCoord(), _GameObjectsVector[index]->getYCoord(), _GameObjectsVector[index]->getPathVector(), _GameObjectsVector[index]->getAngle(), _GameObjectsVector[index]->getScaleCount()));
            
        case gameObjectType::Asteriod:
        // tracks the position of the player
            return shared_ptr<GameObject>(new Asteriod(_GameObjectsVector[0]->getAngle()));
            
        case gameObjectType::Satellite:
            break;
        case gameObjectType::LaserGenerator:
        {
            int ID = 0;
            int separationAngle = 0;
            
            // give new LaserGenerator/ArcSegment objects a unique ID
            for(auto element : _GameObjectsVector)
            {
                if(element->getObjectType() == gameObjectType::LaserGenerator)
                {
                    shared_ptr<LaserGenerator> laserGen_ptr = std::static_pointer_cast<LaserGenerator>((*element).getptr());
                    
                    if(laserGen_ptr->getID() > ID) {
                        ID = laserGen_ptr->getID();
                    }
                }
            }
            ID++;
            
            float angle = GenerateRandomNumber(0, 360);
            
             // create first LaserGenerator
            shared_ptr<GameObject> laserGen1_ptr(new LaserGenerator(angle + 2, ID));
            
            shared_ptr<LaserGenerator> temp_ptr = std::static_pointer_cast<LaserGenerator>((*laserGen1_ptr).getptr());
            separationAngle = temp_ptr->getSeparationAngle();
            
            // create ArcSegments
            for(int i = 0; i < temp_ptr->getNumArcSegs(); i++)
            {
                angle += separationAngle;
                shared_ptr<GameObject> arcSeg_ptr(new ArcSegment(angle, ID));
                _GameObjectsVector.push_back(arcSeg_ptr);
            }

            _GameObjectsVector.push_back(laserGen1_ptr);
            
            angle += separationAngle;
            
            // create second LaserGenerator
            shared_ptr<GameObject> laserGen2_ptr(new LaserGenerator(angle - 2, ID));

            return laserGen2_ptr;
        }
        
        default:
            break;
    }
    return shared_ptr<GameObject>();
} 



void Game::MovePlayerObject(int direction)
{
	_GameObjectsVector[0]->circularMove(direction);
}

void Game::MoveLineObject(int objectIndex) 
{
    _GameObjectsVector[objectIndex]->lineMove();
}

void Game::AddGameObject(gameObjectType type, int index)
{
    shared_ptr<GameObject> object_ptr = Game::SpawnGameObject(type, index);
    _GameObjectsVector.push_back(object_ptr);
}

void Game::ObjectCleanup() 
{
    for (int i = 0; i < _GameObjectsVector.size(); i++)
    {
        // all game objects use health as a cleanup flag
        if (_GameObjectsVector[i]->getHealth() <= 0)
        {
            _GameObjectsVector.erase(_GameObjectsVector.begin() + i);
            i--;
        }
    }
}

void Game::CheckGameOver()
{
    if (_GameObjectsVector.size() > 0 && _GameObjectsVector[0]->getObjectType() != gameObjectType::Player)
    {
        SetNewHighScore();
        _gameState = 3;
    }
}


// ??????

void Game::DecrementCooldowns()
{
    for (int i = 0; i < _GameObjectsVector.size(); i++)
    {
        if (_GameObjectsVector[i]->getObjectType() == gameObjectType::Enemy)
        {
            shared_ptr<Enemy> enemy_ptr = std::static_pointer_cast<Enemy>((*_GameObjectsVector[i]).getptr());
            enemy_ptr->decrementEnemyBulletCooldown(); 
          
            if (enemy_ptr->getBulletCooldown() <= 0)
            {
                AddGameObject(gameObjectType::EnemyBullet, i);
                enemy_ptr->setBulletCooldown(GenerateRandomNumber(100,200));
            }
        }
    }
    
    if (_enemyCooldown > 0) {
        _enemyCooldown--;
    }
    
    if (_asteriodCooldown > 0) {
        _asteriodCooldown--;
    }
    
     if (_laserGeneratorCooldown > 0) {
        _laserGeneratorCooldown--;
    }
}


void Game::CreateGameObjects()
{
    if (_enemyCooldown <= 0)
    {
        AddGameObject(gameObjectType::Enemy, 0);
        _enemyCooldown = GenerateRandomNumber(75.0f, 150.0f);
    }
            
    if (_asteriodCooldown <= 0)
    {
        AddGameObject(gameObjectType::Asteriod, 0);
        _asteriodCooldown = GenerateRandomNumber(100.0f, 150.0f);
    }
    
    if (_laserGeneratorCooldown <= 0)
    {
        AddGameObject(gameObjectType::LaserGenerator, 0);
        _laserGeneratorCooldown = GenerateRandomNumber(350.0f, 400.0f);
    }
}

void Game::CheckCollisions() 
{
    for (int i = 0; i < _GameObjectsVector.size(); i++)
    {
        *_score += _GameObjectsVector[i]->checkCollisions(_GameObjectsVector);
    }
}

float Game::GenerateRandomNumber(float min, float max)
{
    float randomNumber = min + float(rand())/float(RAND_MAX/(max-min));
    //cout << randomNumber << endl;
    return randomNumber;
}

void Game::CheckScoreStatus()
{
    if (*_score >= *_highScore)
    {
        *_highScore = *_score;
    }
    
    SetNewHighScore(); // only necessary if you don't play till the game/over screen appears
}

void Game::SetNewHighScore()
{
    FileReader file("scores.txt");
    file.setHighScore(*_highScore);
}