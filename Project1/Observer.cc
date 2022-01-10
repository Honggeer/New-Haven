#include "GameObserver.h"
#include "Observer.h"
#include <iostream>
using namespace std;

Observer::Observer()
{

}
Observer::~Observer()
{

}


//part 1
TurnObserver::TurnObserver(Player *subject_)
{
	subject = subject_;
	subject->attach(this);

}

TurnObserver::~TurnObserver()
{
	subject->detach(this);
}

void TurnObserver::update()
{
	string name = subject->getName();
	int phase = subject->getCurrentPhrase();
	

	switch (phase)
	{
		//Phase 1: 
		//Place a Heaven Tile in GBMAP
		//Indicate the increasement of Resource Marker
	case 1:
		cout << "The active player " << name << ": plays a Harvest Tile by placing it on the Game Board" << endl;
		cout << "********************** Increasement of Resource Marker **********************" << endl;
		subject->showResourceMarkers();
		break;
		
		//Phase 2:
		//Construct building in VGMAP
		//Update building counter

	case 2:
		cout << "The active player " << name << ": constructs a building by placing it on the Village Board" << endl;
		cout << " ********************** Left space in Village **********************" << endl;
		cout <<"**********************"<< subject->leftPlaceVG() << "**********************" << endl;
		break;

		//Phase 3:
		//In every buliding played
		//Decrease Resources by the building

	case 3:
		cout << "The active player " << name << ": constructs a building by placing it on the Village Board" << endl;
		cout << " ********************** Resouces Remain **********************" << endl;
		subject->showResourceMarkers();
		break;
	}

}

//part 2
StatisticsObserver::StatisticsObserver()
{

}

StatisticsObserver::~StatisticsObserver()
{

}
void StatisticsObserver::update()
{

}
