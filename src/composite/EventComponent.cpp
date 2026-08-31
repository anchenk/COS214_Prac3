#include "../../include/composite/EventComponent.h"
#include "../../include/composite/EventGroup.h"

EventComponent::EventComponent(std::string name, bool isOutdoor) : name(name), isOutdoor(isOutdoor), parent(nullptr) {}

EventComponent::~EventComponent()
{
    if (parent != nullptr)
        parent->detach(this);
}

std::string EventComponent::getName()
{
    return name;
}

bool EventComponent::getIsOutdoor()
{
    return isOutdoor;
}

void EventComponent::setParent(EventGroup *parent)
{
    if (this->parent != nullptr)
        this->parent->detach(this); // stop getting events from old parent
    if (parent != nullptr)
        parent->attach(this); // get events from new parent

    this->parent = parent;
}

EventGroup *EventComponent::getParent() const
{
    return parent;
}