#ifndef VENDOR_BOOTH_H
#define VENDOR_BOOTH_H

#include "EventUnit.h"

class VendorBooth : public EventUnit
{
private:
	std::string craftType;
	bool isOpen;
	bool isSecured;
	std::string currentStaff;

public:
	VendorBooth(std::string name, int capacity, std::string craftType);
	void secureGoods();
	void changeStaff(std::string newStaff);

	// event unit
	void handleNotice(Notice *notice) override;
	// event component
	void open() override;
	void close() override;
	void reportStatus() override;
	int getCapacity() override;
};

#endif
