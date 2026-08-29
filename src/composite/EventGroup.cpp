#include "../../include/composite/EventGroup.h"

EventGroup::EventGroup(std::string name, int capacity, bool isOutdoor, std::string groupName, bool isOpen, bool isOperationZone) {}

void EventGroup::addChild(EventComponent *child)
{
}

EventComponent *EventGroup::removeChild(EventComponent *child)
{
}

EventComponent *EventGroup::findChild(std::string name)
{
}

std::vector<EventComponent *> EventGroup::getChildren()
{
    return this->children;
}

void EventGroup::update(Notice *notice)
{
}

void EventGroup::attach(Observer *observer)
{
}

void EventGroup::detach(Observer *observer)
{
}

void EventGroup::notify(Notice *notice)
{
}

void open()
{
}

void close()
{
}

void reportStatus()
{
}

int getCapacity()
{
}
