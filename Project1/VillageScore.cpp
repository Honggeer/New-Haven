#include "VillageScore.h"
#include <sstream>
#include <algorithm>
using namespace std;

VillageScore::VillageScore()
{
	VG = new VGMap();
	score = new int(0);
}


VillageScore::VillageScore(VGMap* VG_)
{
	VG = VG_;
	score = new int(0);
	
}

VillageScore:: ~VillageScore() {

	delete VG;
	delete score;
}
int &VillageScore::getScore() {
	return *score;
}
void VillageScore:: evaluate() {

	
	bool isFlippedr = false;
	int scores[5] = {5,4,3,4,5};
	
	
	for (int i = 0; i < VG->getBuildingSlots().size(); i++) {
		
		if (VG->getBuildingSlots().at(i)->getBuilding()->getCost() == 0) {
			i += 5 - (i % 5);
			continue;
		}

		if (VG->getBuildingSlots().at(i)->getBuilding()->getFlip() == 1) {
			isFlippedr = true;
		}
			

		if (i % 5 == 4) {
			if (isFlippedr == false) {
				*score += ((i+1)/5)*2;
				//cout <<score << endl;
			}
			else {
				cout << "p\n";
					*score += (i+1)/5;
			}
			isFlippedr = false;
		}

	}
	isFlippedr = false;

	for (int i = 0; i < 5; i++) {
		int breaked = 0;
		for (int j = i; j < 30; j += 5) {
		
			if (VG->getBuildingSlots().at(j)->getBuilding()->getCost()==0) 
				break;
			

			if (VG->getBuildingSlots().at(j)->getBuilding()->getFlip()==1)
				isFlippedr = true;

			if (j > 24) {
				if (isFlippedr == false)
					*score += scores[i%5]* 2;
				else
					*score += scores[i%5];
				isFlippedr = false;
			}
		}
		


	}


	
}


