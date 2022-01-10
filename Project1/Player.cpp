#include "Player.h"
#include <iostream>
#include <string>
#include <iterator>

using namespace std;
//default constructor
GBMap* Player::GB;
Player::Player() {
	name = new string("");
	vgm = new VGMap();
	rms = new int[4]{ 0,0,0,0 };
	rg = new ResourcesGather();
	order = new int();
	tiles = new vector<Tile*>();
	buildings = new vector<Building*>();
	firstPlay = new bool[4]{ true, true, true, true };
	vs = new VillageScore();
	currentPhase = new int(0);
	numberOfBuildings = new int(0);
	
}

//parametrized constructor
Player::Player(string n, int order, VGMap* VG) {
	name =new string(n);
	tiles = new vector<Tile*>();
	buildings = new vector<Building*>();
	vgm = VG;
	rms = new int[4]{ 0,0,0,0 };
	rg = new ResourcesGather();
	this->order = &order;
	firstPlay = new bool[4]{ true, true, true, true };
	vs = new VillageScore(VG);
	currentPhase = new int(0);
	numberOfBuildings = new int(0);
	
}

Player::~Player() {
	delete name;
	name = nullptr;
	delete vgm;
	vgm = nullptr;
	delete tiles;
	tiles = nullptr;
	delete buildings;
	buildings = nullptr;
	delete rg;
	rg = nullptr;
	delete order;
	order = nullptr;
	delete [] rms;
	rms = nullptr;
	delete [] firstPlay;
	firstPlay = nullptr;
	delete vs;
	vs = nullptr;
	delete currentPhase;
	
}

string Player::getName() {
	return *name;
}

int Player::getOrder() {
	return *order;
}
 
int* Player::getRMS() {
	return rms;
}

int* Player::getNumberOfBuilings()
{
	return numberOfBuildings;
}

VGMap* Player::getVgmap()
{
	return vgm;
}

GBMap* Player::getGBMap()
{
	return GB;// TODO: insert return statement here
}


void Player::setGBMap(GBMap* gb)
{
	GB = gb;
}
bool Player::onePlaceLeft()
{
	if (!Player::getGBMap()->onePlaceLeft())
		return false;
	currentPhase = new int(4);
	notify();
	return true;
}
void Player::addBuilding(Building* B)
{
	buildings->push_back(B);
}
string Player::availableBS(int cost)
{
	string spots = "( ";
	for (int i = 1; i < 6; i++) {
		if (vgm->getBuildingSlotByID(i * 10 + cost)->getBuilding()->getCost() == 0)
			spots +=std::to_string(i * 10 + cost) + " ";

	};
	return spots+")";
}
Building* Player::getBuilding(int index)
{
	return buildings->at(index);
	
}
void Player::setRMS(int* r) {
	for (int i = 0; i < 4; i++)
		*(rms+i) = r[i];

}

//print the tile that player has
void Player::showTiles() {
	
	cout << "Those are your harvest tiles: " <<"\n"<< endl;
	for (int i = 0; i < tiles->size(); i++) {
		cout << "NO." << i << "\n";
		tiles->at(i)->toString();
		cout << "\n";
	}
}

//print the building cards that player has
void Player::showBuildings() {

	cout << "Those are your building tiles: " <<"\n"<< endl;
	for (int i = 0; i < buildings->size(); i++) {
		cout << "NO." << i ;
		buildings->at(i)->toString();
		cout << "\n";
	}
}

//print the location of the resource marker
void Player::showResourceMarkers() {
	cout << "********************** Sheep: " << rms[0] << " Wheat: " << rms[1] << " Stone: " << rms[2] << " Timber: " << rms[3]<<" **********************"<<endl;
}




//place a tile card on the game board. if the node already have tile return false
bool Player::PlaceHarvestTile(int index, int id, GBMap *map) {
	//change phase counter to 1
	
	


	if (index >= tiles->size()) {
		cout << tiles->size();
		cout << "Out of bound"<<endl;
		return false;
	}
	if (map->SearchById(id)->getTileSlotId() == 0) {
		cout << "\nYou cannot harvest here, this location is out of the Board Game." << endl;
		return false;
	}
	if (!map->SearchById(id)->isEmpty()) {
		cout << "You cannot harvest here"<<endl;
		return false;
	}
	string s;
	int times;
	while (true) {
		cout << "\nDo you want to change the direction of tile? (Enter yes or no)"<<endl;
		try {
			cin >> s;
		}
		catch (exception e) {
			cerr << e.what();
		}
		if (s.compare("no") == 0)
			break;
		else {
			if (s.compare("yes") == 0) {
				cout << "How many time you want to rotate it clockwise?"<<endl;
				try {
					cin >> times;
				}
				catch (exception e) {
					cerr << e.what();
				}
				for (int i = 0; i < times; i++) {
					tiles->at(index)->changeDirection();

				}
				break;
			}
			else {
				cout << "You didn't enter a valid answer."<<endl;
				continue;
			}
		}
	


	}
	tiles->at(index)->toString();
	tiles->at(index);
	//map->SearchById(id)->setTile(Tile());

	map->SearchById(id)->setTile(*(tiles->at(index)));
	map->print();
	//map.SearchById(id)->getTile()->toString();

	tiles->erase(tiles->begin() + index);
	return true;

}


