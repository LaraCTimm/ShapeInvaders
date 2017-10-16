#include "Player.h"
#include "Game.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITHOUT_MAIN
#include "doctest.h"


TEST_CASE("Check GameObject vector size = 1 at start") {
	Game newGame(1);
	CHECK(newGame.getGameObjectsVector().size() == 1);
}

TEST_CASE("Check Game starts with a player object") {
	Game newGame(1);
	CHECK( newGame.getGameObjectsVector()[0]->getObjectType() == gameObjectType::Player);
}

// Player tests

TEST_CASE("Check Player is instantiated at (700,400)"){
	Game newGame(1);
	CHECK(newGame.getGameObjectsVector()[0]->getXCoord() == 700);
	CHECK(newGame.getGameObjectsVector()[0]->getYCoord() == 400);
}

TEST_CASE("Check player can move in anti-clockwise direction"){
	Game newGame(5);
	int oldx = newGame.getGameObjectsVector()[0]->getXCoord(), oldy = newGame.getGameObjectsVector()[0]->getYCoord();
	newGame.MovePlayerObject(1);
	int newx = newGame.getGameObjectsVector()[0]->getXCoord(), newy = newGame.getGameObjectsVector()[0]->getYCoord();
	CHECK(oldx > newx);
	CHECK(oldy < newy);
}

TEST_CASE("Check player can move in clockwise direction"){
	Game newGame(5);
	int oldx = newGame.getGameObjectsVector()[0]->getXCoord(), oldy = newGame.getGameObjectsVector()[0]->getYCoord();
	newGame.MovePlayerObject(-1);
	int newx = newGame.getGameObjectsVector()[0]->getXCoord(), newy = newGame.getGameObjectsVector()[0]->getYCoord();
	CHECK(oldx > newx);
	CHECK(oldy > newy);
}

TEST_CASE("Check player is instantiated at start with 5 lives"){
	Game newGame(5);
	int lives = newGame.getGameObjectsVector()[0]->getHealth();
	CHECK(lives==5);
}

// Player bullet tests

TEST_CASE("Check bullet can be instantiated"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::PlayerBullet, 1);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 1);
}

TEST_CASE("Check bullet is of type 'PlayerBullet'"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::PlayerBullet, 1);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::PlayerBullet);
}

TEST_CASE("Check bullet is instantiated at player's position"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::PlayerBullet, 1);
	float playX = newGame.getGameObjectsVector()[0]->getXCoord(), playY = newGame.getGameObjectsVector()[0]->getYCoord();
	float bulX = newGame.getGameObjectsVector()[1]->getXCoord(), bulY = newGame.getGameObjectsVector()[1]->getYCoord();
	
	CHECK(bulX == playX - 15);
	CHECK(bulY == playY);
}

TEST_CASE("Check bullet movement: negative x direction"){
	Game newGame(5);
	newGame.getGameObjectsVector()[0]->circularMove(0);
	newGame.AddGameObject(gameObjectType::PlayerBullet, 2);
	shared_ptr<GameObject> testPlayerBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	auto oldX = testPlayerBullet->getXCoord();
	auto oldY = testPlayerBullet->getYCoord();
	
	testPlayerBullet->lineMove();
	CHECK(testPlayerBullet->getXCoord() < oldX);
	CHECK(testPlayerBullet->getYCoord() == oldY);
}

TEST_CASE("Check bullet movement: first quadrant"){
	Game newGame(5);
	newGame.getGameObjectsVector()[0]->circularMove(315/2);
	newGame.AddGameObject(gameObjectType::PlayerBullet, 2);
	shared_ptr<GameObject> testPlayerBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	auto oldX = testPlayerBullet->getXCoord();
	auto oldY = testPlayerBullet->getYCoord();
	
	testPlayerBullet->lineMove();
	CHECK(testPlayerBullet->getXCoord() < oldX);
	CHECK(testPlayerBullet->getYCoord() > oldY);
}

