#ifndef EVENT_UNIT_H
#define EVENT_UNIT_H

#include "EventComponent.h"

/**
 * @brief Abstract Leaf participant in the Composite pattern.
 *
 * Base class for all concrete leaf components.
 * Implements the Observer interface to receive notifications.
 */
class EventUnit : public EventComponent
{
private:
    int capacity;

public:
    /**
     * @brief Construct a new Event Unit object.
     *
     * @param name The name of the unit
     * @param isOutdoor Whether the unit is outdoors
     * @param capacity The maximum capacity
     */
    EventUnit(std::string name, bool isOutdoor, int capacity);

    /**
     * @brief Handle a received notice.
     * 
     * Pure virtual - must be implemented by concrete leaves.
     * 
     * @param notice The notice to handle
     */
    virtual void handleNotice(Notice *notice) = 0;

    /**
     * @brief Update method called by Subject.
     * 
     * Delegates to handleNotice() for concrete leaf processing.
     * 
     * @param notice The notice being received
     */
    void update(Notice *notice) override final;

    /**
     * @brief Get the capacity of this leaf.
     * 
     * @return int The capacity value
     */
    int getCapacity() override;
};

#endif
