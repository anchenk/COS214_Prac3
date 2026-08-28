#include "../../include/observer/Subject.h"

Subject::~Subject()
{
    for (Observer *observer : attachedObservers)
    {
        observer->subject = nullptr;
    }
}

void Subject::attach(Observer *observer)
{
    if (std::find(attachedObservers.begin(), attachedObservers.end(), observer) != attachedObservers.end())
    {
        // observer is already attached to this subject
        return;
    }
    if (observer->subject != nullptr)
    {
        // observer is alread attached to another subject
        throw "Observer cannot be attached to more than one subject";
    }

    attachedObservers.push_back(observer);
    observer->subject = this; // cache to later detach if observer is deleted
}

void Subject::detach(Observer *observer)
{
    attachedObservers.erase(std::remove(attachedObservers.begin(), attachedObservers.end(), observer), attachedObservers.end());
}

void Subject::notify(Notice *notice)
{
    for (Observer *observer : attachedObservers)
    {
        observer->update(notice);
    }
}