#pragma once

#pragma once
#include "VGMap.h"
#include <string>
#include <vector>
#include <algorithm>
class VGMap;
class Building;



class VillageScore {
public:

	VillageScore(); //Default
	VillageScore(VGMap* VG); // parametrized constructor
	~VillageScore();;

	void evaluate(); 
	int& getScore();




private:
	VGMap* VG;
	int* score;

};

