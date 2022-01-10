//
// Created by Kunming Yang on 2020-01-22.
//
#pragma once

#ifndef PROJECT_GBMAPLOADER_H
#define PROJECT_GBMAPLOADER_H

#include "GBMap.h"
#include "Resources.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

static Tile::Types sToTypes(std::string str)
{
	if (str == "Sheep")
		return Tile::sheep;
	else if (str == "Wheat")
		return Tile::wheat;
	else if (str == "Stone")
		return Tile::stone;
	else if (str == "Timber")
		return Tile::timber;
};

class GBMapLoader
{
private:
	GBMap * map;
public:
	GBMapLoader();

	virtual ~GBMapLoader();
	virtual void readfromfile(std::string);

	void error_m();

	GBMap* getMap();

	void setMap(GBMap *GBMap_);
};



#endif //PROJECT_GBMAPLOADER_H
