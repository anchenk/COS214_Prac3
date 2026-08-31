#ifndef NOTIFICATION_HUB_H
#define NOTIFICATION_HUB_H

#include <vector>

#include "Notice.h"
#include "Subject.h"

/**
 * @brief Sends out events relating to a market gathering.
 *
 * Acts as a concrete subject in the observer design pattern.
 * Sends out events relating to a market gathering so that different components of the market can handle them and update in their own ways.
 * 
 */
class NotificationHub : public Subject
{
private:
    Notice *lastNotice;

public:
    /**
     * @brief Construct a new Notification Hub object.
     *
     * Initializes with no cached notice.
     */
    NotificationHub();

    /**
     * @brief Destroy the Notification Hub object.
     *
     * Deletes the cached lastNotice if it exists.
     */
    ~NotificationHub();

    /**
     * @brief Cache an event and then send it out to every registered listener.
     *
     * Notices passed into this method become owned by this NotificationHub and will be deleted when this instance is deleted.
     *
     * @param notice The event to cache and broadcast.
     */
    void broadcastToAll(Notice *notice);

    /**
     * @brief Gets the last event that was sent out.
     *
     * @return the last Notice that was sent out, or nullptr if no event has been sent out since the creation of this NotificationHub.
     */
    Notice *getLastNotice();
};

#endif