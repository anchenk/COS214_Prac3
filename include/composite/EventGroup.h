#ifndef EVENT_GROUP_H
#define EVENT_GROUP_H

#include "EventComponent.h"
#include "../observer/Subject.h"

/**
 * @brief Composite participant in the Composite pattern.
 *
 * Represents a container that can hold multiple EventComponent children
 * (both leaves and other composites). Implements recursive operations
 * by delegating to all children.
 *
 * Also acts as a Concrete Subject in the Observer pattern, allowing
 * children to register as observers and receive cascading notifications.
 *
 * @note Implements the Composite role in the Composite pattern.
 * @note Implements the Concrete Subject role in the Observer pattern.
 * @note Does NOT implement Observer directly - receives via EventComponent inheritance.
 * 
 * @author Caleb Jennings - u25173805, Anchen Kruger - u25073703, Chloe Larsen - u25004141
 */

class EventGroup : public EventComponent,
				   public Subject
{

private:
	std::vector<EventComponent *> children;
	bool isOpen;
	bool isOperationZone;

public:
	/**
	 * @brief Construct a new Event Group object.
	 *
	 * @param name The name of the group
	 * @param isOutdoor Whether the group is outdoors
	 * @param isOpen Initial open state
	 * @param isOperationZone Whether this is an operational zone
	 */
	EventGroup(std::string name, bool isOutdoor, bool isOpen, bool isOperationZone);

	/**
	 * @brief Destroy the Event Group object.
	 *
	 * Deletes all owned children to prevent memory leaks.
	 */
	~EventGroup();

	/**
	 * @brief Add a child component to this group.
	 *
	 * Takes ownership of the child and automatically registers it
	 * as an observer of this group (if it implements Observer).
	 *
	 * @param child Pointer to the child component to add
	 */
	void addChild(EventComponent *child);

	/**
	 * @brief Remove a child component from this group.
	 *
	 * Removes the child from the children list and detaches it
	 * as an observer. Ownership is transferred to the caller.
	 *
	 * @param child Pointer to the child component to remove
	 * @return EventComponent* The removed child (caller now owns it), or nullptr if not found
	 */
	EventComponent *removeChild(EventComponent *child);

	/**
	 * @brief Find a child component by name (recursive).
	 *
	 * Searches this group and all descendant groups for a component
	 * with the matching name.
	 *
	 * @param name The name of the child to find
	 * @return EventComponent* Pointer to the found component, or nullptr if not found
	 */
	EventComponent *findChild(std::string name);

	EventComponent *findChild(std::string name);

	/**
	 * @brief Get all children of this group.
	 *
	 * @return std::vector<EventComponent*> Vector of child components
	 */
	std::vector<EventComponent *> getChildren();

	/**
	 * @brief Update method called by Subject (parent or NotificationHub).
	 *
	 * Receives a notification from the parent/Subject, handles it at this level,
	 * and forwards it to all registered child observers (cascade).
	 *
	 * @param notice The notice being received
	 */
	void update(Notice *notice) override;

	/**
	 * @brief Open the group.
	 *
	 * Sets isOpen to true and recursively opens all children.
	 */
	void open() override;

	/**
	 * @brief Close the group.
	 *
	 * Sets isOpen to false and recursively closes all children.
	 */
	void close() override;

	/**
	 * @brief Display the current status of the group.
	 *
	 * Prints: name, capacity, children count, observers count,
	 * open status, outdoor status, operation zone status, and parent.
	 * Also recursively reports status of all children.
	 */
	void reportStatus() override;

	/**
	 * @brief Get the total capacity of the group.
	 *
	 * Sums the capacity of this group plus all children capacities.
	 *
	 * @return int The total capacity
	 */
	int getCapacity() override;
};

#endif
