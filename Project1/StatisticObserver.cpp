//part 2
#include "StatisticObserver.h"


StatisticsObserver::StatisticsObserver(vector<Player*>*players_)
{
	Players = players_;
	for (int i = 0; i < players_->size(); i++) {
		Players->at(i)->attach(this);
	}
}

StatisticsObserver::~StatisticsObserver()
{
	for (int i = 0; i < Players->size(); i++) {
		Players->at(i)->detach(this);
	}
	delete Players;
}
void StatisticsObserver::update()
{
	if (Players->at(0)->getCurrentPhrase() != 4) {
		cout << "\n************************************************Statistic Observer************************************************" << endl;
		for (int i = 0; i < Players->size(); i++) {
			cout << "player #" << i << " " << Players->at(i)->getName() << " Ressources: ";
			for (int j = 0; j < 4; j++)
				cout << Players->at(i)->getRMS()[j] << "/";
			cout << "Village Score: " << Players->at(i)->calculateScore() << endl;
			cout << " Number of Buildings: " << *(Players->at(i)->getNumberOfBuilings()) << " :";
			for (int j = 0; j < Players->at(i)->getVgmap()->getBuildingSlots().size(); j++) {

				if (Players->at(i)->getVgmap()->getBuildingSlots().at(j)->getBuilding()->getCost() != 0) {
					cout << enumToString(Players->at(i)->getVgmap()->getBuildingSlots().at(j)->getBuilding()->getType()) << " building at location: ";
					cout << Players->at(i)->getVgmap()->getBuildingSlots().at(j)->getBuildingSlot_id() << ", ";
				}

			}
			cout << "\n";

		}
		cout << "*****************************************************************************************************************" << endl;
	}
	if (Players->at(0)->getCurrentPhrase()== 4) {
		cout << "\n***********************************************celebratory message*********************************************" << endl;
		for (int i = 0; i < Players->size(); i++) {
			cout << "player #" << i << " " << Players->at(i)->getName() << " Village Score: "<< Players->at(i)->calculateScore() << endl;
		}
		bool winner[] = { false,false,false,false };
	int winners = 0;
	int highest = 0;
	int lowest = 0;
	int sameAsHighers;
	// find the higest score
	for (int i = 0; i < Players->size(); i++) {
		if (Players->at(i)->calculateScore() > highest)
			highest = Players->at(i)->calculateScore();
	}
	//check who have and how many players have the highest score;
	for (int i = 0; i < Players->size(); i++) {
		if (Players->at(i)->getScore() == highest) {
			winner[i] = true;
			winners++;
		}
	}
	//if there is a tie
	if (winners > 1) {
		int lowest = 100;
		// find the lowest number of leftover building slot
		for (int i = 0; i < Players->size(); i++) {
			if (winner[i] == true) {
				if (Players->at(i)->leftPlaceVG() < lowest) {
					lowest = Players->at(i)->leftPlaceVG();
				}
			}
		}
		// check who and how many player have the empty space the least leftover space
		for (int i = 0; i < Players->size(); i++) {
			if (winner[i] == true) {
				if (Players->at(i)->leftPlaceVG() > lowest) {
					winner[i] = false;
					winners--;
				}
			}
		}
		//if its still a tie
		if (winners > 1) {
			lowest = 100;
			//find the lowest number of building tiles in hand
			for (int i = 0; i < Players->size(); i++) {
				if (winner[i] == true) {
					if (Players->at(i)->leftBuildings() < lowest) {
						lowest = Players->at(i)->leftBuildings();
					}
				}
			}
			// check who have it
			for (int i = 0; i < Players->size(); i++) {
				if (winner[i] == true) {
					if (Players->at(i)->leftBuildings() > lowest) {
						winner[i] = false;
						winners--;
					}
				}
			}



		}

	}

	cout << "winner is ";
	for (int i = 0; i < Players->size(); i++) {
		if (winner[i] == true) {
			cout << Players->at(i)->getName();
		}
	}
		
	}
}