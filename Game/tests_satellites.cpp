#include "Player.h"
#include "Game.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITHOUT_MAIN
#include "doctest.h"

// Satellite tests

TEST_CASE("Check satellites can be instantiated, are instantiated three at a time and are of type 'Satellite'"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::Satellite, 0);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 3);
	CHECK(newGame.getGameObjectsVector()[oldSize]->getObjectType() == gameObjectType::Satellite);
	CHECK(newGame.getGameObjectsVector()[oldSize+1]->getObjectType() == gameObjectType::Satellite);
	CHECK(newGame.getGameObjectsVector()[oldSize+2]->getObjectType() == gameObjectType::Satellite);
}

TEST_CASE("Check three satellites are instantiated with the same ID"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::Satellite, 0);
	
	shared_ptr<GameObject> sat1_GO = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	shared_ptr<Satellite> sat1_ptr = std::static_pointer_cast<Satellite>((*sat1_GO).getptr());
	int satID1 = sat1_ptr->getID();
	
	shared_ptr<GameObject> sat2_GO = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-2];
	shared_ptr<Satellite> sat2_ptr = std::static_pointer_cast<Satellite>((*sat2_GO).getptr());
	int satID2 = sat2_ptr->getID();
	
	shared_ptr<GameObject> sat3_GO = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-3];
	shared_ptr<Satellite> sat3_ptr = std::static_pointer_cast<Satellite>((*sat3_GO).getptr());
	int satID3 = sat3_ptr->getID();
	
	CHECK(satID2 == satID1);
	CHECK(satID3 == satID2);
}

TEST_CASE("Check separate satellite sets have different IDs"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::Satellite, 0);
	newGame.AddGameObject(gameObjectType::Satellite, 0);
	
	shared_ptr<GameObject> sat1_GO = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-1];
	shared_ptr<Satellite> sat1_ptr = std::static_pointer_cast<Satellite>((*sat1_GO).getptr());
	int satID1 = sat1_ptr->getID();
	
	shared_ptr<GameObject> sat2_GO = newGame.getGameObjectsVector()[newGame.getGameObjectsVector().size()-4];
	shared_ptr<Satellite> sat2_ptr = std::static_pointer_cast<Satellite>((*sat2_GO).getptr());
	int satID2 = sat2_ptr->getID();
	
	CHECK(satID2 != satID1);
}

TEST_CASE("Check number of bullets shot increases with gun upgrade"){
	Game newGame(5);
	int oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::PlayerBullet, 0);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 1);
	
	shared_ptr<GameObject> player_GO = newGame.getGameObjectsVector()[0];
	shared_ptr<Player> player_ptr = std::static_pointer_cast<Player>((*player_GO).getptr());
	player_ptr->UpgradeGun();
	
	oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::PlayerBullet, 0);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 2);
	CHECK(newGame.getGameObjectsVector()[oldSize]->getObjectType() == gameObjectType::PlayerBullet);
	CHECK(newGame.getGameObjectsVector()[oldSize+1]->getObjectType() == gameObjectType::PlayerBullet);
	
	player_ptr->UpgradeGun();
	
	oldSize = newGame.getGameObjectsVector().size();
	newGame.AddGameObject(gameObjectType::PlayerBullet, 0);
	CHECK(newGame.getGameObjectsVector().size() == oldSize + 3);
	CHECK(newGame.getGameObjectsVector()[oldSize]->getObjectType() == gameObjectType::PlayerBullet);
	CHECK(newGame.getGameObjectsVector()[oldSize+1]->getObjectType() == gameObjectType::PlayerBullet);
	CHECK(newGame.getGameObjectsVector()[oldSize+2]->getObjectType() == gameObjectType::PlayerBullet);
	
}

TEST_CASE("Check satellite is instantiated at same angle as player, ie chases player"){
	Game newGame(5);
	newGame.MovePlayerObject(1);
	newGame.MovePlayerObject(1);
	float playerAngle = newGame.getGameObjectsVector()[0]->getAngle();
	
	newGame.AddGameObject(gameObjectType::Satellite, 0);
	float satAngle = newGame.getGameObjectsVector()[1]->getAngle();
	
	CHECK(playerAngle == satAngle);
}