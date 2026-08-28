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
    void attach(Observer *observer);

    /**
     * TODO: include policy for invalid registration detachments.
     */
    void detach(Observer *observer);

    void notify(Notice *notice);
};

#endif