#include "Player.h"
#include "Game.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("Check GameObject vector size = 1 at start") {
	Game newGame(1);
	CHECK(newGame.getGameObjectsVector().size() == 1);
}

TEST_CASE("Check Game starts with a player object") {
	Game newGame(1);
	CHECK( newGame.getGameObjectsVector()[0].getObjectType() == gameObjectType::Player);
}

TEST_CASE("Check Player is instantiated at (700,400)"){
	Game newGame(1);
	CHECK(newGame.getGameObjectsVector()[0].getXCoord() == 700);
	CHECK(newGame.getGameObjectsVector()[0].getYCoord() == 400);
}


TEST_CASE("Check player can move in anti-clockwise direction"){
	Game newGame(5);
	int oldx = newGame.getGameObjectsVector()[0].getXCoord(), oldy = newGame.getGameObjectsVector()[0].getYCoord();
	newGame.movePlayerObject(1);
	int newx = newGame.getGameObjectsVector()[0].getXCoord(), newy = newGame.getGameObjectsVector()[0].getYCoord();
	CHECK(oldx > newx);
	CHECK(oldy < newy);
}

TEST_CASE("Check player can move in clockwise direction"){
	Game newGame(5);
	int oldx = newGame.getGameObjectsVector()[0].getXCoord(), oldy = newGame.getGameObjectsVector()[0].getYCoord();
	newGame.movePlayerObject(-1);
	int newx = newGame.getGameObjectsVector()[0].getXCoord(), newy = newGame.getGameObjectsVector()[0].getYCoord();
	CHECK(oldx > newx);
	CHECK(oldy > newy);
}

TEST_CASE("Check bullet can be instantiated"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::PlayerBullet);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 1);
}

TEST_CASE("Check bullet is of type 'PlayerBullet'"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::PlayerBullet);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1].getObjectType() == gameObjectType::PlayerBullet);
}

TEST_CASE("Check instantiated bullet can be moved"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::PlayerBullet);
    float startXCoord = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1].getXCoord();
    newGame.moveLineObject(newGame.getGameObjectsVector().size()-1);
    float endXCoord = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1].getXCoord();
	CHECK(endXCoord < startXCoord);
}

TEST_CASE("Check bullet is destroyed after it reaches screen centre"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::PlayerBullet);
    while (newGame.getGameObjectsVector().size() > 1) 
    {
        newGame.moveLineObject(newGame.getGameObjectsVector().size()-1);
        newGame.ObjectCleanup();
    }
	CHECK(newGame.getGameObjectsVector().size() == 1);
}

TEST_CASE("Check enemy can be instantiated"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::Enemy);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 1);
}

TEST_CASE("Check enemy object is of type 'Enemy'){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::Enemy);
	CHECK(newGame.getGameObjectsVector()[1].getObjectType() == gameObjectType::Enemy);
}

TEST_CASE("Check multiple enemies can be instantiated"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::Enemy);
	newGame.AddGameObject(gameObjectType::Enemy);
	newGame.AddGameObject(gameObjectType::Enemy);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 3);
}