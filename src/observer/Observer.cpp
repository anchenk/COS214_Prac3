#include "../../include/observer/Observer.h"
#include "../../include/observer/Subject.h"

Observer::Observer()
{
    subject = nullptr;
}

Observer::~Observer()
{
    if (subject != nullptr)
    {
        subject->detach(this);
    }
}