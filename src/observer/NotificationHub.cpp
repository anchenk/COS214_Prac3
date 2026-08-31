#include "../../include/observer/NotificationHub.h"

NotificationHub::NotificationHub() : lastNotice(nullptr) {}

NotificationHub::~NotificationHub()
{
    lastNotice = nullptr;
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