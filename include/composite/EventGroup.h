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
	/**
	 * @brief constructor for the eventgroup object
	 */
	EventGroup(std::string name, bool isOutdoor, bool isOpen, bool isOperationZone);

	/**
	 * @brief destructor for the object
	 */
	~EventGroup();

	/**
	 * @brief add leaf node to the eventGroup
	 *
	 * @param child the leaf that will be attached to this specific object
	 */
	void addChild(EventComponent *child);

	/**
	 * @brief to removev a leaf from the object
	 *
	 * @param child the child to remove
	 */
	EventComponent *removeChild(EventComponent *child);

	/**
	 * @brief find a specific child within the object eventgroup
	 *
	 * @param name the child be are looking for
	 */
	EventComponent *findChild(std::string name);

	std::vector<EventComponent *> getChildren();

	// observer
	void update(Notice *notice) override;

	// event component

	/**
	 * @brief open up the first aid station for function
	 */
	void open() override;

	/**
	 * @brief close the first aid station for function
	 */
	void close() override;

	/**
	 * @brief a general overview of the station
	 */
	void reportStatus() override;

	/**
	 * @brief to get the capacity of the station from base class
	 */
	int getCapacity() override;
};

#endif
