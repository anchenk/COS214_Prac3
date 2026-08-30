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
    isOpen = true;
    // output
    if (!children.empty())
    {
        // maybe output
        for (const auto &child : children)
        {
            child->open();
        }
    }
    else
    {
        // output
    }
}

void EventGroup::close()
{
    isOpen = false;
    // output
    if (!children.empty())
    {
        // maybe output
        for (const auto &child : children)
        {
            child->close();
        }
    }
    else
    {
        // output
    }
}

void EventGroup::reportStatus()
{
    // output
    if (!children.empty())
    {
        for (const auto &child : children)
        {
            child->reportStatus();
        }
    }
    else
    {
        // output
    }
}

int EventGroup::getCapacity()
{
    int total = 0;

    for (EventComponent *child : children)
        total += child->getCapacity();

    return total;
}
