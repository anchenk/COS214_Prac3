#include "../../include/composite/InfomationDesk.h"

InfomationDesk::InfomationDesk(std::string name, int capacity) : EventUnit(name, false, capacity), isOpen(false), visitorsHelped(0)
{
}

void InfomationDesk::addStaff(std::string staffMember)
{
	staff.push_back(staffMember);
	std::cout << "Welcome to the team, " << staffMember << std::endl;
}

std::string InfomationDesk::addLanguage(std::string newLanguage)
{
	for (const auto &lang : languages)
	{
		if (lang == newLanguage)
		{
			std::cout << "Ahh ma cheri, we can already speak " << newLanguage << std::endl;
			return newLanguage;
		}
	}
	languages.push_back(newLanguage);
	std::cout << "Oui oui bonjour! Hola, tudo bem? Hallo hoe ganit! We can speak even more languages now like, " << newLanguage << std::endl;
	return newLanguage;
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
	isOpen = true;
	std::cout << "Need some info? Come on here, we got it all! "<< name << " is open!" << std::endl;
}

void InfomationDesk::close()
{
	isOpen = false;
	std::cout << "Unfortunately we have run out of information at the moment... " << name << "is closed" << std::endl;
}

void InfomationDesk::reportStatus()
{
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Capacity: " << getCapacity() << std::endl;
	std::cout << "Is Open: " << (isOpen ? "Yes" : "No") << std::endl;
	std::cout << "Visitors Helped: " << visitorsHelped << std::endl;
	std::cout << "Staff Members: " << staff.size() << std::endl;

	if (!staff.empty())
	{
		std::cout << "Staff:" << std::endl;
		for (const auto &member : staff)
		{
			std::cout << "  - " << member << std::endl;
		}
	}

	std::cout << "Languages Offered: " << languages.size() << std::endl;
	if (!languages.empty())
	{
		std::cout << "Languages:" << std::endl;
		for (const auto &lang : languages)
		{
			std::cout << "  - " << lang << std::endl;
		}
	}

	std::cout << "Location: " << (getIsOutdoor() ? "Outdoor" : "Indoor") << std::endl;
}

int InfomationDesk::getCapacity()
{
	return EventUnit::getCapacity();
}