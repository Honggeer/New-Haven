//
//
//#include "Player.h"
//
//#include "TurnObserver.h"
//#include "StatisticObserver.h"
//#include <string>
//#include <iostream>
//#include <vector>
//#include "VGMapLoader.h"
//
//
//using namespace std;
//void error() {
//	cin.clear(); //clear bad input flag
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
//	cout << "Invalid input; please re-enter.\n" << endl;
//
//}
//int main() {
//	
//	
//	int input;
//	//***********************************************part1***********************************************
//	// buid game board map according player number
//	int players;
//
//	
//
//
//	while ((cout << "How many players there will be ? (2-4 players)\n" && !(cin >> players)) || (players < 2 || players>4)) {
//		error();
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
//	
//	Player::setGBMap(gbml->getMap());
//	//building vgmap for each players
//	VGMapLoader* VG;
//	string villageName[4] = { "GUILFORD","STRATFORD","FAIRFIELD","DOWNTOWN" };
//	
//	vector <Player*>* playersVector = new vector<Player*>();
//	//6,7,8
//	BuildingDeck* bd = new BuildingDeck();
//	TileDeck* td = new TileDeck();
//	vector <TurnObserver*>* TurnOs=new vector<TurnObserver*>();
//
//
//	Tile original[4];
//	vector<Building*>* buildingPool = new vector<Building*>();
//	for (int i = 0; i < 5; i++) {
//		buildingPool->push_back(&bd->draw());
//	}
//	//to show remeber if player played shipment card
//	int shipmemtTimes[4] = { 1,1,1,1 };
//	Player* playerP;
//	TurnObserver* TurnO;
//	string playerNames[4] = { "Justin","Jin Ping","Vladimir","Donald" };
//	for (int i = 0; i < players; i++) {
//
//		//9.when i create player class, they already have empty hand
//		VG = new VGMapLoader(villageName[i]);
//		VG->readfromfile("VillageBoard2.txt");
//		playerP = new Player(playerNames[i], i, VG->getVGMap());
//		TurnO = new TurnObserver(playerP);
//		TurnOs->push_back(TurnO);
//		playersVector->push_back(playerP);
//
//		VG = nullptr;
//
//		//10. draw 6 building tile, 2 harvest tile
//		//getchar();
//		//cout << '\n' << "To draw your 6 Buildings and 2 Tiles press Enter.";
//		//getchar();
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
//	StatisticsObserver* SO = new StatisticsObserver(playersVector);
//	string playShipment;
//	string type;
//	int index;
//
//
//	int tileIndex;
//	int tileLocation;
//	int buildingIndex;
//	int buildingLocation;
//	string keepBuild;
//	Tile* temp;
//	cout << "**************************************************" << endl;
//	while (!Player::getGBMap()->onePlaceLeft()) {
//		for (int i = 0; i < playersVector->size(); i++) {
//			playersVector->at(i)->setRgToZero();
//			cout << "\nIt is " << playersVector->at(i)->getName() << "'s turn. (Press Enter)" << endl;
//			getchar();
//			playersVector->at(i)->showTiles();
//			if (shipmemtTimes[i] == 1) {
//				cout << "Do you want to play your shipment card (please enter yes or no)" << endl;
//				cin >> playShipment;
//				while (playShipment != "yes" && playShipment != "no") {
//					cout << "Invalid answer, enter yes or no." << endl;
//					cin >> playShipment;
//				}
//				if (playShipment == "yes") {
//					cout << "\nWhich resource type would you like to choose? (wheat,stone,timber,sheep)" << endl;
//					cin >> type;
//					while (type != "wheat" && type != "stone"&& type != "timber" && type != "sheep") {
//						cout << "Invalid answer, enter wheat, stone, timber or sheep." << endl;
//						cin >> type;
//					}
//					temp = new Tile(Tile::sToTypes(type), Tile::sToTypes(type), Tile::sToTypes(type), Tile::sToTypes(type));
//
//
//					cout << "\nWhere do you want to place the shipment tile on the board? (Enter -1 to see the board) "<<endl;
//					while (!(cin >> tileLocation))
//						error();
//					if (tileLocation == -1) {
//						Player::getGBMap()->print();
//						cout << "\nWhere do you want to place the shipment tile on the board?"<<endl;
//						while (!(cin >> tileLocation))
//							error();
//					}
//					while (true) {
//						if (Player::getGBMap()->SearchById(tileLocation)->getTileSlotId() == 0) {
//							cout << "\nInvalid Location, this is not on the board! Enter again." << endl;
//							while (!(cin >> tileLocation))
//								error();
//							continue;
//						}
//						if (!Player::getGBMap()->SearchById(tileLocation)->isEmpty()) {
//							cout << "\nThere is already a tile here! Enter again." << endl;
//							while (!(cin >> tileLocation))
//								error();
//							continue;
//
//						}
//						break;
//					}
//					Player::getGBMap()->SearchById(tileLocation)->setTile(*temp);
//				}
//			}
//			if (shipmemtTimes[i] != 1 || playShipment == "no") {
//				cout << "\nChoose one card and where you want to place it. (Enter the index of the card followed by the location on the map)" << endl;
//				
//				while(!(cin >> tileIndex))
//					error();
//				while(!(cin >> tileLocation))
//					error();
//
//				while (!playersVector->at(i)->PlaceHarvestTile(tileIndex, tileLocation, Player::getGBMap())) {
//					cout << "Enter the index followed by the location again." << endl;
//					while (!(cin >> tileIndex))
//						error();
//					while (!(cin >> tileLocation))
//						error();
//				}
//
//
//			}
//			if (Player::getGBMap()->onePlaceLeft())
//				break;
//			playersVector->at(i)->CalculateResources(Player::getGBMap()->SearchById(tileLocation));
//			//show player their score and map
//
//			cout << "\nYou have those resources:" << endl;
//			playersVector->at(i)->showResourceMarkers();
//
//			//********************************************************build village************************************************************************
//			cout << "What do you want to do?" << endl;
//			cout << " Enter 0: Look at your Village Board.\n Enter 1: Look at your Building Cards\n Enter 2: Build a Building\n Enter 3: End turn" << endl;
//			while(!(cin >> input))
//				error();
//			while (input != 3) {
//
//				switch (input) {
//				case 0:	playersVector->at(i)->printVGMap();
//					break;
//				case 1: playersVector->at(i)->showBuildings();
//					break;
//				case 2:	cout << "Which building tile you want to place?" << endl;
//					while (!(cin >> buildingIndex))
//						error();
//					if (playersVector->at(i)->buildingsSize() < buildingIndex || buildingIndex < -1) {
//						cout << "Error, building index out of the bound." << endl;
//						break;
//					}
//					cout << "Which location you want to place it? " << playersVector->at(i)->availableBS(playersVector->at(i)->getBuilding(buildingIndex)->getCost()) + "" << ". Enter any locations if you intend to flip you building." << endl;
//					while(!(cin >> buildingLocation))
//						error();
//					while (!playersVector->at(i)->BuildingVillage(buildingIndex, buildingLocation)) {
//						cout << "Error, please enter the index and the location again." << endl;
//						cout << "Which building tile you want to place? (Enter -1 to go back to the Menu)" << endl;
//						while (!(cin >> buildingIndex))
//							error();
//						if (playersVector->at((i + 1) % playersVector->size())->buildingsSize() < buildingIndex || buildingIndex < -1) {
//							cout << "Error, building index out of the bound. Please enter the index and the location again." << endl;
//							break;
//						}
//						if (buildingIndex == -1)
//							break;
//						cout << "Which location you want to place it?" << playersVector->at(i)->availableBS(playersVector->at(i)->getBuilding(buildingIndex)->getCost()) + "" << ". Enter any locations if you intend to flip you building." << endl;
//						while (!(cin >> buildingLocation))
//							error();
//					}
//					break;
//				case 3:
//					break;
//				default:cout << "Error, please enter a valid option. " << endl;
//				}
//				cout << "\nYou have those resources:" << endl;
//				playersVector->at(i)->showResourceMarkers();
//				cout << "What do you want to do?" << endl;
//				cout << " Enter 0: Look at your Village Board.\n Enter 1: Look at your Building Cards\n Enter 2: Build a Building\n Enter 3: End turn" << endl;
//				while (!(cin >> input))
//					error();
//
//			}
//
//			//**************************************************share wealth************************************************************************************8
//			for (int j = 1; j < playersVector->size(); j++) {
//				if (playersVector->at(i)->rmsIsEmpty())
//					break;
//				cout << "\n" << playersVector->at((i + j) % playersVector->size())->getName() << ", there is those resources available:" << endl;
//				playersVector->at(i)->showResourceMarkers();
//				playersVector->at((i + j) % playersVector->size())->setRMS(playersVector->at(i)->getRMS());
//				cout << "What do you want to do?" << endl;
//				cout << " Enter 0: Look at your Village Board.\n Enter 1: Look at your Building Cards\n Enter 2: Build a Building\n Enter 3: Pass" << endl;
//				while (!(cin >> input))
//					error();
//				while (input != 3) {
//					switch (input) {
//					case 0:	playersVector->at((i + j) % playersVector->size())->printVGMap();;
//						break;
//					case 1: playersVector->at((i + j) % playersVector->size())->showBuildings();
//						break;
//					case 2:	cout << "Which building tile you want to place?" << endl;
//						cin >> buildingIndex;
//						if (playersVector->at((i + j) % playersVector->size())->buildingsSize() < buildingIndex || buildingIndex < -1) {
//							cout << "Error, building index out of the bound. Please enter the index and the location again." << endl;
//							break;
//						}
//						cout << "Which location you want to place it?" << playersVector->at((i + j) % playersVector->size())->availableBS(playersVector->at((i + j) % playersVector->size())->getBuilding(buildingIndex)->getCost()) + "" << ". Enter any locations if you intend to flip you building." << endl;
//						while (!(cin >> buildingLocation))
//							error();
//						while (!playersVector->at((i + j) % playersVector->size())->BuildingVillage(buildingIndex, buildingLocation)) {
//							cout << "Error, please enter the index and the location again." << endl;
//							cout << "Which building tile you want to place? (Enter -1 to go back to the Menu)" << endl;
//							while (!(cin >> buildingIndex)&& playersVector->at((i + j) % playersVector->size())->buildingsSize() < buildingIndex || buildingIndex < -1)
//								error();
//							/*if (playersVector->at((i + j) % playersVector->size())->buildingsSize() < buildingIndex || buildingIndex < -1) {
//								cout << "Error, building index out of the bound." << endl;
//								break;
//							}*/
//							if (buildingIndex == -1)
//								break;
//							
//							cout << "Which location you want to place it?" << playersVector->at((i + j) % playersVector->size())->availableBS(playersVector->at((i + j) % playersVector->size())->getBuilding(buildingIndex)->getCost()) + "" << ". Enter any locations if you intend to flip you building." << endl;
//							while(!(cin >> buildingLocation))
//								error();
//							
//						}
//						if (buildingIndex == -1)
//							break;
//						playersVector->at(i)->setRMS(playersVector->at((i + j) % playersVector->size())->getRMS());
//						input = 3;
//						continue;
//					case 3:
//						break;
//
//					default:cout << "Error, please enter a valid option. " << endl;
//					}
//
//						cout << "What do you want to do?" << endl;
//						cout << " Enter 0: Look at your Village Board.\n Enter 1: Look at your Building Cards\n Enter 2: Build a Building\n Enter 3: Pass" << endl;
//						while (!(cin >> input))
//							error();
//
//				}
//					
//			}
//		
//			bool first = true;
//			getchar();
//			cout << playersVector->at(i)->getName() << ", it's time to pick up cards. (Press Enter)" << endl;
//			getchar();
//			for (int x = 0; x < 4; x++)
//				if (playersVector->at(i)->getRMS()[x] == 0) {
//
//					for (int j = 0; j < buildingPool->size(); j++) {
//						cout << "\nNO." << j;
//						buildingPool->at(j)->toString();
//					}
//					if (first) {
//						cout << "\nGive the index of the building you want." << endl;
//						while (!(cin >> index)||index>=buildingPool->size()||index<0)
//							error();
//						playersVector->at(i)->addBuilding(buildingPool->at(index));
//						buildingPool->erase(buildingPool->begin() + index);
//						first = false;
//					}
//					else {
//						cout << "\nGive the index of the building you want or enter -1 to draw from the pile." << endl;
//
//						while (!(cin >> index)&&index!=-1&&!(index<buildingPool->size())) {
//							error();
//						}
//						if (index < 0)
//							playersVector->at(i)->DrawBuilding(bd);
//						else {
//							playersVector->at(i)->addBuilding(buildingPool->at(index));
//							buildingPool->erase(buildingPool->begin() + index);
//
//						}
//					}
//				}
//
//
//			while (buildingPool->size() < 5) {
//				buildingPool->push_back(&bd->draw());
//			}
//			// change back the shipment card
//			if (playShipment == "yes") {
//				gbml->getMap()->SearchById(tileLocation)->setTile(original[i]);
//				shipmemtTimes[i] = 0;
//			}
//			else {
//				cout << "\nYou drew this Harvest Tile:" << endl;
//				playersVector->at(i)->DrawHarvestTile(td);
//			}
//			getchar();
//
//		}
//	}
//	delete gbml;
//	gbml = nullptr;
//	delete[] playersVector;
//	playersVector = nullptr;
//	delete bd;
//	bd = nullptr;
//	delete td;
//	td = nullptr;
//	
//	
//	return 0;
//}