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
/** 
 * @brief Creates an Information Desk object
 */
	InfomationDesk(std::string name, int capacity);
	
/**
 * @brief Adds a staff member to the string vector of staff members
 * 
 * @param staffMember the new staff member that will be added to the list of staff
 */
	void addStaff(std::string staffMember);

	/** 
	 * @brief Adds a new language to the string vector of languages
	 * 
	 * @param newLanguage the new language that will be added to the list of languages
	 */
	std::string addLanguage(std::string newLanguage);

	/** 
	 * @brief Will know if the Information desk is open or not 
	 * 
	 * @return a boolean to let the user know if the desk if open (true) or not (false)
	 */
	bool getIsOpen();

/** 
 * @brief The amount of visitors helped
 * 
 * @return The number of visitors that have been helped at the desk 
 */
	int getVisitorsHelped();

	// event unit
	void handleNotice(Notice *notice) override;
	// event component

	/** 
	 * @brief Will open the desk for use by changing the isOpen variable to true
	 */
	void open() override;

	/** 
	 * @brief Will close the desk by changing the isOpen variable to false
	 */
	void close() override;

	/** 
	 * @brief A general overview of what is happening in the Information desk by using all the qualities of the object 
	 */
	void reportStatus() override;

	/**
	 * @brief the Capacity of the Information desk 
	 * 
	 * @return the capacity specified to the information desk 
	 */
	int getCapacity() override;
};

#endif
