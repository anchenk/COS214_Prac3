#ifndef NOTIFICATION_HUB_H
#define NOTIFICATION_HUB_H

#include <vector>

#include "Notice.h"
#include "Subject.h"

class NotificationHub : public Subject
{
private:
    Notice *lastNotice;

public:
    void broadcastToAll(Notice *notice);
    Notice *getLastNotice();
};

#endif