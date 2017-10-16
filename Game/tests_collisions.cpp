#include "Game.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITHOUT_MAIN
#include "doctest.h"

// Asteroid collisions 
TEST_CASE("Asteroid-player collision - check damage dealt"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	int oldHealth = newGame.getGameObjectsVector()[0]->getHealth();
	newGame.AddGameObject(gameObjectType::Asteriod, 1);
	shared_ptr<GameObject> testAsteroid = newGame.getGameObjectsVector()[oldSize];
	
	while(newGame.getGameObjectsVector().size()==oldSize+1){
		testAsteroid->lineMove();
		newGame.CheckCollisions();
		newGame.ObjectCleanup();
		}
	
	CHECK(newGame.getGameObjectsVector()[0]->getHealth()==oldHealth-1);
}

TEST_CASE("Asteroid-playerBullet collision - check damage dealt and object deletions"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::Asteriod, 1);
	shared_ptr<GameObject> testAsteroid = newGame.getGameObjectsVector()[oldSize];
	newGame.AddGameObject(gameObjectType::PlayerBullet,1);
	shared_ptr<GameObject> testBullet = newGame.getGameObjectsVector()[oldSize+1];
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::PlayerBullet);
	
	while(newGame.getGameObjectsVector().size()==oldSize+2){
		testBullet->lineMove();
		newGame.CheckCollisions();
		newGame.ObjectCleanup();
		}
	
	CHECK(testAsteroid->getHealth()!=0);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::PlayerBullet);
	
}

// Enemy collisions
TEST_CASE("Enemy-player collisions - check damage dealt"){
	Game newGame(5);
	int oldHealth = newGame.getGameObjectsVector()[0]->getHealth();
	
	newGame.AddGameObject(gameObjectType::Enemy, 1);
	shared_ptr<GameObject> testEn = newGame.getGameObjectsVector()[1];
	float enAngle = testEn->getAngle();
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::Enemy);
	
	
	shared_ptr<GameObject> play_GO = newGame.getGameObjectsVector()[0];
	shared_ptr<Player> play_ptr = std::static_pointer_cast<Player>((*play_GO).getptr());
	play_ptr->circularMove(enAngle/2);
	
	while(newGame.getGameObjectsVector().size()==2){
		testEn->lineMove();
		newGame.CheckCollisions();
		newGame.ObjectCleanup();
		}
	
	CHECK(newGame.getGameObjectsVector()[0]->getHealth()==oldHealth-1);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::Enemy);
	
}

TEST_CASE("EnemyBullet-player collisions - check damage dealt, bullet deletion"){
	Game newGame(5);
	int oldHealth = newGame.getGameObjectsVector()[0]->getHealth();
	
	newGame.AddGameObject(gameObjectType::Enemy, 1);
	shared_ptr<GameObject> testEn = newGame.getGameObjectsVector()[1];
	float enAngle = testEn->getAngle();
	
	newGame.AddGameObject(gameObjectType::EnemyBullet, 1);
	shared_ptr<GameObject> testEnBullet = newGame.getGameObjectsVector()[2];
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::EnemyBullet);
	
	shared_ptr<GameObject> play_GO = newGame.getGameObjectsVector()[0];
	shared_ptr<Player> play_ptr = std::static_pointer_cast<Player>((*play_GO).getptr());
	play_ptr->circularMove(enAngle/2);
	
	while(newGame.getGameObjectsVector().size()==3){
		testEnBullet->lineMove();
		newGame.CheckCollisions();
		newGame.ObjectCleanup();
		}
	
	CHECK(newGame.getGameObjectsVector()[0]->getHealth()==oldHealth-1);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::EnemyBullet);	
}

TEST_CASE("Enemy-playerBullet collisions - check deletions and score update"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::Enemy, 1);
	int oldHealth = newGame.getGameObjectsVector()[0]->getHealth();
	shared_ptr<GameObject> testEn = newGame.getGameObjectsVector()[1];
	float enAngle = testEn->getAngle();
	int enPoints = testEn->getPoints();
	
	shared_ptr<GameObject> play_GO = newGame.getGameObjectsVector()[0];
	shared_ptr<Player> play_ptr = std::static_pointer_cast<Player>((*play_GO).getptr());
	play_ptr->circularMove(enAngle/2);
	
	newGame.AddGameObject(gameObjectType::PlayerBullet,1);
	shared_ptr<GameObject> testBullet = newGame.getGameObjectsVector()[2];
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::PlayerBullet);
	
	while(newGame.getGameObjectsVector().size()==3){
		testBullet->lineMove();
		newGame.CheckCollisions();
		newGame.ObjectCleanup();
		}
	
	CHECK(newGame.getGameObjectsVector().size()==1);
	newGame.CheckScoreStatus();
	CHECK(*newGame.getScore() == enPoints);
}

