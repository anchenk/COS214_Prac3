#include "../../include/observer/NotificationHub.h"

NotificationHub::NotificationHub() : lastNotice(nullptr) {}

NotificationHub::~NotificationHub()
{
    if (lastNotice != nullptr)
    {
        delete lastNotice;
    }
}

void NotificationHub::broadcastToAll(Notice *notice)
{
    lastNotice = notice;
    notify(notice);
}

Notice *NotificationHub::getLastNotice()
{
    return lastNotice;
}