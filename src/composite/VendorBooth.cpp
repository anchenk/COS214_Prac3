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
    if (!notice)
        return;

    // switch severity
    switch (notice->getSeverity())
    {
    case Severity::Info:
        std::cout << "Informational message: ";
        break;
    case Severity::Warning:
        std::cout << "Warning message: ";
        break;
    case Severity::Critical:
        std::cout << "Critical Message: ";
        break;
    }

    // switch type
    switch (notice->getType())
    {
    case NoticeType::Open:
        open();
        break;
    case NoticeType::Close:
        close();
        break;
    case NoticeType::Evacuate:
        close();
        secureGoods();
        std::cout << "LEAVE IN A CALM ORDER! " << name << " evacuated - goods secured" << std::endl;
        break;
    case NoticeType::WeatherAlert:
        std::cout << "Incoming weather! " << name << " is indoor, safe to continue operating." << std::endl;
        break;
    case NoticeType::ScheduleChange:
        if (notice->hasDetail("new_staff"))
        {
            changeStaff(notice->getDetail("new_staff"));
        }
        break;
    case NoticeType::MedicalAlert:
        if (isOpen)
        {
            close();
            secureGoods();
            std::cout << "Everybody stay back! " << name << " closed due to medical emergency" << std::endl;
        }
        break;
    default:
        std::cout << name << " received unknown notice: " << notice->getMessage() << std::endl;
        break;
    }
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