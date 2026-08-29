#ifndef EVENT_COMPONENT_H
#define EVENT_COMPONENT_H

#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "../observer/Observer.h"
#include "../composite/EventGroup.h"

class EventComponent : public Observer
{
protected:
	std::string name;
	bool isOutdoor;
	EventGroup *parent;

public:
	EventComponent(std::string name, bool isOutdoor);
	virtual ~EventComponent();

	virtual void open() = 0;
	virtual void close() = 0;
	virtual void reportStatus() = 0;
	virtual int getCapacity() = 0;
	std::string getName();
	bool getIsOutdoor();
	virtual void setParent(EventGroup *parent);
	EventGroup *getParent() const;
};

#endif