// Laser generator collisions
TEST_CASE("LaserGenerator-player collision - check deletions, damage dealt"){
	Game newGame(5);
	int oldHealth = newGame.getGameObjectsVector()[0]->getHealth();
	
	newGame.AddGameObject(gameObjectType::LaserGenerator, 1);
	shared_ptr<GameObject> testLaser = newGame.getGameObjectsVector()[1];
	float laserAngle = testLaser->getAngle();
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::LaserGenerator);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-2]->getObjectType() == gameObjectType::LaserGenerator);
	
	shared_ptr<GameObject> play_GO = newGame.getGameObjectsVector()[0];
	shared_ptr<Player> play_ptr = std::static_pointer_cast<Player>((*play_GO).getptr());
	play_ptr->circularMove(laserAngle/2);
	
	int oldSize = newGame.getGameObjectsVector().size();
	while(newGame.getGameObjectsVector().size()== oldSize){
		testLaser->lineMove();
		newGame.CheckCollisions();
		newGame.ObjectCleanup();
		}
	
	CHECK(newGame.getGameObjectsVector()[0]->getHealth()==oldHealth-1);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::LaserGenerator);
}

TEST_CASE("LaserGenerator-playerBullet collision - check deletions and score update"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::LaserGenerator, 1);
	int oldHealth = newGame.getGameObjectsVector()[0]->getHealth();
	shared_ptr<GameObject> testLaser = newGame.getGameObjectsVector()[8];
	float laserAngle = testLaser->getAngle();
	int laserPoints = testLaser->getPoints();
	CHECK(testLaser->getObjectType() == gameObjectType::LaserGenerator);
	
	shared_ptr<GameObject> play_GO = newGame.getGameObjectsVector()[0];
	shared_ptr<Player> play_ptr = std::static_pointer_cast<Player>((*play_GO).getptr());
	play_ptr->circularMove(laserAngle/2);
	
	newGame.AddGameObject(gameObjectType::PlayerBullet,1);
	shared_ptr<GameObject> testBullet = newGame.getGameObjectsVector()[2];
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::PlayerBullet);
	
	int oldSize = newGame.getGameObjectsVector().size();
	while(newGame.getGameObjectsVector().size()==oldSize){
		testLaser->lineMove();
		testBullet->lineMove();
		newGame.CheckCollisions();
		newGame.ObjectCleanup();
		}
	
	CHECK(newGame.getGameObjectsVector().size()==2);
	//newGame.CheckScoreStatus();
	//CHECK(*newGame.getScore() == laserPoints);
}

TEST_CASE("ArcSegment-player collision - check deletion, damage dealt"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::LaserGenerator, 1);
	int oldHealth = newGame.getGameObjectsVector()[0]->getHealth();
	shared_ptr<GameObject> testArc = newGame.getGameObjectsVector()[2];
	float arcAngle = testArc->getAngle();
	int arcPoints = testArc->getPoints();
	CHECK(testArc->getObjectType() == gameObjectType::ArcSegment);
	
	shared_ptr<GameObject> play_GO = newGame.getGameObjectsVector()[0];
	shared_ptr<Player> play_ptr = std::static_pointer_cast<Player>((*play_GO).getptr());
	play_ptr->circularMove(arcAngle/2);
	
	int oldSize = newGame.getGameObjectsVector().size();
	while(newGame.getGameObjectsVector().size()==oldSize){
		testArc->lineMove();
		newGame.CheckCollisions();
		newGame.ObjectCleanup();
		}
	
	CHECK(newGame.getGameObjectsVector().size()==1);
	CHECK(newGame.getGameObjectsVector()[0]->getHealth() == oldHealth-1);
}


TEST_CASE("ArcSegment-playerBullet collision - check deletion"){
	Game newGame(5);
	newGame.AddGameObject(gameObjectType::LaserGenerator, 1);
	int oldHealth = newGame.getGameObjectsVector()[0]->getHealth();
	shared_ptr<GameObject> testArc = newGame.getGameObjectsVector()[2];
	float arcAngle = testArc->getAngle();
	CHECK(testArc->getObjectType() == gameObjectType::ArcSegment);
	
	shared_ptr<GameObject> play_GO = newGame.getGameObjectsVector()[0];
	shared_ptr<Player> play_ptr = std::static_pointer_cast<Player>((*play_GO).getptr());
	play_ptr->circularMove(arcAngle/2);
	
	newGame.AddGameObject(gameObjectType::PlayerBullet,1);
	shared_ptr<GameObject> testBullet = newGame.getGameObjectsVector()[2];
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::PlayerBullet);
	
	int oldSize = newGame.getGameObjectsVector().size();
	while(newGame.getGameObjectsVector().size()==oldSize){
		testArc->lineMove();
		testBullet->lineMove();
		newGame.CheckCollisions();
		newGame.ObjectCleanup();
		}
	
	//CHECK(newGame.getGameObjectsVector().size()==oldSize-1);
	//CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::PlayerBullet);

}

