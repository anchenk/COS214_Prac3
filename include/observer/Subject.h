#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

#include "../enums/EventType.h"
#include "Observer.h"

class Subject
{
private:
    std::vector<Observer *> attachedObservers;

public:
    virtual ~Subject();

    void attach(Observer *observer);
    void detach(Observer *observer);
    void notify(EventType eventType);
};

#endif