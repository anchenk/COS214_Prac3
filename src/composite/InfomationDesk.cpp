#include "../../include/composite/InfomationDesk.h"

InformationDesk::InformationDesk(std::string name, int capacity) : EventUnit(name, false, capacity), isOpen(false), visitorsHelped(0)
{
}

void InformationDesk::addStaff(std::string staffMember)
{
	staff.push_back(staffMember);
	std::cout << "Welcome to the team, " << staffMember << std::endl;
}

std::string InformationDesk::addLanguage(std::string newLanguage)
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

bool InformationDesk::getIsOpen()
{
	return this->isOpen;
}

int InformationDesk::getVisitorsHelped()
{
	return this->visitorsHelped;
}

void InformationDesk::handleNotice(Notice *notice)
{
	if (!notice)
		return;

	switch (notice->getType())
	{
	case NoticeType::Open:
		open();
		break;
	case NoticeType::Close:
		close();
		break;
	case NoticeType::Evacuate:
		std::cout << "EVERYBODY THIS WAY! " << name << " is assisting with evacuation" << std::endl;
		close();
		break;
	case NoticeType::WeatherAlert:
		std::cout << "NOBODY GO OUTSIDE! " << name << " REMAINS OPEN - providing weather safety info" << std::endl;
		break;
	case NoticeType::ScheduleChange:
		if (notice->hasDetail("new_staff"))
		{
			addStaff(notice->getDetail("new_staff"));
		}
		break;
	case NoticeType::MedicalAlert:
		std::cout << name << " REMAINS OPEN - directing visitors away from medical incident" << std::endl;
		break;
	default:
		std::cout << name << " received unknown notice: " << notice->getMessage() << std::endl;
		break;
	}
}

// event component
void InformationDesk::open()
{
	isOpen = true;
	std::cout << "Need some info? Come on here, we got it all! " << name << " is open!" << std::endl;
}

void InformationDesk::close()
{
	isOpen = false;
	std::cout << "Unfortunately we have run out of information at the moment... " << name << "is closed" << std::endl;
}

void InformationDesk::reportStatus()
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

int InformationDesk::getCapacity()
{
	return EventUnit::getCapacity();
}