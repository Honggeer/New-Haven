//Program to demonstrate that an array variable is a kind of pointer variable.
//
// Created by Kunming Yang on 2020-02-02.



#include "GBMap.h"
#include <iostream>
#include <time.h>
#include "ResourcesGather.h"
#include "Player.h"
#include "VGMapLoader.h"
#include "VGMap.h"
#include "VillageScore.h"


using namespace std;

int main() {

	srand(time(0));

//##################################GBMap Driver#####################################################################

	/*GBMap* map_ = new GBMap();
	TileSlot *TileSlot11 = new TileSlot(11);
	TileSlot *TileSlot12 = new TileSlot(12);
	TileSlot *TileSlot13 = new TileSlot(13);

	TileSlot *TileSlot21 = new TileSlot(21);
	TileSlot *TileSlot22 = new TileSlot(22);
	TileSlot *TileSlot23 = new TileSlot(23);

	TileSlot *TileSlot31 = new TileSlot(31);
	TileSlot *TileSlot32 = new TileSlot(32);
	TileSlot *TileSlot33 = new TileSlot(33);
	map_->addTileSlot(TileSlot11);
	map_->addTileSlot(TileSlot12);
    map_->addTileSlot(TileSlot13);

	map_->addTileSlot(TileSlot21);
	map_->addTileSlot(TileSlot22);
	map_->addTileSlot(TileSlot23);

	map_->addTileSlot(TileSlot31);
	map_->addTileSlot(TileSlot32);
	map_->addTileSlot(TileSlot33);

	map_->print();
	int a = map_->isConnectedGraph();
	if(a==0)
	cout << "\nFalse:The map is not a connected graph\n";
	else
		cout << "\nTrue:The map is a connected graph\n";

	TileSlot11->addAdjacentTileSlot(TileSlot12);
	TileSlot11->addAdjacentTileSlot(TileSlot21);

	TileSlot12->addAdjacentTileSlot(TileSlot11);
	TileSlot12->addAdjacentTileSlot(TileSlot22);
	TileSlot12->addAdjacentTileSlot(TileSlot13);

	TileSlot13->addAdjacentTileSlot(TileSlot12);
	TileSlot13->addAdjacentTileSlot(TileSlot23);

	TileSlot21->addAdjacentTileSlot(TileSlot31);
	TileSlot21->addAdjacentTileSlot(TileSlot11);
	TileSlot21->addAdjacentTileSlot(TileSlot22);

	TileSlot22->addAdjacentTileSlot(TileSlot12);
	TileSlot22->addAdjacentTileSlot(TileSlot21);
	TileSlot22->addAdjacentTileSlot(TileSlot32);
	TileSlot22->addAdjacentTileSlot(TileSlot23);

	TileSlot23->addAdjacentTileSlot(TileSlot13);
	TileSlot23->addAdjacentTileSlot(TileSlot33);
	TileSlot23->addAdjacentTileSlot(TileSlot22);

	TileSlot31->addAdjacentTileSlot(TileSlot21);
	TileSlot31->addAdjacentTileSlot(TileSlot32);

	TileSlot32->addAdjacentTileSlot(TileSlot31);
	TileSlot32->addAdjacentTileSlot(TileSlot33);
	TileSlot32->addAdjacentTileSlot(TileSlot22);

	TileSlot33->addAdjacentTileSlot(TileSlot32);
	TileSlot33->addAdjacentTileSlot(TileSlot23);

	a = map_->isConnectedGraph();
	if (a == 0)
		cout << "\nFalse:The map is not a connected graph\n";
	else
		cout << "\nTrue:The map is a connected graph\n";
	system("pause");*/

	//##################################-VGMap-##############################################################################################
	

	//VGMap* map_ = new VGMap();
	//BuildingSlot *BuildingSlot11 = new BuildingSlot(1, 11);
	//BuildingSlot *BuildingSlot12 = new BuildingSlot(1, 12);
	//BuildingSlot *BuildingSlot13 = new BuildingSlot(1, 13);
	//BuildingSlot *BuildingSlot21 = new BuildingSlot(2, 21);
	//BuildingSlot *BuildingSlot22 = new BuildingSlot(2, 22);
	//BuildingSlot *BuildingSlot23 = new BuildingSlot(2, 23);
	//BuildingSlot *BuildingSlot31 = new BuildingSlot(3, 31);
	//BuildingSlot *BuildingSlot32 = new BuildingSlot(3, 32);
	//BuildingSlot *BuildingSlot33 = new BuildingSlot(3, 33);

	//BuildingSlot11->addAdjacentBuildingSlots(BuildingSlot12);
	//BuildingSlot11->addAdjacentBuildingSlots(BuildingSlot21);

	//BuildingSlot12->addAdjacentBuildingSlots(BuildingSlot11);
	//BuildingSlot12->addAdjacentBuildingSlots(BuildingSlot22);
	//BuildingSlot12->addAdjacentBuildingSlots(BuildingSlot13);

	//BuildingSlot13->addAdjacentBuildingSlots(BuildingSlot12);
	//BuildingSlot13->addAdjacentBuildingSlots(BuildingSlot23);

	//BuildingSlot21->addAdjacentBuildingSlots(BuildingSlot11);
	//BuildingSlot21->addAdjacentBuildingSlots(BuildingSlot31);
	//BuildingSlot21->addAdjacentBuildingSlots(BuildingSlot22);

	//BuildingSlot22->addAdjacentBuildingSlots(BuildingSlot21);
	//BuildingSlot22->addAdjacentBuildingSlots(BuildingSlot23);
	//BuildingSlot22->addAdjacentBuildingSlots(BuildingSlot12);
	//BuildingSlot22->addAdjacentBuildingSlots(BuildingSlot32);

	//BuildingSlot23->addAdjacentBuildingSlots(BuildingSlot22);
	//BuildingSlot23->addAdjacentBuildingSlots(BuildingSlot13);
	//BuildingSlot23->addAdjacentBuildingSlots(BuildingSlot33);

	//BuildingSlot31->addAdjacentBuildingSlots(BuildingSlot21);
	//BuildingSlot31->addAdjacentBuildingSlots(BuildingSlot32);

	//BuildingSlot32->addAdjacentBuildingSlots(BuildingSlot31);
	//BuildingSlot32->addAdjacentBuildingSlots(BuildingSlot22);
	//BuildingSlot32->addAdjacentBuildingSlots(BuildingSlot33);

	//BuildingSlot33->addAdjacentBuildingSlots(BuildingSlot23);
	//BuildingSlot33->addAdjacentBuildingSlots(BuildingSlot32);



	//
	//map_->addBuildingSlot(BuildingSlot11);
	//map_->addBuildingSlot(BuildingSlot12);
	//map_->addBuildingSlot(BuildingSlot13);
	//map_->addBuildingSlot(BuildingSlot21);
	//map_->addBuildingSlot(BuildingSlot22);
	//map_->addBuildingSlot(BuildingSlot23);
	//map_->addBuildingSlot(BuildingSlot31);
	//map_->addBuildingSlot(BuildingSlot32);
	//map_->addBuildingSlot(BuildingSlot33);
	//

	//map_->printVGMap();
	//int a = map_->isConnectedGraph();
	//if(a==0)
	//cout << "\nFalse:The map is not a connected graph\n";
	//else
	//cout << "\nTrue:The map is a connected graph\n";

	//
	//system("pause");

//######################################################-GBMap Loader-################################################
//GBMapLoader *GB = new GBMapLoader();
//GB->readfromfile("GBMap4Players.txt");
//GB->getMap()->print();
//system("pause");

 //######################################################-VGMap Loader-###################################################

//VGMapLoader *VG = new VGMapLoader();
//VG->readfromfile("VillageBoard2.txt");
//VG->getVGMap()->printVGMap();
//system("pause");


//###################################################-Resources-################################################################
//Tile* y = new Tile(Tile::sheep, Tile::stone, Tile::stone, Tile::sheep);
//Building* b = new Building(6, Building::Type::sheep);
//
//y->toString();
//
//b->toString();
//
//BuildingDeck *bd = new BuildingDeck();
//Building drawFromBd = bd->draw();
//
//drawFromBd.toString();
//
//Building b2 = bd->draw();
//b2.toString();
//
//cout << "\nturn it......." << endl;
//b2.turn();
//b2.toString();
//
//Building b3 = bd->draw();
//b3.toString();
//
//TileDeck* td = new TileDeck();
//Tile* drawFromTileDeck = td->draw();
//drawFromTileDeck->setNumOfResources();
//drawFromTileDeck->toString();
//
//Tile* sd = td->draw();
//sd->setNumOfResources();
//sd->toString();
//
//system("pause");

//####################################################-Player-########################################################################## 
//VGMap *VG = new VGMap();
//GBMap *map_ = new GBMap();
//TileDeck *td = new TileDeck();
//BuildingDeck *bd = new BuildingDeck();
//BuildingSlot *BuildingSlot11 = new BuildingSlot(1, 11);
//BuildingSlot *BuildingSlot12 = new BuildingSlot(1, 12);
//BuildingSlot *BuildingSlot13 = new BuildingSlot(1, 13);
//BuildingSlot *BuildingSlot21 = new BuildingSlot(2, 21);
//BuildingSlot *BuildingSlot22 = new BuildingSlot(2, 22);
//BuildingSlot *BuildingSlot23 = new BuildingSlot(2, 23);
//BuildingSlot *BuildingSlot31 = new BuildingSlot(3, 31);
//BuildingSlot *BuildingSlot32 = new BuildingSlot(3, 32);
//BuildingSlot *BuildingSlot33 = new BuildingSlot(3, 33);
//VG->addBuildingSlot(BuildingSlot11);
//
//Player *p1 = new Player("Jacques", 1,VG);
//p1->DrawBuilding(bd);
//p1->DrawHarvestTile(td);
//p1->DrawHarvestTile(td);
//p1->DrawHarvestTile(td);
//
//p1->showTiles();
//p1->PlaceHarvestTile(0, 11, map_);
//p1->showTiles();
//
//TileSlot *TileSlot11 = new TileSlot(11);
//TileSlot *TileSlot12 = new TileSlot(12);
//TileSlot *TileSlot13 = new TileSlot(13);
//
//TileSlot *TileSlot21 = new TileSlot(21);
//TileSlot *TileSlot22 = new TileSlot(22);
//TileSlot *TileSlot23 = new TileSlot(23);
//
//TileSlot *TileSlot31 = new TileSlot(31);
//TileSlot *TileSlot32 = new TileSlot(32);
//TileSlot *TileSlot33 = new TileSlot(33);
//
//
//map_->addTileSlot(TileSlot11);
//map_->addTileSlot(TileSlot12);
//map_->addTileSlot(TileSlot13);
//
//map_->addTileSlot(TileSlot21);
//map_->addTileSlot(TileSlot22);
//map_->addTileSlot(TileSlot23);
//
//map_->addTileSlot(TileSlot31);
//map_->addTileSlot(TileSlot32);
//map_->addTileSlot(TileSlot33);
//
//
//map_->print();
//p1->DrawBuilding(bd);
//p1->DrawBuilding(bd);
//
//p1->showBuildings();
//p1->BuildingVillage(0,11);
//p1->showBuildings();
//
//p1->showTiles();
//
//
//system("pause");









//###################################################-VillageScore-#####################################################################

VGMapLoader *VG = new VGMapLoader();
VG->readfromfile("VillageBoard2.txt");
Building* b = new Building(1, Building::Type::sheep);
Building* b1 = new Building(1, Building::Type::sheep);
Building* b2 = new Building(1, Building::Type::sheep);
Building* b3 = new Building(1, Building::Type::sheep);
Building* b4 = new Building(1, Building::Type::sheep);
Building* b5 = new Building(1, Building::Type::sheep);

VG->getVGMap()->getBuildingSlots()[0]->setBuilding(*b);
VG->getVGMap()->getBuildingSlots()[6]->setBuilding(*b1);
VG->getVGMap()->getBuildingSlots()[12]->setBuilding(*b2);
VG->getVGMap()->getBuildingSlots()[18]->setBuilding(*b3);
VG->getVGMap()->getBuildingSlots()[24]->setBuilding(*b4);
VG->getVGMap()->getBuildingSlots()[5]->setBuilding(*b5);

VillageScore *VS = new VillageScore(VG->getVGMap());
VS->evaluate();
cout << VS->getScore()<<"\n";

system("pause");



//###################################################-ResourcesGather-################################################################
//GBMap* map_ = new GBMap();
//Tile* t1 = new Tile(Tile::Types::stone, Tile::Types::wheet, Tile::Types::stone, Tile::Types::wheet);
//Tile* t2 = new Tile(Tile::Types::wheet, Tile::Types::wheet, Tile::Types::sheep, Tile::Types::sheep);
//Tile* t3 = new Tile(Tile::Types::stone, Tile::Types::wheet, Tile::Types::sheep, Tile::Types::sheep);
//TileSlot *TileSlot11 = new TileSlot(t1,11);
//TileSlot *TileSlot12 = new TileSlot(t2,12);
//TileSlot *TileSlot13 = new TileSlot(t3,13);
//
//TileSlot11->addAdjacentTileSlot(TileSlot12);
//TileSlot12->addAdjacentTileSlot(TileSlot13);
//map_->addTileSlot(TileSlot11);
//map_->addTileSlot(TileSlot12);
//map_->addTileSlot(TileSlot13);
//ResourcesGather* RG = new ResourcesGather();
//bool a[] = { true,true,true,true };
//RG->allGather2(*TileSlot11, a);
//cout << RG->getResources()[0];
//cout << RG->getResources()[1];
//cout << RG->getResources()[2];
//cout << RG->getResources()[3];
//system("pause");
//#########################################################################################################################################

	//string P1 = "p1";
	//int order1 = 1;
	//Player *p1 = new Player(string("p1"), int(1));
	//TileDeck *td = new TileDeck();
	//BuildingDeck *bd = new BuildingDeck();
	////p1->DrawHarvestTile(td);
	////p1->DrawHarvestTile(td);
	////p1->DrawHarvestTile(td);

	//// BuildingDeck * bd = new BuildingDeck();
	////p1->DrawBuilding(bd);

	//TileSlot *TileSlot11 = new TileSlot(11);
	//TileSlot *TileSlot12 = new TileSlot(12);
	//TileSlot *TileSlot13 = new TileSlot(13);

	//TileSlot *TileSlot21 = new TileSlot(21);
	//TileSlot *TileSlot22 = new TileSlot(22);
	//TileSlot *TileSlot23 = new TileSlot(23);

	//TileSlot *TileSlot31 = new TileSlot(31);
	//TileSlot *TileSlot32 = new TileSlot(32);
	//TileSlot *TileSlot33 = new TileSlot(33);


	//

	//map_->addTileSlot(TileSlot11);
	//map_->addTileSlot(TileSlot12);
	//map_->addTileSlot(TileSlot13);

	//map_->addTileSlot(TileSlot21);
	//map_->addTileSlot(TileSlot22);
	//map_->addTileSlot(TileSlot23);

	//map_->addTileSlot(TileSlot31);
	//map_->addTileSlot(TileSlot32);
	//map_->addTileSlot(TileSlot33);

	////p1->showTiles();
	////p1->PlaceHarvestTile(0,11,map_);
	////p1->showTiles();
	//// map_->print();
	////p1->DrawBuilding(bd);
	////p1->DrawBuilding(bd);
	////  p1->showBuildings();
	////p1->BuildingVillage(0,11);
	//// p1->showBuildings();

	////p1->showTiles();



	//TileDeck *TileDeck1 = new TileDeck();
	//Tile* t1 = new Tile(Tile::Types::stone, Tile::Types::wheet, Tile::Types::stone, Tile::Types::wheet);
	//Tile* t2 = new Tile(Tile::Types::wheet, Tile::Types::wheet, Tile::Types::sheep, Tile::Types::sheep);
	//Tile* t3 = new Tile(Tile::Types::stone, Tile::Types::wheet, Tile::Types::sheep, Tile::Types::sheep);
	//TileSlot* ts1 = new TileSlot(t1, 11);
	//TileSlot* ts2 = new TileSlot(t2, 12);
	//TileSlot* ts3 = new TileSlot(t3, 13);
	//ts1->addAdjacentTileSlot(ts2);
	//ts2->addAdjacentTileSlot(ts1);
	//ts2->addAdjacentTileSlot(ts3);

	//// cout << ts2->getTileSlotId();

	//bool a[] = { true,true,true,true };
	//bool* b = a;
	//ResourcesGather * h = new ResourcesGather();
	////cout<< "\nBefore\n";
	////cout << h->getResources()[0];
	////cout << h->getResources()[1];
	////cout << h->getResources()[2];
	////cout << h->getResources()[3];
	//h->allGather(*ts1, a);
	//cout<<"\nAfter\n";
	//cout << h->getResources()[0];
	//cout << h->getResources()[1];
	// cout << h->getResources()[2];
	//cout << h->getResources()[3];



	////cout<<b[0]<<b[1]<<b[2]<<b[3]<<"\n";
	////t1->haveConnection(b);
	//// cout<<b[0]<<b[1]<<b[2]<<b[3];
	//// Tile* T1= TileDeck1->draw();
	//// int  a=T1->getTypeArray();
	//// cout << T1->getTypeArray()[0];
	//// cout << T1->getTypeArray()[1];
	//// cout << T1->getTypeArray()[2];
	////cout << T1->getTypeArray()[3];
	//// T1->toString();


	////TileSlot33->getTile().toString();


	//TileSlot11->addAdjacentTileSlot(TileSlot12);
	//TileSlot11->addAdjacentTileSlot(TileSlot21);

	//TileSlot12->addAdjacentTileSlot(TileSlot11);
	//TileSlot12->addAdjacentTileSlot(TileSlot23);
	//TileSlot12->addAdjacentTileSlot(TileSlot32);

	//TileSlot13->addAdjacentTileSlot(TileSlot12);
	//TileSlot13->addAdjacentTileSlot(TileSlot23);




	//map_->addTileSlot(TileSlot11);
	//map_->addTileSlot(TileSlot12);
	//map_->addTileSlot(TileSlot13);

	//map_->addTileSlot(TileSlot21);
	//map_->addTileSlot(TileSlot22);
	//map_->addTileSlot(TileSlot23);

	//map_->addTileSlot(TileSlot31);
	//map_->addTileSlot(TileSlot32);
	//map_->addTileSlot(TileSlot33);

	//// map_->print();
	////map_->getTileSlots().at(map_->getTileSlots().size()-1)->getTile()->toString();


	return 0;

}
