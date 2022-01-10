#pragma once
//partr 2 : Game stati
#include "GameObserver.h"
#include "Player.h"
#include <vector>
class StatisticsObserver : public Observer
{
private:
	vector <Player*>* Players;
public:
	StatisticsObserver(vector<Player*> *players_);
	~StatisticsObserver();
	void update();


};