//draw building
void Player::DrawBuilding(BuildingDeck *bd) {

	buildings->push_back(&bd->draw());
	buildings->back()->toString();
}

//draw tile
void Player::DrawHarvestTile(TileDeck * td) {
	tiles->push_back(td->draw());
	tiles->back()->toString();

}

//build building
bool Player::BuildingVillage(int index, int location) {

	//change phase counter to 2
	
	

	if (index >= buildings->size()) {
		cout << "\nOut of bound, you don't have a card at this index.";
		return false;
	}
	if (vgm->searchByID(location) == nullptr) {
	cout<< "\nYou cannot build here, this location is out of the Village Board Game."<<endl;
	return false;
	}

	if (vgm->searchByID(location)->getBuilding()->getCost() != 0) {
		cout << "\nYou cannot build there, there is already been built something" << endl;
		return false;
	}
	int cost = buildings->at(index)->getCost();
	string forFliped;
	if (location % 10 != buildings->at(index)->getCost()) {

		cout << "Do your want to flip your builidng tile? please enter yes or no. " << endl;
		cin >> forFliped;
		while (forFliped != "yes" && forFliped != "no") {
			cout << "you didn't enter yes or no please enter again " << endl;
			cin >> forFliped;
		}
		if (forFliped == "yes") {
			
			buildings->at(index)->setCost(location % 10);
		}
		else{
			cout << "\nThe costs do not match" << endl;
			return false;
		}
		
	}
	//after first time play a type
	if (!firstPlay[buildings->at(index)->getType()]) {
		
		if (!checkAdj(index, location)) {
			cout << "\nYou need to place near the same type" << endl;
			buildings->at(index)->setCost(cost);
			return false;
		}
	}
	//check
	if (buildings->at(index)->getCost() > rms[ buildings->at(index)->getType() ]) {
	cout << "\nYou don't have enough resources" << endl;
	buildings->at(index)->setCost(cost);
	return false;
    }

	if(firstPlay[buildings->at(index)->getType()])
		firstPlay[buildings->at(index)->getType()] = false;

	decreaseResource(index);

	vgm->searchByID(location)->setBuilding(*buildings->at(index));
	buildings->erase(buildings->begin() + index);
	(*numberOfBuildings)++;
	delete currentPhase;
	currentPhase = new int(2);
	notify();
	return true;
}

void Player::decreaseResource(int index)
{
	//change phase counter to 3
	delete currentPhase;
	currentPhase = new int(3);
	
	rms[buildings->at(index)->getType()] -= (buildings->at(index)->getCost());
	notify();
}

// check if the building tile is the same type as tiles on adjacent buidling slot
bool Player::checkAdj(int index, int id) {
	/*BuildingSlot* temp;
	temp= vgm->searchByID(id);*/
	for (int i = 0; i < vgm->searchByID(id)->getAdjacentBuildingSlots().size(); i++) {
		if (vgm->searchByID(id)->getAdjacentBuildingSlots().at(i)->getBuilding()->getCost() == 0)
			continue;
		if (vgm->searchByID(id)->getAdjacentBuildingSlots().
			at(i)->getBuilding()->getType() == buildings->at(index)->getType())
			return true;
	}
	return false;
}

//calcaulate resources
void Player::CalculateResources(TileSlot* ts) {
	delete currentPhase;
	currentPhase = new int(1);

	bool alltrue[]  = { true,true,true,true };
	bool* allTrue = alltrue;
	rg->allGather2(ts, allTrue);
	for (int i = 0; i < 4; i++) {
		rms[i] = rg->getResources()[i];
	}
	rg->setToZero();
	notify();
}
int Player::calculateScore()
{	
	vs->evaluate();
	return vs->getScore();
}
int Player::getScore()
{
	return vs->getScore();
}
void Player::setRgToZero() {
	rg->setToZero();
}

void Player::printVGMap() {
	vgm->printVGMap();
}

int Player::leftPlaceVG()
{
	int leftspace = 0;
	for (int i = 0; i < vgm->getBuildingSlots().size(); i++) {
		if (vgm->getBuildingSlots().at(i)->getBuilding()->getCost() == 0)
			leftspace++;
	}
	return leftspace;
}

int Player::leftBuildings()
{
	return buildings->size();
}

bool Player::rmsIsEmpty()
{
	for (int i = 0; i < 4; i++) {
		if (rms[i] > 0) {
			return false;
		}
	}
	return true;
	
}

int Player::buildingsSize()
{
	return buildings->size();
}

int Player::getCurrentPhrase() {
	return *currentPhase;
}