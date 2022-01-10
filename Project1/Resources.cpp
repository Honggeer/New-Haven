#include "Resources.h"
#include <random>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;



Tile::Tile() {

	typeArray = new  Types[4]{ (Types)4, (Types)4, (Types)4, (Types)4 };

}

Tile::Tile(const Tile& T)
{
	typeArray = new  Types[4]{ (Types)4, (Types)4, (Types)4, (Types)4 };
	
	for (int i = 0; i < 4; i++) {
		typeArray[i] = T.typeArray[i];

	}
}

Tile::Tile(Types one, Types two, Types three, Types four) {

	typeArray = new Types[4]{ one,two,three,four };

}

Tile::~Tile() {
	delete[] typeArray;
	typeArray = nullptr;

}
Tile::Types* Tile::getTypeArray() {
	return typeArray;
}
Tile::Types& Tile::getUpLeft() {
	return typeArray[0];
}
Tile::Types& Tile::getUpRight() {
	return typeArray[1];
}
Tile::Types& Tile::getDownLeft() {
	return typeArray[2];
}
Tile::Types& Tile::getDownRight() {
	return typeArray[3];
}

void Tile::setUpLeft(Types s) {
	typeArray[0] = s;
}
void Tile::setUpRight(Types s) {
	typeArray[1] = s;
}
void Tile::setDownLeft(Types s) {
	typeArray[2] = s;
}
void Tile::setDownRight(Types s) {
	typeArray[3] = s;
}



void  Tile::setNumOfResources() {
	for (int i = 0; i < 4; i++) {
		if (typeArray[i] == 0)
			numOfResources[0]++;
		if (typeArray[i] == 1)
			numOfResources[1]++;
		if (typeArray[i] == 2)
			numOfResources[2]++;
		if (typeArray[i] == 3)
			numOfResources[3]++;
	}
};

void Tile::toString() {


	
	std::cout << "upleft: " << enumToString(typeArray[0]) << std::endl;
	std::cout << "upright: " << enumToString(typeArray[1]) << std::endl;
	std::cout << "downleft: " << enumToString(typeArray[2]) << std::endl;
	std::cout << "downright: " << enumToString(typeArray[3]) << std::endl;

}
void Tile::haveConnection(bool *a) {
	for (int i = 0; i < 4; i++) {
		if (a[i] == true) {
			if (i % 2 == 0) {
				if (getTypeArray()[i + 1] == getTypeArray()[i]) {
					a[i + 1] = true;

					if (getTypeArray()[i + 1] == getTypeArray()[(i + 3) % 4]) {
						a[(i + 3) % 4] = true;
						break;
					}
				}
				if (getTypeArray()[(i + 2) % 4] == getTypeArray()[i]) {
					a[(i + 2) % 4] = true;

					if (getTypeArray()[(i + 2) % 4] == getTypeArray()[(i + 3) % 4]) {
						a[(i + 3) % 4] = true;
						break;
					}
				}
			}
			else {
				if (getTypeArray()[i] == getTypeArray()[(i + 2) % 4]) {
					a[(i + 2) % 4] = true;

					if (getTypeArray()[(i + 2) % 4] == getTypeArray()[(i + 1) % 4]) {
						a[(i + 1) % 4] = true;
						break;
					}
				}
				if (getTypeArray()[i] == getTypeArray()[(i + 3) % 4]) {
					a[(i + 3) % 4] = true;

					if (getTypeArray()[(i + 3) % 4] == getTypeArray()[(i + 2) % 4]) {
						a[(i + 1) % 4] = true;
						break;
					}
				}
			}
		}
	}
}

Building::Type& Building::getType() {
	return *type;
}

int& Building::getCost() {
	return *cost;
}
void Building::setCost(int n) {
	cost = new int(n);
}

