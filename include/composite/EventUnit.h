#ifndef EVENT_UNIT_H
#define EVENT_UNIT_H

#include "EventComponent.h"

class EventUnit : public EventComponent
{
private:
    int capacity;

public:
    EventUnit(std::string name, bool isOutdoor, int capacity);

    virtual void handleNotice(Notice *notice) = 0;

    void update(Notice *notice) override final;
    int getCapacity() override;
};

#endif
