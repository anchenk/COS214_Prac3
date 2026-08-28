#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

#include "Notice.h"

class Subject;

/**
 * @brief An abstract observer in the observer design pattern.
 *
 * Handles events sent out from a Subject that this Observer is attached to.
 */
class Observer
{
private:
    Subject *subject;

public:
    Observer();
    /**
     * @brief Automatically detaches this Observer from the Subject it is attached to, if it is attached to one.
     */
    virtual ~Observer();

    /**
     * @brief Handle an event sent out by the Subject this Observer is attached to.
     *
     * @param notice The event that was sent out by the Subject.
     */
    virtual void update(Notice *notice) = 0;

    /**
     * @brief Allow Subject to set this instance's "subject" field.
     */
    friend class Subject;
};

#endif