void Building::setType(Type s)
{
	*type = s;
}
Building::Building() {
	cost = new int(0);
	type = new Type();
	Flip = new bool (false);
}
Building::Building(int num, Type t) {
	cost = new int(num);
	type = new Type(t);
	Flip = new bool(false);
}
Building::Building(int num, Type t, bool s) {
	cost = new int(num);
	type = new Type(t);
	Flip = &s;
}
Building::~Building() {
	delete type;
	delete cost;
	delete Flip;
}
void Building::setFlipped(bool s) {
	*Flip = s;
}
int Building::getFlip() {
	return *Flip;
}
void Building::turn() {
	if (this->getFlip() == 0)
		this->setFlipped(1);
	else {
		this->setFlipped( 0);

	}
}
void Building::toString() {
	cout << "\nThe building's attributes" << endl;
	cout << "The type is: " << enumToString( *type) << endl;
	cout << "The cost is " << *cost << endl;
	cout << "If the building is flipped? " << *Flip <<endl;

}
BuildingDeck::BuildingDeck() {
	
	for (int j = 0; j < 6; j++) {

		for (int i = 0+j*24; i < 6 + j * 24; i++) {
			allBuilding[i] = new Building(int(j + 1), Building::Type::sheep);
			allBuilding[i]->setFlipped(false);
		}
		for (int i = 6 + j * 24; i < 12 + j * 24; i++) {
			allBuilding[i] = new Building(int(j + 1), Building::Type::stone);
			allBuilding[i]->setFlipped(false);
		}
		for (int i = 12 + j * 24; i < 18 + j * 24; i++) {
			allBuilding[i] = new Building(int(j + 1), Building::Type::timber);
			allBuilding[i]->setFlipped(false);
		}
		for (int i = 18 + j * 24; i < 24 + j * 24; i++) {
			allBuilding[i] = new Building(int(j + 1), Building::Type::wheat);
			allBuilding[i]->setFlipped(false);
		}
	}
}
BuildingDeck::~BuildingDeck() {
	for (int i = 0; i < 144; i++) {
		delete  allBuilding[i];
	}
	delete allBuilding;
}


Building &BuildingDeck::draw() {
	int n1 = rand() % 143;
	
	return *allBuilding[n1];
}
static Tile::Types getRandomType() {
	int ranNum = rand() % 4;

	switch (ranNum)
	{
	case 0:
		return Tile::Types::sheep;
		break;
	case 1:
		return Tile::Types::wheat;
		break;
	case 2:
		return Tile::Types::stone;
		break;
	case 3:
		return Tile::Types::timber;
		break;
	}
}
Tile::Types Tile::sToTypes(std::string str)
{
	if (str == "sheep")
		return sheep;
	else if (str == "wheat")
		return wheat;
	else if (str == "stone")
		return stone;
	else if (str == "timber")
		return timber;
}
TileDeck::TileDeck() {
	allTiles = new Tile[60]();
	for (int i = 0; i < 60; i++) {
		allTiles[i] = Tile();
	}
}
TileDeck::~TileDeck() {
	delete[] allTiles;
}
Tile* TileDeck::draw() {
	Tile *tile = new Tile();
	int r;

	r = rand() % 3;


	tile->setUpLeft(getRandomType());

	tile->setUpRight(getRandomType());

	tile->setDownLeft(getRandomType());

	tile->setDownRight(getRandomType());


	if ((tile->getUpLeft() == tile->getUpRight()) && (tile->getUpLeft() == tile->getDownLeft())) {
		//cout << "\nfirst if";
		while ((tile->getDownRight()) == (tile->getUpLeft())) {
			tile->setDownRight(getRandomType());
		}
	}

	if ((tile->getUpLeft() != tile->getUpRight()) && (tile->getUpLeft() != tile->getDownLeft()) && (tile->getUpRight() != tile->getDownLeft())) {
		//cout << "\nsecond if";
		switch (r) {
		case 0:
			tile->setDownRight(tile->getUpLeft());
			break;
		case 1:
			tile->setDownRight(tile->getUpRight());
			break;
		case 2:
			tile->setDownRight(tile->getDownLeft());
			break;
		}
	}

	return tile;

}
void Tile::changeDirection() {
	Types * temp = new Types[4]{ (Types)(typeArray[0]),(Types)(typeArray[1]),(Types)(typeArray[2]),(Types)(typeArray[3]) };
	typeArray[0] = temp[3];
	typeArray[1] = temp[0];
	typeArray[2] = temp[1];
	typeArray[3] = temp[2];
}


Hand::Hand() {
	numOfStone = new int(0);
	numOfTimber = new int(0);
	numOfSheep = new int(0);
	numOfwheat = new int(0);
}
Hand::Hand(int stone, int timber, int tree, int wheat) {
	numOfStone = new int(stone);
	numOfTimber = new int(timber);
	numOfSheep = new int(tree);
	numOfwheat = new int(wheat);
}
int& Hand::getNumOfStone() {
	return *numOfStone;
}
int& Hand::getNumOfTimber() {
	return *numOfTimber;

}
int& Hand::getNumOfSheep() {
	return *numOfSheep;
}

int& Hand::getNumOfwheat() {
	return *numOfwheat;
}

void Hand::setNumOfStone(int i) {
	numOfStone = new int(i);
}
void Hand::setNumOfTimber(int i) {
	numOfTimber = new int(i);
}
void Hand::setNumOfSheep(int i) {
	numOfSheep = new int(i);
}
void Hand::setNumOfwheat(int i) {
	numOfwheat = new int(i);
}


//
// Created by Meiyi Luan on 2020-02-24.
//

#include "Resources.h"
