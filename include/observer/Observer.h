#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

#include "Notice.h"

class Subject;

class Observer
{
private:
    Subject *subject;

public:
    Observer();
    virtual ~Observer();

    virtual void update(Notice *notice) = 0;

    friend class Subject;
};

#endif