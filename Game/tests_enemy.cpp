#include "Player.h"
#include "Game.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Enemy tests

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
	CHECK(newGame.getGameObjectsVector()[oldSize]->getObjectType() == gameObjectType::Enemy);
	CHECK(newGame.getGameObjectsVector()[oldSize+1]->getObjectType() == gameObjectType::Enemy);
	CHECK(newGame.getGameObjectsVector()[oldSize+2]->getObjectType() == gameObjectType::Enemy);
}

TEST_CASE("Check enemy can move, and moves outward."){
	Game newGame(5);
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
		CHECK(testEnemy->getXCoord() > oldX);
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

TEST_CASE("Check enemy gets deleted when off screen"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::Enemy, 0);
	shared_ptr<GameObject> testEnemy = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	
	while(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::Enemy){
	testEnemy->lineMove();
	newGame.ObjectCleanup();
	}
	
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::Enemy);
}

// Enemy bullet tests

TEST_CASE("Check enemy bullet can be instantiated and is of type 'EnemyBullet'"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::EnemyBullet, 1);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 1);
	CHECK( newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::EnemyBullet);
}

TEST_CASE("Check enemy bullet can move, and moves outward."){
	
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::Enemy,0);
	newGame.AddGameObject(gameObjectType::EnemyBullet, 1);
	shared_ptr<GameObject> testEnemyBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	auto oldX = testEnemyBullet->getXCoord();
	auto oldY = testEnemyBullet->getYCoord();
	
	testEnemyBullet->lineMove();
	
	auto testAngle = testEnemyBullet->getAngle();
	if (testAngle < 0) testAngle += 360;
	if (testAngle == 0)
	{
		CHECK(testEnemyBullet->getXCoord() > oldX);
		CHECK(testEnemyBullet->getYCoord() == oldY);
	}
	else if (testAngle < 90)
	{
		CHECK(testEnemyBullet->getXCoord() > oldX);
		CHECK(testEnemyBullet->getYCoord() > oldY);
	} 
	else if (testAngle == 90)
	{
		CHECK(testEnemyBullet->getXCoord() == oldX);
		CHECK(testEnemyBullet->getYCoord() > oldY);
	}
	else if (testAngle < 180)
	{
		CHECK(testEnemyBullet->getXCoord() < oldX);
		CHECK(testEnemyBullet->getYCoord() > oldY);
	}
	else if (testAngle == 180)
	{
		CHECK(testEnemyBullet->getXCoord() < oldX);
		CHECK(testEnemyBullet->getYCoord() == oldY);
	}
	else if (testAngle < 270)
	{
		CHECK(testEnemyBullet->getXCoord() < oldX);
		CHECK(testEnemyBullet->getYCoord() < oldY);
	}
	else if (testAngle == 270)
	{
		CHECK(testEnemyBullet->getXCoord() == oldX);
		CHECK(testEnemyBullet->getYCoord() < oldY);
	}
	else if (testAngle < 360)
	{
		CHECK(testEnemyBullet->getXCoord() > oldX);
		CHECK(testEnemyBullet->getYCoord() < oldY);
	}
}

TEST_CASE("Check enemy bullet gets deleted when off screen"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::Enemy,1);
	newGame.AddGameObject(gameObjectType::EnemyBullet, 1);
	shared_ptr<GameObject> testEnemyBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	
	while(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::EnemyBullet){
	testEnemyBullet->lineMove();
	newGame.ObjectCleanup();
	}
	
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::EnemyBullet);
}