// Satellite collisions
TEST_CASE("Satellite-player collision - check damage dealt, deletions"){
	Game newGame(5);
	int oldHealth = newGame.getGameObjectsVector()[0]->getHealth();
	
	newGame.AddGameObject(gameObjectType::Satellite, 1);
	shared_ptr<GameObject> testSat = newGame.getGameObjectsVector()[1];
	float satAngle = testSat->getAngle();
	
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::Satellite);
	
	newGame.AddGameObject(gameObjectType::EnemyBullet, 1);
	shared_ptr<GameObject> testEnBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::EnemyBullet);
	
	shared_ptr<GameObject> play_GO = newGame.getGameObjectsVector()[0];
	shared_ptr<Player> play_ptr = std::static_pointer_cast<Player>((*play_GO).getptr());
	play_ptr->circularMove(satAngle/2);
	
	int oldSize = newGame.getGameObjectsVector().size();
	while(newGame.getGameObjectsVector().size()==oldSize){
		testEnBullet->lineMove();
		newGame.CheckCollisions();
		newGame.ObjectCleanup();
	}
	
	CHECK(newGame.getGameObjectsVector()[0]->getHealth()==oldHealth-1);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() != gameObjectType::EnemyBullet);
	
}

TEST_CASE("Satellite-playerBullet collision - check deletions, score update"){
	Game newGame(5);
	
	newGame.AddGameObject(gameObjectType::Satellite, 1);
	shared_ptr<GameObject> testSat = newGame.getGameObjectsVector()[1];
	float satAngle = testSat->getAngle();
	int satPoints = testSat->getPoints();
	
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::Satellite);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-2]->getObjectType() == gameObjectType::Satellite);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-3]->getObjectType() == gameObjectType::Satellite);
	
	shared_ptr<GameObject> play_GO = newGame.getGameObjectsVector()[0];
	shared_ptr<Player> play_ptr = std::static_pointer_cast<Player>((*play_GO).getptr());
	play_ptr->circularMove(satAngle/2);
	
	newGame.AddGameObject(gameObjectType::PlayerBullet, 1);
	shared_ptr<GameObject> testBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::PlayerBullet);
	
	int oldSize = newGame.getGameObjectsVector().size();
	while(newGame.getGameObjectsVector().size()==oldSize){
		testBullet->lineMove();
		newGame.CheckCollisions();
		newGame.ObjectCleanup();
	}
	
	CHECK(newGame.getGameObjectsVector().size()== oldSize-2);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::Satellite);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-2]->getObjectType() == gameObjectType::Satellite);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-3]->getObjectType() == gameObjectType::Player);
	//CHECK(*newGame.getScore()==satPoints);
}

TEST_CASE("Satellite set deletion - check score update, deletions, gun power-up"){
	Game newGame(5);
	
	newGame.AddGameObject(gameObjectType::Satellite, 1);
	
	shared_ptr<GameObject> testSat = newGame.getGameObjectsVector()[1];
	shared_ptr<GameObject> play_GO = newGame.getGameObjectsVector()[0];
	shared_ptr<Player> play_ptr = std::static_pointer_cast<Player>((*play_GO).getptr());
	int satPoints = testSat->getPoints();
		
	for(int a = 0;a<4;a++){
		testSat = newGame.getGameObjectsVector()[1];
		float satAngle = testSat->getAngle();
		
		play_ptr->circularMove(satAngle/2);
		
		newGame.AddGameObject(gameObjectType::PlayerBullet, 1);
		shared_ptr<GameObject> testBullet = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
		CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::PlayerBullet);
		
		int oldSize = newGame.getGameObjectsVector().size();
		while(newGame.getGameObjectsVector().size()==oldSize){
			testBullet->lineMove();
			newGame.CheckCollisions();
			newGame.ObjectCleanup();
		}
	}
	
	CHECK(play_ptr->getGunLevel()== 2);
	CHECK(newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1]->getObjectType() == gameObjectType::Player);
	//CHECK(*newGame.getScore()==satPoints);
}

// Other game collision scenarios
TEST_CASE("All lives lost - check player is deleted, new game can be started"){
	
}

TEST_CASE("High score - check it is updated when new score is higher"){
	
}