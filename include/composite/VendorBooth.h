#ifndef VENDOR_BOOTH_H
#define VENDOR_BOOTH_H

#include "EventUnit.h"

/**
 * @brief Concrete Leaf - Vender booth for selling crafts.
 * Represents an individual vendor booth in the artisanal bazaar.
 * Reacts to various event notices including weather alerts, evacuation,
 * and shift changes.
 */
class VendorBooth : public EventUnit
{
private:
	std::string craftType;
	bool isOpen;
	bool isSecured;
	std::string currentStaff;

public:
	/**
	 * @brief Create a new Venderbooth object.
	 *
	 * @param name The name of the Venderbooth.
	 * @param capacity The capacity of the booth.
	 */
	VendorBooth(std::string name, int capacity, std::string craftType);

	/**
	 * @brief Changes the isSecure status of the booth.
	 */
	void secureGoods();
	/**
	 * @brief Changes the current staff memeber
	 *
	 * @param newStaff The new staff member that will work at the booth
	 */
	void changeStaff(std::string newStaff);

	/**
	 * @brief Handle a received notice from the Subject.
	 *
	 * Reacts to different notice types:
	 * - Open: Opens the booth
	 * - Close: Closes the booth
	 * - WeatherAlert: Remains open
	 * - Evacuate: Closes and secures goods
	 * - ScheduleChange: Changes staff (if "new_staff" detail exists)
	 * - MedicalAlert: Closes and secures goods
	 *
	 * @param notice The notice to handle
	 */
	void handleNotice(Notice *notice) override;
	// event component

	/**
	 * @brief Open up the booth, changes the isOpen status
	 */
	void open() override;

	/**
	 * @brief Closes the booth, by changing the isOpen status
	 */
	void close() override;

	/**
	 * @brief A general overview of the booth
	 */
	void reportStatus() override;

	/**
	 * @brief Gets the capacity of the booth from the base class
	 *
	 * @return the number of the capacity of the booth
	 */
	int getCapacity() override;
};

#endif
