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

/*~~~~~~~~~~~~~~~~ TESTS TO ADD ~~~~~~~~~~~~~~~~
player:
can move with user input
player bullet spawns at player position
player initialised with five lives
player looses a life when colliding with enemy
player gets destroyed after loosing all lives
player points increase when bullets kill stuff
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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

/*~~~~~~~~~~~~~~~~ TESTS TO ADD ~~~~~~~~~~~~~~~~
 * player bullet tests:
bullet destroyed when collliding with all other objects
	enemy
	enemy bullets
	asteriods
	arc segments
	laser gen
	satellite
bullet destroyed when out of bounds

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/