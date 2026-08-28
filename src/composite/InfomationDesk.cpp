#include "../../include/composite/InfomationDesk.h"

InfomationDesk::InfomationDesk(std::string name, int capacity)
{
}

void InfomationDesk::addStaff(std::string staffMember)
{
}

std::string InfomationDesk::addLanguage(std::string newLanguage)
{
}

bool InfomationDesk::getIsOpen()
{
	return this->isOpen;
}

int InfomationDesk::getVisitorsHelped()
{
	return this->visitorsHelped;
}

void InfomationDesk::handleNotice(Notice *notice)
{
}

// event component
void InfomationDesk::open()
{
}

void InfomationDesk::close()
{
}

void InfomationDesk::reportStatus()
{
}

int InfomationDesk::getCapacity()
{
}