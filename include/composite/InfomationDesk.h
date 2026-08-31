#ifndef INFOMATION_DESK_H
#define INFOMATION_DESK_H

#include "EventUnit.h"

/**
 * @brief Concrete Leaf - Visitor information desk.
 * 
 * Represents an information desk that helps visitors navigate the bazaar.
 * This is a CRITICAL SERVICE that remains OPEN during most alerts.
 */
class InformationDesk : public EventUnit
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
	InformationDesk(std::string name, int capacity);

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

	/**
	 * @brief Handle a received notice from the Subject.
     * 
     * CRITICAL SERVICE: Remains open during most alerts.
     * Reacts to:
     * - Open: Opens the desk
     * - Close: Can close when told to
     * - WeatherAlert: STAYS OPEN, provides weather safety info
     * - Evacuate: Closes and assists with evacuation
     * - ScheduleChange: Adds staff (if "new_staff" detail exists)
     * - MedicalAlert: STAYS OPEN, directs visitors away from incident
     * 
     * @param notice The notice to handle
	 */
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
