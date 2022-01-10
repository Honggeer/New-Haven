//
// Created by Meiyi Luan on 2020-02-04.
//


#ifndef COMP_345_RESOURCESGATHER_H
#define COMP_345_RESOURCESGATHER_H

#include <iostream>
#include "Resources.h"
#include "GBMap.h"
#include <vector>
//#include "VGMap.h"
//#include "VGMapLoader.h"
#include "GBMapLoader.h"
using namespace std;
class ResourcesGather {
private:

	int* resources;// sheep wheet stone timber
	std::vector <Tile::Types*> *alreadycount;
	std::vector<Tile::Types*> *counted;




public:
	ResourcesGather();
	~ResourcesGather();
	// call four fouction below it
	//void allGather(TileSlot ts, bool connection[]);
	void allGather2(TileSlot *ts, bool connection[]);
	//void Gather(Tile::Types t,TileSlot ts,GBMap map,bool direction []);
	void add(bool a[], Tile *t);
	void add2(bool a[], Tile *t);
	int* getResources();
	void setToZero();
	bool incount(Tile::Types* ty);
	


};

#endif //COMP_345_RESOURCESGATHER_H