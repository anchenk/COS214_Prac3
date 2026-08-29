#ifndef EVENT_COMPONENT_H
#define EVENT_COMPONENT_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "../observer/Observer.h"

class EventComponent: public Observer{

protected:
	std::string name;
	int capacity;
	bool isOutdoor;
	EventComponent* parent;

public:
	EventComponent(std::string name, int capacity, bool isOutdoor);
	virtual ~EventComponent();
	
	virtual void open() = 0;
	virtual void close() = 0;
	virtual void reportStatus() = 0;
	virtual int getCapacity() = 0;
	std::string getName();
	bool getIsOutdoor();
	virtual void setParent(EventComponent* parent);
	virtual EventComponent* getParent() const;
};

#endif