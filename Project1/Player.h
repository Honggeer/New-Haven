//
// Created by Meiyi Luan on 2020-02-09.
//





#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "ResourcesGather.h"
#include "VGMap.h"
#include "GBMap.h"
#include <string>
#include "Resources.h"
#include "VillageScore.h"
#include "Subject.h"




using namespace std;


class Player : public Subject {
private:
	string * name;
	VGMap* vgm;
	std::vector <Tile*> *tiles;
	std::vector <Building*> *buildings;
	int* rms;
	ResourcesGather* rg;
	int* order;
	bool* firstPlay;
	VillageScore* vs;
	int* currentPhase;
	int* numberOfBuildings;
	
	

public:
	//default constructor
	Player();
	//constructor
	Player(string name, int order);
	Player(string name, int order, VGMap* VG);
	//destructor
	~Player();
	static GBMap* GB;
	//getter
	string getName();
	int getOrder();
	int* getRMS();
	int* getNumberOfBuilings();
	VGMap* getVgmap();
	void setRMS(int *r);
	static GBMap* getGBMap();
	static void setGBMap(GBMap* gb);
	bool onePlaceLeft();
	void addBuilding(Building* B);
	string availableBS(int cost);

	Building* getBuilding(int index);
	//show tiles
	void showTiles();
	//show buildings
	void showBuildings();
	// show resource markers
	void showResourceMarkers();

	//fuctions on moodle
	bool PlaceHarvestTile(int index, int location, GBMap *map); //放Tile到GB上

	bool checkAdj(int index, int id);
	void DrawBuilding(BuildingDeck *bd);
	void DrawHarvestTile(TileDeck *td);
	string ResourcesTracker();
	bool BuildingVillage(int index, int location); //在VG建造建筑

	void CalculateResources(TileSlot *ts);
	int calculateScore();
	int getScore();
	void setRgToZero();
	void printVGMap();
	int leftPlaceVG();
	int leftBuildings();
	bool rmsIsEmpty();
	int buildingsSize();

	//A3
	int getCurrentPhrase();
	void decreaseResource(int index);
};

#endif //COMP_345_PLAYER_H

