#include "../../include/composite/EventComponent.h"

EventComponent::EventComponent(std::string name, int capacity, bool isOutdoor)
{
}

EventComponent::~EventComponent()
{
}

std::string EventComponent::getName()
{
    return this->name;
}

bool EventComponent::getIsOutdoor()
{
    return this->isOutdoor;
}

void EventComponent::setParent(EventComponent *parent)
{
    this->parent = parent;
}

EventComponent *EventComponent::getParent() const
{
    return this->parent;
}