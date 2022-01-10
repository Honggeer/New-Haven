
#ifndef SUBJECT_H
#define SUBJECT_H


#include "GameObserver.h"
#include <vector>
#include <algorithm>


class Subject
{
public:
	Subject();
	~Subject();
	virtual void attach(Observer*);
	virtual void detach(Observer*);
	virtual void notify();
	
private:
	std::vector<Observer*> *observers;

};
#endif // !SUBJECT_H