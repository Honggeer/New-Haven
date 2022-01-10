#pragma once
#include "Player.h"
#include "GameObserver.h"
class TurnObserver : public Observer
{
private:
	Player* subject;
public:
	TurnObserver(Player*);
	~TurnObserver();
	void update();

};



