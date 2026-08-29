#include "../../include/composite/VendorBooth.h"

VendorBooth::VendorBooth(std::string name, int capacity, std::string craftType) : EventUnit(name, false, capacity), craftType(craftType), isOpen(false), isSecured(false), currentStaff("")
{
}

void VendorBooth::secureGoods()
{
    isSecured = true;
    std::cout << "Your goods are nice and secure!!" << std::endl;
}

void VendorBooth::changeStaff(std::string newStaff)
{
    if (currentStaff != "")
        std::cout << "Say goodbye to " << currentStaff << std::endl;
    currentStaff = newStaff;
    std::cout << "Say hi to your new staff member, " << newStaff << std::endl;
}

void VendorBooth::handleNotice(Notice *notice)
{
    // not sure how to do this at the moment
}

// event component
void VendorBooth::open()
{
    isOpen = true;
    std::cout << "The booth is officially opened!! Welcome one and all, make sure to bring a friend along" << std::endl;
}

void VendorBooth::close()
{
    isOpen = false;
    std::cout << "Oh no! The booth is closed... come back next time!" << std::endl;
}

void VendorBooth::reportStatus()
{
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Craft Type: " << craftType << std::endl;
    std::cout << "Capacity: " << getCapacity() << std::endl;
    std::cout << "Is Open: " << (isOpen ? "Yes" : "No") << std::endl;
    std::cout << "Is Secured: " << (isSecured ? "Yes" : "No") << std::endl;
    std::cout << "Current Staff: " << (currentStaff.empty() ? "None" : currentStaff) << std::endl;
    std::cout << "Location: " << (getIsOutdoor() ? "Outdoors" : "Indoors") << std::endl;
}

int VendorBooth::getCapacity()
{
    return this->EventUnit::getCapacity();
}