#ifndef EVENT_UNIT_H
#define EVENT_UNIT_H

#include "EventComponent.h"

class EventUnit : public EventComponent
{
public:
    EventUnit(std::string name, int capacity, bool isOutdoor);
    virtual ~EventUnit();
    virtual void handleNotice(Notice *notice) = 0;

    // observer
    void update(Notice *notice) override;
};

#endif
