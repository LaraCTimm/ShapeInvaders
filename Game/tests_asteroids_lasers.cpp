#include "Player.h"
#include "Game.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITHOUT_MAIN
#include "doctest.h"

// Asteroid tests

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

TEST_CASE("Check asteroid gets deleted when off screen"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::Asteriod, 0);
	shared_ptr<GameObject> testAsteroid = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	
	while(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::Asteriod){
	testAsteroid->lineMove();
	newGame.ObjectCleanup();
	}
	
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::Asteriod);
}

TEST_CASE("Check asteroid is instantiated at same angle as player, ie chases player"){
	Game newGame(5);
	newGame.MovePlayerObject(1);
	newGame.MovePlayerObject(1);
	float playerAngle = newGame.getGameObjectsVector()[0]->getAngle();
	
	newGame.AddGameObject(gameObjectType::Asteriod, 0);
	float astAngle = newGame.getGameObjectsVector()[1]->getAngle();
	
	CHECK(playerAngle == astAngle);
}

// Laser generator tests

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

TEST_CASE("Check laser generator can be instantiated, along with its pair and arc between the two and all have the same ID."){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::LaserGenerator, 1);
	
	shared_ptr<GameObject> laserGen1_GO = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	shared_ptr<LaserGenerator> laserGen1_ptr = std::static_pointer_cast<LaserGenerator>((*laserGen1_GO).getptr());
	int laserID1 = laserGen1_ptr->getID();
	
	shared_ptr<GameObject> laserGen2_GO = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-2];
	shared_ptr<LaserGenerator> laserGen2_ptr = std::static_pointer_cast<LaserGenerator>((*laserGen2_GO).getptr());
	int laserID2 = laserGen2_ptr->getID();
	
	CHECK(laserID1 == laserID2);
	
	for(int a = oldSize; a < newGame.getGameObjectsVector().size()-2; a++){
		shared_ptr<GameObject> arcSeg_GO = newGame.getGameObjectsVector()[a];
		shared_ptr<LaserGenerator> arcSeg_ptr = std::static_pointer_cast<LaserGenerator>((*arcSeg_GO).getptr());
		int arcSegID = arcSeg_ptr->getID();
		CHECK(arcSegID == laserID1);
	}
}

TEST_CASE("Check two separate laser generators have different IDs"){
	
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::LaserGenerator, 1);
	newGame.AddGameObject(gameObjectType::LaserGenerator, 1);
	
	shared_ptr<GameObject> laserGen1_GO = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	shared_ptr<LaserGenerator> laserGen1_ptr = std::static_pointer_cast<LaserGenerator>((*laserGen1_GO).getptr());
	int laserID1 = laserGen1_ptr->getID();
	
	shared_ptr<GameObject> laserGen2_GO = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1-(2+7)];
	shared_ptr<LaserGenerator> laserGen2_ptr = std::static_pointer_cast<LaserGenerator>((*laserGen2_GO).getptr());
	int laserID2 = laserGen2_ptr->getID();
	
	CHECK(laserID1 != laserID2);
}

TEST_CASE("Check laser generator gets deleted when off screen"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::LaserGenerator, 0);
	
	while(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::Player){
		for (auto element :newGame.getGameObjectsVector()){
			if (element->getObjectType() == gameObjectType::ArcSegment || element->getObjectType() == gameObjectType::LaserGenerator){
				element->lineMove();
			}
		}
		newGame.ObjectCleanup();
	}
	
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::LaserGenerator);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::ArcSegment);
}
