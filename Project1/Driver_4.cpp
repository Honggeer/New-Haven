//#include <vector>
//#include "GBMapLoader.h"
//#include "GBMap.h"
//#include "Player.h"
//#include"VGMap.h"
//#include "VGMapLoader.h"
//using namespace std;
//int main() {
//
//	GBMapLoader* gbml = new GBMapLoader();
//	VGMapLoader* vgml1 = new VGMapLoader();
//	VGMapLoader* vgml2 = new VGMapLoader();
//	VGMapLoader* vgml3 = new VGMapLoader();
//	cout << "There is the 2 players game...... " << endl;
//	cout << "Honggeer vs Xavier...." << endl;
//	cout << "Suppose they filled their VGmap already....." << endl;
//	vgml1->readfromfile("VillageBoard2.txt");
//	vgml2->readfromfile("VillageBoard2.txt");
//	vgml3->readfromfile("VillageBoard2.txt");
//	BuildingDeck* bd = new BuildingDeck();
//	Player* p1 = new Player("Honggeer", 1, vgml1->getVGMap());
//	Player* p2 = new Player("Xavier", 2, vgml2->getVGMap());
//	Player* p3 = new Player("Luan", 3, vgml3->getVGMap());
//
//
//	Building* b1 = new Building(6, Building::sheep);
//	Building* b2 = new Building(5, Building::sheep);
//	Building* b3 = new Building(4, Building::sheep);
//	Building* b7 = new Building(6, Building::stone);
//	Building* b8 = new Building(5, Building::stone);
//	Building* b11 = new Building(2, Building::timber);
//	//P1 has above
//	Building* pb1 = new Building(6, Building::sheep);
//	Building* pb2 = new Building(5, Building::sheep);
//	Building* pb3 = new Building(4, Building::sheep);
//	Building* b4 = new Building(3, Building::wheat);
//	Building* b5 = new Building(2, Building::wheat);
//	Building* b6 = new Building(1, Building::wheat);
//	//P2 has above
//	Building* b9 = new Building(3, Building::timber);
//	Building* b10 = new Building(3, Building::timber);
//	Building* pb11 = new Building(3, Building::timber);
//	Building* b12 = new Building(3, Building::timber);
//	Building* b13 = new Building(3, Building::timber);
//	Building* b14 = new Building(4, Building::timber);
//	int* r;
//	int r1[4] = { 1000,1000,1000,1000 };
//	r = r1;
//	p1->setRMS(r);
//	p2->setRMS(r);
//	p3->setRMS(r);
//	p1->addBuilding(b1);
//	p1->addBuilding(b2);
//	p1->addBuilding(b3);
//	p1->addBuilding(b7);
//	p1->addBuilding(b8);
//	p1->addBuilding(b11);
//	cout << "here is what Honggeer got....." << endl;
//	p1->showBuildings();
//	p2->addBuilding(pb1);
//	p2->addBuilding(pb2);
//	p2->addBuilding(pb3);
//	p2->addBuilding(b4);
//	p2->addBuilding(b5);
//	p2->addBuilding(b6);
//	cout << "here is what Xavier got...." << endl;
//	p2->showBuildings();
//	p3->addBuilding(b9);
//	p3->addBuilding(b10);
//	p3->addBuilding(pb11);
//	p3->addBuilding(b12);
//	p3->addBuilding(b13);
//	p3->addBuilding(b14);
//	cout << "Here is what Luan got......" << endl;
//	p3->showBuildings();
//	p1->BuildingVillage(0, 16);
//	p1->BuildingVillage(0, 15);
//	p1->BuildingVillage(0, 14);
//	p1->BuildingVillage(0, 36);
//	p1->BuildingVillage(0, 35);
//	p1->BuildingVillage(0, 12);
//
//	cout << "...................." << endl;
//	cout << "Honggeer finished building......" << endl;
//	p2->showBuildings();
//	p2->BuildingVillage(0, 16);
//	p2->BuildingVillage(0, 15);
//	p2->BuildingVillage(0, 14);
//	p2->BuildingVillage(0, 13);
//	p2->BuildingVillage(0, 12);
//	p2->BuildingVillage(0, 11);
//	cout << ".................." << endl;
//	cout << "Xavier finished building............" << endl;
//	p3->showBuildings();
//	p3->BuildingVillage(0, 13);
//	p3->BuildingVillage(0, 23);
//	p3->BuildingVillage(0, 33);
//	p3->BuildingVillage(0, 43);
//	p3->BuildingVillage(0, 53);
//	p3->BuildingVillage(0, 54);
//	cout << ".................." << endl;
//	cout << "Luan finished building............" << endl;
//	cout << "Here is the status of the VGmap of Honggeer......" << endl;
//	p1->printVGMap();
//	cout << "Here is the status of the VGmap of Xavier......" << endl;
//	p2->printVGMap();
//	cout << "Here is the status of the VGmap of Luan......" << endl;
//	p3->printVGMap();
//	cout << "Here is the scores...." << endl;
//	
//	cout << "Honggeer: " << p1->calculateScore() << endl;
//	cout << "Xavier: " << p2->calculateScore() << endl;
//	cout << "Luan: " << p3->calculateScore() << endl;
//	vector <Player*>* playersVector = new vector<Player*>();
//	playersVector->push_back(p1);
//	playersVector->push_back(p2);
//	playersVector->push_back(p3);
//	bool winner[] = { false,false,false,false };
//	int winners = 0;
//	int highest = 0;
//	int lowest = 0;
//	int sameAsHighers;
//	// find the higest score
//	for (int i = 0; i < playersVector->size(); i++) {
//		if (playersVector->at(i)->calculateScore() > highest)
//			highest = playersVector->at(i)->calculateScore();
//	}
//	//check who have and how many players have the highest score;
//	for (int i = 0; i < playersVector->size(); i++) {
//		if (playersVector->at(i)->getScore() == highest) {
//			winner[i] = true;
//			winners++;
//		}
//	}
//	//if there is a tie
//	if (winners > 1) {
//		int lowest = 100;
//		// find the lowest number of leftover building slot
//		for (int i = 0; i < playersVector->size(); i++) {
//			if (winner[i] == true) {
//				if (playersVector->at(i)->leftPlaceVG() < lowest) {
//					lowest = playersVector->at(i)->leftPlaceVG();
//				}
//			}
//		}
//		// check who and how many player have the empty space the least leftover space
//		for (int i = 0; i < playersVector->size(); i++) {
//			if (winner[i] == true) {
//				if (playersVector->at(i)->leftPlaceVG() > lowest) {
//					winner[i] = false;
//					winners--;
//				}
//			}
//		}
//		//if its still a tie
//		if (winners > 1) {
//			lowest = 100;
//			//find the lowest number of building tiles in hand
//			for (int i = 0; i < playersVector->size(); i++) {
//				if (winner[i] == true) {
//					if (playersVector->at(i)->leftBuildings() < lowest) {
//						lowest = playersVector->at(i)->leftBuildings();
//					}
//				}
//			}
//			// check who have it
//			for (int i = 0; i < playersVector->size(); i++) {
//				if (winner[i] == true) {
//					if (playersVector->at(i)->leftBuildings() > lowest) {
//						winner[i] = false;
//						winners--;
//					}
//				}
//			}
//
//
//
//		}
//
//	}
//
//	cout << "winner is ";
//	for (int i = 0; i < playersVector->size(); i++) {
//		if (winner[i] == true) {
//			cout << playersVector->at(i)->getName();
//		}
//	}
//
//	cout << "Game ends";
//	string end;
//	cin >> end;
//	return 0;
//
//}