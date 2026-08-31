#ifndef FIRST_AID_POINT_H
#define FIRST_AID_POINT_H

#include "EventUnit.h"

/**
 * @brief Concrete Leaf - First aid and medical assistance point.
 *
 * Represents a medical station that provides emergency care.
 * This is a CRITICAL SERVICE that ALWAYS remains operational.
 */
class FirstAidPoint : public EventUnit
{

private:
	std::vector<std::string> medicalStaff;
	int suppliesLevel;
	bool isOperational;
	int patientsTreated;
	std::string currentDoctor;
	std::vector<std::string> activeIncidents;
	bool isEvacuating;

public:
	/**
	 * @brief creates an object for the first aid point
	 *
	 * @param name of the first aid point
	 * @param capacity of the first aid point
	 */
	FirstAidPoint(std::string name, int capacity);

	/**
	 * @brief will treat the patient and handle variables as necessary while taking into account certain environmental conditions
	 *
	 * @param condition the condition in which the patient finds themselves
	 */
	void treatPatient(std::string condition);

	/**
	 * @brief help in evacuating if available to calm the people
	 */
	void assistEvacuation();

	/**
	 * @brief to check the variable suppliesLevel to ensure there is enough to treat patients
	 */
	void checkSupplies();

	/**
	 * @brief to prepare by ensuring there is staff members, an operational first aid point as well as enough supplies
	 */
	void prepareForInjuries();

	/**
	 * @brief to increase the amount of supplies
	 *
	 * @param amount of which we increase it
	 */
	void restockSupplies(int amount);

	/**
	 * @brief to ensure there is a team available for a certain active incident occuring
	 *
	 * @param location where the incident is occuring
	 */
	void dispatchTeam(std::string location);

	/**
	 * @brief to change the current doctor that is working
	 *
	 * @param newDoctor who will take over from the current doctor
	 */
	void changeDoctor(std::string newDoctor);

	/**
	 * @brief Handle a received notice from the Subject.
	 *
	 * CRITICAL SERVICE: ALWAYS remains operational.
	 * Reacts to:
	 * - Open: Opens the station
	 * - Close: Closes if told
	 * - WeatherAlert: REMAINS OPEN, prepares for injuries
	 * - Evacuate: Assists evacuation, closes
	 * - ScheduleChange: Changes doctor (if "new_doctor" detail exists)
	 * - MedicalAlert: Dispatches team and treats patients
	 */
	void handleNotice(Notice *notice) override;
	// event component

	/**
	 * @brief open up the first aid station for function
	 */
	void open() override;

	/**
	 * @brief close the first aid station for function
	 */
	void close() override;

	/**
	 * @brief a general overview of the station
	 */
	void reportStatus() override;

	/**
	 * @brief to get the capacity of the station from base class
	 */
	int getCapacity() override;
};

#endif
