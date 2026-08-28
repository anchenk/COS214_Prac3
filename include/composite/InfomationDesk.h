#ifndef INFOMATION_DESK_H
#define INFOMATION_DESK_H

#include "EventUnit.h"

class InfomationDesk : public EventUnit
{
private:
	std::vector<std::string> staff;
	std::vector<std::string> languages;
	bool isOpen;
	int visitorsHelped;

public:
	InfomationDesk(std::string name, int capacity);
	void addStaff(std::string staffMember);
	std::string addLanguage(std::string newLanguage);
	bool getIsOpen();
	int getVisitorsHelped();

	// event unit
	void handleNotice(Notice *notice) override;
	// event component
	void open() override;
	void close() override;
	void reportStatus() override;
	int getCapacity() override;
};

#endif
