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
	CHECK( newGame.getGameObjectsVector()[0]->getObjectType() == gameObjectType::Player);
}

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
// Check bullet move

TEST_CASE("Check enemy can be instantiated"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::Enemy, 1);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 1);
}

TEST_CASE("Check multiple enemies can be instantiated and are all of type 'Enemy'"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::Enemy, 1);
	newGame.AddGameObject(gameObjectType::Enemy, 1);
	newGame.AddGameObject(gameObjectType::Enemy, 1);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 3);
<<<<<<< HEAD
}

TEST_CASE("check stuff") {
    int x = 1;
    CHECK(x == 1);
}
=======
	CHECK(newGame.getGameObjectsVector()[oldSize]->getObjectType() == gameObjectType::Enemy);
	CHECK(newGame.getGameObjectsVector()[oldSize+1]->getObjectType() == gameObjectType::Enemy);
	CHECK(newGame.getGameObjectsVector()[oldSize+2]->getObjectType() == gameObjectType::Enemy);
}

TEST_CASE("Check enemy can move, and moves outward."){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::Enemy, 0);
	shared_ptr<GameObject> testEnemy = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	auto oldX = testEnemy->getXCoord();
	auto oldY = testEnemy->getYCoord();
	
	testEnemy->lineMove();
	
	auto testAngle = testEnemy->getAngle();
	if (testAngle < 0) testAngle += 360;
	if (testAngle == 0)
	{
		CHECK(testEnemy->getXCoord() > oldX);
		CHECK(testEnemy->getYCoord() == oldY);
	}
	else if (testAngle < 90)
	{
		CHECK(testEnemy->getXCoord() < oldX);
		CHECK(testEnemy->getYCoord() > oldY);
	} 
	else if (testAngle == 90)
	{
		CHECK(testEnemy->getXCoord() == oldX);
		CHECK(testEnemy->getYCoord() > oldY);
	}
	else if (testAngle < 180)
	{
		CHECK(testEnemy->getXCoord() < oldX);
		CHECK(testEnemy->getYCoord() > oldY);
	}
	else if (testAngle == 180)
	{
		CHECK(testEnemy->getXCoord() < oldX);
		CHECK(testEnemy->getYCoord() == oldY);
	}
	else if (testAngle < 270)
	{
		CHECK(testEnemy->getXCoord() < oldX);
		CHECK(testEnemy->getYCoord() < oldY);
	}
	else if (testAngle == 270)
	{
		CHECK(testEnemy->getXCoord() == oldX);
		CHECK(testEnemy->getYCoord() < oldY);
	}
	else if (testAngle < 360)
	{
		CHECK(testEnemy->getXCoord() > oldX);
		CHECK(testEnemy->getYCoord() < oldY);
	}
	
	
	
	
	
}

// Test enemy instantiation
// Test enemy movement

//TEST_CASE("Check enemy bullet can be instantiated and is of type 'EnemyBullet'"){
//	Game newGame(5);
//	int oldSize = newGame.getGameObjectsVector().size();
//	newGame.AddGameObject(gameObjectType::EnemyBullet, 2);
//	CHECK(newGame.getGameObjectsVector().size() == oldSize + 1);
//	CHECK( newGame.getGameObjectsVector()[oldSize]->getObjectType() == gameObjectType::EnemyBullet);
//}

//TEST_CASE("Check enemy bullet can move, and moves outward."){
//	
//}

//LaserGenerator
// Check other laser generator Created
// Check arc Created
// Check all same ID

// Enemy bullet cooldown only exists in enemy 
>>>>>>> 1c57928277cb91985df77e9c5181de6870019ff4
