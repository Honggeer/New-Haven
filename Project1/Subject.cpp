#include "Subject.h"


Subject::Subject()
{
	observers = new std:: vector<Observer*>;
}
Subject::~Subject()
{
    for (int i = 0; i < observers->size(); i++) {
        delete(observers->at(i));
    }

    observers->clear();
    delete observers;
}

void Subject::attach(Observer *observer_) {
    observers->push_back(observer_);
}

void Subject::detach(Observer *observer_) {

    observers->erase(std::remove(observers->begin(),observers->end(),observer_), observers->end());
}

void Subject::notify() {

    for (int i = 0; i < observers->size(); i++) {
        observers->at(i)->update();
    }
}