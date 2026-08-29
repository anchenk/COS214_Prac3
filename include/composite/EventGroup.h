#ifndef EVENT_GROUP_H
#define EVENT_GROUP_H

#include "EventComponent.h"
#include "../observer/Subject.h"

class EventGroup : public EventComponent,
				   public Subject
{

private:
	std::vector<EventComponent *> children;
	bool isOpen;
	bool isOperationZone;

public:
	EventGroup(std::string name, bool isOutdoor, bool isOpen, bool isOperationZone);
	~EventGroup();

	void addChild(EventComponent *child);
	EventComponent *removeChild(EventComponent *child);
	EventComponent *findChild(std::string name);
	std::vector<EventComponent *> getChildren();

	// observer
	void update(Notice *notice) override;

	// event component
	void open() override;
	void close() override;
	void reportStatus() override;
	int getCapacity() override;
};

#endif
