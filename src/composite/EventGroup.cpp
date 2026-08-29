#include "../../include/composite/EventGroup.h"

EventGroup::EventGroup(std::string name, bool isOutdoor, bool isOpen, bool isOperationZone) : EventComponent(name, isOutdoor), isOpen(isOpen), isOperationZone(isOperationZone) {}

EventGroup::~EventGroup()
{
    for (EventComponent *child : children)
        delete child;
    children.clear();
}

void EventGroup::addChild(EventComponent *child)
{
    if (child == nullptr)
        return;

    child->setParent(this);
    children.push_back(child);
}

EventComponent *EventGroup::removeChild(EventComponent *child)
{
    if (child->getParent() != this)
        return;

    child->setParent(nullptr);
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
}

EventComponent *EventGroup::findChild(std::string name)
{
    for (EventComponent *child : children)
    {
        if (child->getName() == name)
        {
            return child;
        }
    }

    return nullptr;
}

std::vector<EventComponent *> EventGroup::getChildren()
{
    return this->children;
}

void EventGroup::update(Notice *notice)
{
    notify(notice); // forward event to children
}

void EventGroup::open()
{
    // TODO
}

void EventGroup::close()
{
    // TODO
}

void EventGroup::reportStatus()
{
    // TODO
}

int EventGroup::getCapacity()
{
    int s = 0;

    for (EventComponent *child : children)
        s += child->getCapacity();

    return s;
}
