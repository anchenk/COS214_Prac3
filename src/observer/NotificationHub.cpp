#include "../../include/observer/NotificationHub.h"

void NotificationHub::broadcastToAll(Notice *notice)
{
    lastNotice = notice;
    notify(notice);
}

Notice *NotificationHub::getLastNotice()
{
    return lastNotice;
}