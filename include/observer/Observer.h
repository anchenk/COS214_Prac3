#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

#include "Notice.h"

class Subject;

/**
 * @brief An abstract observer in the observer design pattern.
 *
 * Handles events sent out from a Subject that this Observer is attached to.
 * 
 */
class Observer
{
public:
    /**
     * @brief Virtual destructor.
     *
     * Required for polymorphic destruction of derived classes.
     */
    virtual ~Observer();

    /**
     * @brief Handle an event sent out by the Subject this Observer is attached to.
     *
     * @param notice The event that was sent out by the Subject.
     */
    virtual void update(Notice *notice) = 0;
};

#endif