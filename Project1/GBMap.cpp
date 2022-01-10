#include "GBMap.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//TileSlot section
//default
TileSlot::TileSlot()
{
	adjTiltSlots = new vector<TileSlot *>();
	Tile_p = new Tile();
	TileSlot_id = new int();

}
//parameter
TileSlot::TileSlot(Tile* Tile_, int TileSlot_id_)
{
	adjTiltSlots = new vector<TileSlot *>();
	Tile_p = Tile_;
	TileSlot_id = new int(TileSlot_id_);

}

TileSlot::TileSlot(int TileSlot_id_)
{
	adjTiltSlots = new vector<TileSlot *>();
	Tile_p = new Tile();
	TileSlot_id = new int(TileSlot_id_);

}

//parameter
TileSlot::TileSlot(std::vector<TileSlot *> adjTilesSlots_, Tile Tile_, int TileSlot_id_)
{
	adjTiltSlots = new std::vector<TileSlot* >(adjTilesSlots_);
	Tile_p = new Tile(Tile_);
	TileSlot_id = new int(TileSlot_id_);

}

//copy constructor
//TileSlot:: TileSlot(constant )


//destructor
TileSlot::~TileSlot()
{
	delete adjTiltSlots;
	delete TileSlot_id;
	delete Tile_p;

}

Tile* TileSlot::getTile()
{
	return Tile_p;
}

void TileSlot::setTile(Tile Tile_)
{
	//Tile_p = new Tile(Tile_.getTypeArray()[0],Tile_.getTypeArray()[1],Tile_.getTypeArray()[2],Tile_.getTypeArray()[3]);
	Tile_p->setUpLeft(Tile_.getUpLeft());
	Tile_p->setUpRight(Tile_.getUpRight());
	Tile_p->setDownLeft(Tile_.getDownLeft());
	Tile_p->setDownRight(Tile_.getDownRight());
}


bool TileSlot::isEmpty()
{

	if (getTile()->getUpLeft() == 4 && getTile()->getUpRight() == 4 && getTile()->getDownLeft() == 4 && getTile()->getDownRight() == 4)   //is empty
	{
		return true;
	}
	else  //is not empty
	{
		return false;
	}

	if (this->getTile() == nullptr)
		return true;

}


//adjacent TileSlot accessor method
std::vector<TileSlot *>& TileSlot::getAdjacentTileSlots()
{
	return *adjTiltSlots;
}

//adjacent TileSlot mutator method
void TileSlot::setAdjacentTileSlots(std::vector<TileSlot *> adjTileSlots_)
{
	adjTiltSlots = &adjTileSlots_;
}

//add TileSlot to adjacent TileSlot vector method
void TileSlot::addAdjacentTileSlot(TileSlot *TileSlots)
{
	adjTiltSlots->push_back(TileSlots);
}

//
int& TileSlot::getTileSlotId()
{
	return *TileSlot_id;
}


//check if TileSlot is adjacent
bool TileSlot::isAdjacent(TileSlot *TileSlots)
{
	for (int i = 0; i < adjTiltSlots->size(); i++) {
		if (adjTiltSlots->at(i) == TileSlots)
		{
			return true;
		}
	}
	return false;
}

/**GBMap IMPLEMENTATION **/

GBMap::GBMap()
{
	TileSlots = new vector<TileSlot *>();
}

GBMap::GBMap(std::vector<TileSlot *> *TileSlots_)
{
	TileSlots = TileSlots_;

}

GBMap::~GBMap()
{
	for (int i = 0; i<TileSlots->size(); i++) {
		delete TileSlots->at(i);
		TileSlots->at(i) = nullptr;
	}

	delete  TileSlots;
	TileSlots = nullptr;
}

// Accessor method
std::vector<TileSlot *>& GBMap::getTileSlots()
{
	return *TileSlots;
}

// Mutator method
void GBMap::setTileSlots(std::vector<TileSlot *> TileSlots_)
{
	TileSlots = &TileSlots_;

}

// add TileSlot method
void GBMap::addTileSlot(TileSlot *TileSlots_)
{
	TileSlots->push_back(TileSlots_);

}


// check if a map is a connected graph
bool GBMap::isConnectedGraph()
{
	for (int i = 0; i < TileSlots->size(); i++) {
		for (int j = 0; j < TileSlots->at(i)->getAdjacentTileSlots().size(); j++) {
			if (!(TileSlots->at(i)->getAdjacentTileSlots().at(j)->isAdjacent(TileSlots->at(i)))) {
				//                std::cout << "TileSlots : " << TileSlots->at(i)->getAdjacentTileSlots().at(j)->getName() << " and " << TileSlots->at(i)->getName() << " are only connected one way." << std::endl;
				return false;
			}
		}
	}

	std::vector<TileSlot *> temp;
	for (int i = 0; i < TileSlots->size(); i++) {
		temp.insert(temp.end(), TileSlots->at(i)->getAdjacentTileSlots().begin(), TileSlots->at(i)->getAdjacentTileSlots().end());
	}
	std::sort(temp.begin(), temp.end());
	temp.erase(std::unique(temp.begin(), temp.end()), temp.end());

	for (int i = 0; i < TileSlots->size(); i++) {
		if (std::find(temp.begin(), temp.end(), TileSlots->at(i)) == temp.end()) {
			//            std::cout << "BuildingSlot " << TileSlots->at(i)->getName() << " is not connected to the rest of the graph." << std::endl;
			return false;
		}
	}
	return true;
}

void GBMap::print()
{
	int id;
	Tile* temp;

	for (int i = 0; i <TileSlots->size(); i++)
	{
		id = TileSlots->at(i)->getTileSlotId();
		temp = (TileSlots->at(i)->getTile());

		cout << "\nID: " << id << endl;
		/* if there is tile inside, print tile information*/
		if (!TileSlots->at(i)->isEmpty())
		{
			
			temp->toString();

		}
		/*if there is no tile inside, print empty */
		else
		{
			cout << "Empty Slot." << endl;
		}
	}
}


TileSlot* GBMap::SearchById(int n)
{
	for (int i = 0; i < getTileSlots().size(); i++)
	{
		if (TileSlots->at(i)->getTileSlotId() == n && n!=0) {
			return TileSlots->at(i);
		}
	}
	return new TileSlot();

}

bool GBMap::onePlaceLeft() {
	int empty = 0;
	for (int i = 0; i < TileSlots->size();i++) {
		if (TileSlots->at(i)->isEmpty())
			empty++;
	}
	if (empty == 1)
		return true;
	return false;
}

