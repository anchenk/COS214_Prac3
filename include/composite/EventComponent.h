#ifndef EVENT_COMPONENT_H
#define EVENT_COMPONENT_H

#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "../observer/Observer.h"
#include "../composite/EventGroup.h"

/**
 * @brief Abstract Component participant in the Composite pattern.
 *
 * Represents any element in the event structure - both composites (EventGroup)
 * and leaves (EventUnit). Defines the common interface for all components.
 *
 * This class also implements Observer, allowing components to receive
 * notifications from Subjects.
 *
 * @note This class is abstract and cannot be instantiated directly.
 * @note Implements the Component role in the Composite pattern.
 * @note Implements the Observer role in the Observer pattern.
 */

class EventComponent : public Observer
{
protected:
	std::string name;
	bool isOutdoor;
	EventGroup *parent;

public:
	/**
	 *
	 * @brief Construct a new Event Component object.
	 *
	 * @param name The unique name of the component
	 * @param isOutdoor Whether the component is outdoors (affects weather reactions)
	 */
	EventComponent(std::string name, bool isOutdoor);

	/**
	 * @brief Virtual destructor.
	 *
	 * Required for polymorphic destruction of derived classes.
	 */
	virtual ~EventComponent();

	/**
	 * @brief Open the event component.
	 *
	 * Pure virtual - must be implemented by derived classes.
	 * For EventGroup: opens all children recursively.
	 * For EventUnit: opens the specific leaf.
	 */
	virtual void open() = 0;

	/**
	 * @brief Close the event component.
	 *
	 * Pure virtual - must be implemented by derived classes.
	 * For EventGroup: closes all children recursively.
	 * For EventUnit: closes the specific leaf.
	 */
	virtual void close() = 0;

	/**
	 * @brief Report the status of the event component.
	 *
	 * Pure virtual - must be implemented by derived classes.
	 * Prints information about the component and its children (if any).
	 */
	virtual void reportStatus() = 0;

	/**
	 * @brief Get the total capacity of the event component.
	 *
	 * Pure virtual - must be implemented by derived classes.
	 * For EventGroup: returns sum of all children capacities.
	 * For EventUnit: returns its own capacity.
	 *
	 * @return int The total capacity
	 */
	virtual int getCapacity() = 0;

	/**
	 * @brief Get the name of the component.
	 *
	 * @return std::string The component name
	 */
	std::string getName();

	/**
	 * @brief Check if the component is outdoors.
	 *
	 * @return bool True if outdoor, false if indoor
	 */
	bool getIsOutdoor();

	/**
	 * @brief Set the parent of this component.
	 *
	 * This is a non-owning back-pointer for tree navigation.
	 * Called by EventGroup::addChild() when adding a child.
	 *
	 * @param parent Pointer to the parent EventGroup (nullptr for root)
	 */
	virtual void setParent(EventGroup *parent);

	/**
	 * @brief Get the parent of this component.
	 *
	 * @return EventGroup* Pointer to parent EventGroup, or nullptr if root
	 */
	EventGroup *getParent() const;
};

#endif