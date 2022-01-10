
#pragma once
#ifndef RESOURCES_H
#define RESOURCES_H
#include <iostream>



class Tile;
class TileDeck;
class Building;
class BuildingDeck;
class Hand;


static std::string enumToString(int t) {
	switch (t)
	{
	case 0: return "Sheep";
	case 1: return "Wheat";
	case 2: return "Stone";
	case 3: return "Timber";
	default: return "Empty";
	}

}

class Tile {


public:
	Tile();
	Tile(const Tile &T);
	enum Types {sheep,wheat,stone,timber};
	Tile(Types one, Types two, Types three, Types four);

	~Tile();
	static Types sToTypes(std::string s);
	Types& getUpLeft();
	Types& getUpRight();
	Types& getDownLeft();
	Types& getDownRight();
	Types* getTypeArray();
	void haveConnection(bool *a);

	void setUpLeft(Types s);
	void setUpRight(Types s);
	void setDownLeft(Types s);
	void setDownRight(Types s);
	//Types getRandomType();
	void setNumOfResources();
	void toString();
	void changeDirection();

private:
	int * numOfResources[4] = { 0,0,0,0 }; //index0:sheep index1:wheat index2:stone index3:timber
	Types*  typeArray;



};


class TileDeck {
private:
	Tile * allTiles;
public:
	Tile * draw();
	TileDeck();
	~TileDeck();

};
class Building {
public:
	enum Type { sheep, wheat, stone, timber };
	Building();
	Building(int num, Type t);
	Building(int cost, Type type, bool s);
	~Building();
	Type& getType();
	int& getCost();
	void setType(Type type);
	void setCost(int cost);
	void setFlipped(bool s);
	void turn();
	int getFlip();
	void toString();
	void boolToString(bool s);

private:
	bool* Flip;
	int* cost;
	Type* type;


};

class BuildingDeck {

	Building* allBuilding [144];
public:
	Building  &draw();
	BuildingDeck();
	~BuildingDeck();

};


class Hand {
private:

	int* numOfSheep;
	int* numOfStone;
	int* numOfwheat;
	int* numOfTimber;

public:
	Hand();
	Hand(int tree, int stone, int wheat, int timber);
	//void exchange(GBMapLoader gbmp);
	int& getNumOfSheep();
	int& getNumOfStone();
	int& getNumOfwheat();
	int& getNumOfTimber();
	void setNumOfSheep(int i);
	void setNumOfTimber(int i);
	void setNumOfStone(int i);
	void setNumOfwheat(int i);
	//void toString();
};


#endif // !RESOURCES_H

