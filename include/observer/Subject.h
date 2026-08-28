#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

#include "Notice.h"
#include "Observer.h"

/**
 * @bief An abstract subject in the observer design pattern.
 *
 * Provides an interface for classes to have event listeners registered to them so that the listeners can be auto notified on an event.
 */
class Subject
{
private:
    std::vector<Observer *> attachedObservers;

public:
    virtual ~Subject();

    /**
     * @brief Add an event listener to be called whenever an event occurs.
     *
     * If an Observer that is already attached to this Subject is passed into this method, it is ignored.
     * Attached Observers will not be deleted when this subject is deleted.
     * Sets Observer.subject so that the Observer can automatically detach itself from this Subject when it is deleted.
     *
     * @param observer The Observer instance that will handle the event.
     */
    void attach(Observer *observer);

    /**
     * TODO: include policy for invalid registration detachments.
     * @brief Remove a registered event listener from handling future events.
     *
     * If an Observer that is not attached to this Subject is passed into this method, it is ignored.
     *
     * @param observera The Observer instance to detach from this Subject so that it stops handling events.
     */
    void detach(Observer *observer);

    /**
     * @brief Send an event to all attached Observers.
     *
     * @param notice The event to broadcast to all attached Observers.
     */
    void notify(Notice *notice);
};

#endif