#include "../../include/observer/Subject.h"

Subject::~Subject()
{
    // empty
}

void Subject::attach(Observer *observer)
{
    if (std::find(attachedObservers.begin(), attachedObservers.end(), observer) != attachedObservers.end())
    {
        // observer is already attached
        return;
    }

    attachedObservers.push_back(observer);
}

void Subject::detach(Observer *observer)
{
    attachedObservers.erase(std::remove(attachedObservers.begin(), attachedObservers.end(), observer), attachedObservers.end());
}

void Subject::notify(EventType eventType)
{
    for (Observer *observer : attachedObservers)
    {
        observer->update(eventType);
    }
}