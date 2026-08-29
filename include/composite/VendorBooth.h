#ifndef VENDOR_BOOTH_H
#define VENDOR_BOOTH_H

#include "EventUnit.h"

/** 
 * @brief A leaf type for the base class 
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

	// event unit
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
