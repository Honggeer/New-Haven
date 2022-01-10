//
// Created by Meiyi Luan on 2020-02-22.
//
#include "ResourcesGather.h"
ResourcesGather::ResourcesGather() {
	resources = new int[4]{ 0,0,0,0 };
	counted = new vector<Tile::Types*>();
	alreadycount = new vector<Tile :: Types*>();
}


ResourcesGather:: ~ResourcesGather() {
	delete[] resources;
	delete alreadycount;
}
int* ResourcesGather::getResources() {
	return resources;
}
void ResourcesGather::setToZero() {
	for (int i = 0; i < 4; i++) {
		resources[i] = 0;
	}
	alreadycount->clear();
}

void ResourcesGather::allGather2(TileSlot *ts, bool connection[]) {

	ts->getTile()->haveConnection(connection);


	add(connection, ts->getTile());
	

	int isIn = 0;
	bool b = true;

	for (int i = 0; i<ts->getAdjacentTileSlots().size(); i++) {
	/*	isIn = 0;
		for (int j = 0; j<alreadycount->size(); j++) {
			if (alreadycount->at(j) == ts->getAdjacentTileSlots()[i]->getTileSlotId()) {
				isIn = 1;
				break;
			}
		}
		if (isIn == 1)
			continue;*/

		if (ts->getAdjacentTileSlots()[i]->getTileSlotId() == ts->getTileSlotId() + 10) {
			bool connect[] = { false,false,false,false };
			if (connection[1]	&&	ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[0] == ts->getTile()->getTypeArray()[1]	&&	!incount((&ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[0])))
				connect[0] = b;

			if (connection[3]	&&	ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[2] == ts->getTile()->getTypeArray()[3]	&&	!incount((&ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[2])))
				connect[2] = b;
			
			if (connect[0] || connect[2])
				allGather2(ts->getAdjacentTileSlots()[i], connect);
		}


		if (ts->getAdjacentTileSlots()[i]->getTileSlotId() == ts->getTileSlotId() - 10) {
			bool connect[] = { false,false,false,false };
			if (connection[0]	&&	ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[1] == ts->getTile()->getTypeArray()[0] &&	!incount((&ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[1])))
				connect[1] = b;

			if (connection[2]	&&	ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[3] == ts->getTile()->getTypeArray()[2] &&	!incount((&ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[3])))
				connect[3] = b;

			if (connect[1] || connect[3])
				allGather2(ts->getAdjacentTileSlots()[i], connect);
		}


		if (ts->getAdjacentTileSlots()[i]->getTileSlotId() == ts->getTileSlotId() + 1) {
			bool connect[] = { false,false,false,false };
			if (connection[0]	&&	ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[2] == ts->getTile()->getTypeArray()[0]	&&	!incount((&ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[2])))
				connect[2] = b;

			if (connection[1]	&&	ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[3] == ts->getTile()->getTypeArray()[1] &&	!incount((&ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[3])))
				connect[3] = b;

			if (connect[2] || connect[3])
				allGather2(ts->getAdjacentTileSlots()[i], connect);
		}

		if (ts->getAdjacentTileSlots()[i]->getTileSlotId() == ts->getTileSlotId() - 1 && (connection[0] || connection[2])) {
			bool connect[] = { false,false,false,false };
			if (connection[2] && ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[0] == ts->getTile()->getTypeArray()[2] && !incount((&ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[0])))
				connect[0] = b;

			if (connection[3] && ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[1] == ts->getTile()->getTypeArray()[3] && !incount((&ts->getAdjacentTileSlots()[i]->getTile()->getTypeArray()[1])))
				connect[1] = b;

			if (connect[0] || connect[1])
				allGather2(ts->getAdjacentTileSlots()[i], connect);
			for (int j = 0; j < alreadycount->size(); j++) {
				
			}
		}




	}



}

void ResourcesGather::add(bool a[], Tile *t) {

	int temp;

	for (int i = 0; i<4; i++) {
		if (a[i]) {
			temp = t->getTypeArray()[i];
			
			alreadycount->push_back((&(t->getTypeArray()[i])));
			resources[temp]++;



		}
	}
}



bool ResourcesGather::incount(Tile:: Types* ty) {
	for (int i = 0; i < alreadycount->size(); i++) {
		if (ty == alreadycount->at(i)) {
			
			return true;
		}
	}
	return false;
}

