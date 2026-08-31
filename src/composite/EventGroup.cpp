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
    std::cout << "We are officially open" << std::endl;
    if (!children.empty())
    {
        // maybe output
        std::cout << "Opening all the different facilities..." << std::endl;
        for (const auto &child : children)
        {
            child->open();
        }
    }
    else
    {
        // output
        std::cout << "Ohhhh... it looks like there are no facilities..." << std::endl;
    }
}

void EventGroup::close()
{
    isOpen = false;
    // output
    std::cout << "We are officially closing... :(" << std::endl;
    if (!children.empty())
    {
        // maybe output
        std::cout << "Closing all the facilities..." << std::endl;
        for (const auto &child : children)
        {
            child->close();
        }
    }
    else
    {
        // output
        std::cout << "There are no facilities to close!" << std::endl;
    }
}

void EventGroup::reportStatus()
{
    // output
    std::cout << "Reporting for all the facilities now!" << std::endl;
    if (!children.empty())
    {
        for (const auto &child : children)
        {
            child->reportStatus();
        }
    }
    else
    {
        std::cout << "Oops... there is no facilities to get a report on..." << std::endl;
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
