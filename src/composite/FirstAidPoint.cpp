#include "../../include/composite/FirstAidPoint.h"

FirstAidPoint::FirstAidPoint(std::string name, int capacity) : EventUnit(name, true, capacity), suppliesLevel(0), isOperational(false), patientsTreated(0), isEvacuating(false)
{
}

void FirstAidPoint::treatPatient(std::string condition)
{
    if (!isOperational)
    {
        std::cout << "First aid point is not operational at the moment... our apologies" << std::endl;
        return;
    }

    if (medicalStaff.empty())
    {
        std::cout << "No medical staff available to treat patient, oh deary" << std::endl;
        return;
    }

    if (suppliesLevel == 0)
    {
        std::cout << "No more supplies!!" << std::endl;
        return;
    }

    patientsTreated++;
    suppliesLevel -= 1;

    std::cout << "Treating patient with condition: " << condition << std::endl;
}

void FirstAidPoint::assistEvacuation()
{
    if (isEvacuating)
    {
        std::cout << "WE ARE ALREADY EVACUATING, COME ON!!" << std::endl;
        return;
    }

    if (!isOperational)
    {
        std::cout << "There is no one here to help, gotta figure it out yourself..." << std::endl;
        return;
    }

    isEvacuating = true;

    std::cout << "Everyone stay calm and follow me! Evacuation headed this way" << std::endl;
}

void FirstAidPoint::checkSupplies()
{
    if (suppliesLevel > 70)
    {
        std::cout << "Status: Supplies are well stocked." << std::endl;
    }
    else if (suppliesLevel > 40)
    {
        std::cout << "Status: Supplies are adequate." << std::endl;
    }
    else if (suppliesLevel > 20)
    {
        std::cout << "Warning: Supplies are running low." << std::endl;
    }
    else
    {
        std::cout << "CRITICAL: Supplies are dangerously low!" << std::endl;
    }
}

void FirstAidPoint::prepareForInjuries()
{

    if (!isOperational)
    {
        std::cout << "First aid point is not operational..." << std::endl;
        return;
    }

    std::cout << "Preparing for injuries..... " << std::endl;
    checkSupplies();

    std::cout << "Checking staff..." << std::endl;
    if (!currentDoctor.empty())
    {
        std::cout << "The doctor, " << currentDoctor << " is available to treat patients!" << std::endl;
    }
    else
    {
        std::cout << "There is no doctor working currently!" << std::endl;
        return;
    }
    if (!medicalStaff.empty())
    {
        std::cout << "The staff, " << currentDoctor << " is available to treat patients!" << std::endl;
    }
    else
    {
        std::cout << "There is no staff working currently!" << std::endl;
        return;
    }
}

void FirstAidPoint::restockSupplies(int amount)
{
    if (amount <= 0)
    {
        std::cout << "You gotta be kidding me this is nothing!" << std::endl;
        return;
    }

    int oldLevel = suppliesLevel;
    suppliesLevel += amount;
    if (suppliesLevel > 100)
    {
        suppliesLevel = 100;
        std::cout << "Supplies restocked to maximum amount, yippee!" << std::endl;
    }
    else
    {
        std::cout << "Restocked supplies by " << amount << std::endl;
        std::cout << "You now have....." << suppliesLevel << " amount of supplies available to you" << std::endl;
    }
}

void FirstAidPoint::dispatchTeam(std::string location)
{
    if (!isOperational)
    {
        std::cout << "First aid point is not operational..." << std::endl;
        return;
    }

    if (medicalStaff.size() < 2)
    {
        std::cout << "Not enough medical staff to dispatch a team, we need at minimum 2" << std::endl;
        return;
    }

    activeIncidents.push_back(location);

    std::cout << "Active incident occuring!!" << std::endl;
    std::cout << "Location: " << location << std::endl;
}

void FirstAidPoint::changeDoctor(std::string newDoctor)
{

    bool found = false;
    for (const auto &staff : medicalStaff)
    {
        if (staff == newDoctor)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Doctor '" << newDoctor << "' is not in the medical staff list." << std::endl;
        std::cout << "Adding " << newDoctor << " to staff roster." << std::endl;
        medicalStaff.push_back(newDoctor);
    }

    std::cout << "Changing doctor from " << (currentDoctor.empty() ? "None" : currentDoctor)
              << " to " << newDoctor << std::endl;
    currentDoctor = newDoctor;
}

// observer
void FirstAidPoint::handleNotice(Notice *notice)
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
        assistEvacuation();
        close();
        break;
    case NoticeType::WeatherAlert:
        prepareForInjuries();
        std::cout << name << " is preparing for weather-related injuries" << std::endl;
        break;
    case NoticeType::ScheduleChange:
        if (notice->hasDetail("new_doctor"))
        {
            changeDoctor(notice->getDetail("new_doctor"));
        }
        break;
    case NoticeType::MedicalAlert:
    {
        std::string condition = notice->hasDetail("condition") ? notice->getDetail("condition") : "Unknown condition";
        std::string location = notice->hasDetail("location") ? notice->getDetail("location") : "Unknown location";

        std::cout << "" << name << " is responding to medical emergency!" << std::endl;
        std::cout << "    Condition: " << condition << std::endl;
        std::cout << "    Location: " << location << std::endl;

        if (location != "Unknown location")
        {
            dispatchTeam(location);
        }
        if (condition != "Unknown condition")
        {
            treatPatient(condition);
        }

        checkSupplies();
        break;
    }
    default:
        std::cout << name << " received unknown notice: " << notice->getMessage() << std::endl;
        break;
    }
}

// event component
void FirstAidPoint::open()
{
    isOperational = true;
    std::cout << "The doctor is in for service!!" << std::endl;
}

void FirstAidPoint::close()
{
    isOperational = false;
    std::cout << "The doctor is not in at the moment..." << std::endl;
}

void FirstAidPoint::reportStatus()
{
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Capacity: " << getCapacity() << " people" << std::endl;
    std::cout << "Is Operational: " << (isOperational ? "Yes" : "No") << std::endl;
    std::cout << "Current Doctor: " << (currentDoctor.empty() ? "None Assigned" : currentDoctor) << std::endl;
    std::cout << "Supplies Level: " << suppliesLevel << "%" << std::endl;
    std::cout << "Patients Treated: " << patientsTreated << std::endl;
    std::cout << "Is Evacuating: " << (isEvacuating ? "Yes" : "No") << std::endl;
    std::cout << "Medical Staff Count: " << medicalStaff.size() << std::endl;

    if (!medicalStaff.empty())
    {
        std::cout << "Medical Staff:" << std::endl;
        for (const auto &staff : medicalStaff)
        {
            std::cout << "  - " << staff;
            if (staff == currentDoctor)
            {
                std::cout << " Mr in charge";
            }
            std::cout << std::endl;
        }
    }

    if (!activeIncidents.empty())
    {
        std::cout << "Active Incidents:" << std::endl;
        for (const auto &incident : activeIncidents)
        {
            std::cout << "  - " << incident << std::endl;
        }
    }

    checkSupplies();
}

int FirstAidPoint::getCapacity()
{
    return this->EventUnit::getCapacity();
}