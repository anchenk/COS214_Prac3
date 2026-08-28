#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

#include "../enums/EventType.h"

class Observer
{
public:
    virtual ~Observer();

    virtual void update(EventType eventType) = 0;
};

#endif