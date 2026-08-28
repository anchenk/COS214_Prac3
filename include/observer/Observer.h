#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

#include "Notice.h"

class Observer
{
public:
    virtual ~Observer();

    virtual void update(Notice *notice) = 0;
};

#endif