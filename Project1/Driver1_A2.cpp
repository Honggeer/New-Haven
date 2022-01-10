//#include "Player.h"
//#include <string>
//#include <iostream>
//#include <vector>
//#include "VGMapLoader.h"
//
//using namespace std;
//
//int main() {
//	char input;
//	//***********************************************part1***********************************************
//	// buid game board map according player number
//	int players;
//
//
//	while ((cout << "How many players there will be ? (2-4 players)\n" && !(cin >> players)) || (players < 2 || players>4)) {
//		cin.clear(); //clear bad input flag
//		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
//		cout << "Invalid input; please re-enter.\n" << endl;
//	}
//
//	GBMapLoader* gbml = new GBMapLoader();
//
//	switch (players) {
//	case 2: gbml->readfromfile("GBMap2Players.txt");
//		break;
//	case 3: gbml->readfromfile("GBMap3Players.txt");
//		break;
//	case 4: gbml->readfromfile("GBMap4Players.txt");
//		break;
//	}
//	gbml->getMap()->SearchById(11)->getAdjacentTileSlots();
//	Player::setGBMap(gbml->getMap());
//	//building vgmap for each players
//	VGMapLoader* VG;
//	string villageName[4] = { "GUILFORD","STRATFORD","FAIRFIELD", };
//	string playerName;
//	vector <Player*>* playersVector = new vector<Player*>();
//	//6,7,8
//	BuildingDeck* bd = new BuildingDeck();
//	TileDeck* td = new TileDeck();
//	Tile original[4];
//	vector<Building*>* buildingPool = new vector<Building*>();
//	for (int i = 0; i < 5; i++) {
//		buildingPool->push_back(&bd->draw());
//	}
//	//to show remeber if player played shipment card
//	int shipmemtTimes[4] = { 1,1,1,1 };
//	Player* playerP;
//	string l;
//	for (int i = 0; i < players; i++) {
//		cout << "\nPlease enter the name of player " << i + 1 << "." << endl;
//		cin >> playerName;
//		//9.when i create player class, they already have empty hand
//		VG = new VGMapLoader();
//		VG->readfromfile("VillageBoard2.txt");
//		playerP = new Player(playerName, i, VG->getVGMap());
//		playersVector->push_back(playerP);
//		VG = nullptr;
//
//		//10. draw 6 building tile, 2 harvest tile
//		getchar();
//		cout << '\n' << "To draw your 6 Buildings and 2 Tiles press Enter.";
//		getchar();
//		cout << "\nThe Buildings you drew:" << endl;
//		for (int i = 0; i < 6; i++) {
//			cout << "\nN" << i;
//			playersVector->back()->DrawBuilding(bd);
//		}
//		cout << "\nThe Harvest Tiles you drew:" << endl;
//		for (int i = 0; i < 2; i++) {
//			cout << "\nN" << i << endl;
//			playersVector->back()->DrawHarvestTile(td);
//		}
//		//11. draw a shipment tile
//		original[i] = *td->draw();
//	}
//	getchar();
//	return 0;
//}