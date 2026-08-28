#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

#include "Notice.h"
#include "Observer.h"

class Subject
{
private:
    std::vector<Observer *> attachedObservers;

public:
    virtual ~Subject();

    /**
     * TODO: include policy for duplicate observer registrations.
     */
    virtual void attach(Observer *observer);

    /**
     * TODO: include policy for invalid registration detachments.
     */
    virtual void detach(Observer *observer);

    virtual void notify(Notice *notice);
};

#endif