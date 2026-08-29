#include "../../include/composite/EventUnit.h"

EventUnit::EventUnit(std::string name, bool isOutdoor, int capacity) : EventComponent(name, isOutdoor), capacity(capacity) {}

void EventUnit::update(Notice *notice)
{
    handleNotice(notice); // delegate to separate method
}

int EventUnit::getCapacity()
{
    return capacity;
}