TEST_CASE("Check bullet movement: negative y direction"){
	Game newGame(5);
	newGame.getGameObjectsVector()[0]->circularMove(270/2);
	newGame.AddGameObject(gameObjectType::PlayerBullet, 2);
	shared_ptr<GameObject> testPlayerBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	auto oldX = testPlayerBullet->getXCoord();
	auto oldY = testPlayerBullet->getYCoord();
	
	testPlayerBullet->lineMove();
	CHECK(testPlayerBullet->getXCoord() == oldX);
	CHECK(testPlayerBullet->getYCoord() > oldY);
}

TEST_CASE("Check bullet movement: second quadrant"){
	Game newGame(5);
	newGame.getGameObjectsVector()[0]->circularMove(225/2);
	newGame.AddGameObject(gameObjectType::PlayerBullet, 2);
	shared_ptr<GameObject> testPlayerBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	auto oldX = testPlayerBullet->getXCoord();
	auto oldY = testPlayerBullet->getYCoord();
	
	testPlayerBullet->lineMove();
	CHECK(testPlayerBullet->getXCoord() > oldX);
	CHECK(testPlayerBullet->getYCoord() > oldY);
}

TEST_CASE("Check bullet movement: positive x direction"){
	Game newGame(5);
	newGame.getGameObjectsVector()[0]->circularMove(180/2);
	newGame.AddGameObject(gameObjectType::PlayerBullet, 2);
	shared_ptr<GameObject> testPlayerBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	auto oldX = testPlayerBullet->getXCoord();
	auto oldY = testPlayerBullet->getYCoord();
	
	testPlayerBullet->lineMove();
	CHECK(testPlayerBullet->getXCoord() > oldX);
	CHECK(testPlayerBullet->getYCoord() == oldY);
}

TEST_CASE("Check bullet movement: third quadrant"){
	Game newGame(5);
	newGame.getGameObjectsVector()[0]->circularMove(135/2);
	newGame.AddGameObject(gameObjectType::PlayerBullet, 2);
	shared_ptr<GameObject> testPlayerBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	auto oldX = testPlayerBullet->getXCoord();
	auto oldY = testPlayerBullet->getYCoord();
	
	testPlayerBullet->lineMove();
	CHECK(testPlayerBullet->getXCoord() > oldX);
	CHECK(testPlayerBullet->getYCoord() < oldY);
}

TEST_CASE("Check bullet movement: positive y direction"){
	Game newGame(5);
	newGame.getGameObjectsVector()[0]->circularMove(90/2);
	newGame.AddGameObject(gameObjectType::PlayerBullet, 2);
	shared_ptr<GameObject> testPlayerBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	auto oldX = testPlayerBullet->getXCoord();
	auto oldY = testPlayerBullet->getYCoord();
	
	testPlayerBullet->lineMove();
	CHECK(testPlayerBullet->getXCoord() == oldX);
	CHECK(testPlayerBullet->getYCoord() < oldY);
}

TEST_CASE("Check bullet movement: fourth quadrant"){
	Game newGame(5);
	newGame.getGameObjectsVector()[0]->circularMove(45/2);
	newGame.AddGameObject(gameObjectType::PlayerBullet, 2);
	shared_ptr<GameObject> testPlayerBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	auto oldX = testPlayerBullet->getXCoord();
	auto oldY = testPlayerBullet->getYCoord();
	
	testPlayerBullet->lineMove();
	CHECK(testPlayerBullet->getXCoord() < oldX);
	CHECK(testPlayerBullet->getYCoord() < oldY);
}

TEST_CASE("Check player bullet gets deleted once it reaches middle of screen"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::PlayerBullet, 0);
	shared_ptr<GameObject> testBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	
	while(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::PlayerBullet){
	testBullet->lineMove();
	newGame.ObjectCleanup();
	}
	
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::PlayerBullet);
}

