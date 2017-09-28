#include "Player.h"
#include "Game.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("Check asteroid can be instantiated and is of type 'Asteriod'"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::Asteriod, 0);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 1);
	CHECK(newGame.getGameObjectsVector()[oldSize]->getObjectType() == gameObjectType::Asteriod);
}

TEST_CASE("Check asteroid can move, and moves outward."){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::Asteriod, 1);
	shared_ptr<GameObject> testAsteroid = newGame.getGameObjectsVector()[oldSize];
	auto oldX = testAsteroid->getXCoord();
	auto oldY = testAsteroid->getYCoord();
	
	testAsteroid->lineMove();
	
	auto testAngle = testAsteroid->getAngle();
	if (testAngle < 0) testAngle += 360;
	if (testAngle == 0)
	{
		CHECK(testAsteroid->getXCoord() > oldX);
		CHECK(testAsteroid->getYCoord() == oldY);
	}
	else if (testAngle < 90)
	{
		CHECK(testAsteroid->getXCoord() > oldX);
		CHECK(testAsteroid->getYCoord() > oldY);
	} 
	else if (testAngle == 90)
	{
		CHECK(testAsteroid->getXCoord() == oldX);
		CHECK(testAsteroid->getYCoord() > oldY);
	}
	else if (testAngle < 180)
	{
		CHECK(testAsteroid->getXCoord() < oldX);
		CHECK(testAsteroid->getYCoord() > oldY);
	}
	else if (testAngle == 180)
	{
		CHECK(testAsteroid->getXCoord() < oldX);
		CHECK(testAsteroid->getYCoord() == oldY);
	}
	else if (testAngle < 270)
	{
		CHECK(testAsteroid->getXCoord() < oldX);
		CHECK(testAsteroid->getYCoord() < oldY);
	}
	else if (testAngle == 270)
	{
		CHECK(testAsteroid->getXCoord() == oldX);
		CHECK(testAsteroid->getYCoord() < oldY);
	}
	else if (testAngle < 360)
	{
		CHECK(testAsteroid->getXCoord() > oldX);
		CHECK(testAsteroid->getYCoord() < oldY);
	}
}

TEST_CASE("Check laser generator can be instantiated, along with its pair and arc between the two."){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::LaserGenerator, 1);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 9);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::LaserGenerator);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-2]->getObjectType() == gameObjectType::LaserGenerator);
	for(int a = oldSize; a < newGame.getGameObjectsVector().size()-2; a++){
		CHECK(newGame.getGameObjectsVector()[a]->getObjectType() == gameObjectType::ArcSegment);
	}
	}

// Check all same ID
TEST_CASE("Check laser generator can be instantiated, along with its pair and arc between the two and all have the same ID."){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::LaserGenerator, 1);
	//shared_ptr<LaserGenerator> laserGen_ptr = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-2];
	//int laserID = laserGen_ptr->getID();
	//CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-2]->LaserGenerator::getID() == laserID);
	//for(int a = oldSize; a < newGame.getGameObjectsVector().size()-2; a++){
	//	CHECK(newGame.getGameObjectsVector()[a]->getID() == laserID);
	//}
	}