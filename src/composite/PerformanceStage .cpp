#include "../../include/composite/PerformanceStage.h"

PerformanceStage::PerformanceStage(std::string name, int capacity) : EventUnit(name, true, capacity), currentPerformance(""), isPerforming(false), currentStageManager("")
{
}

void PerformanceStage::startPerformance(std::string show)
{
    if (currentStageManager == "")
    {
        std::cout << "No manager, no performance!" << std::endl;
    }
    if (isOpen == false)
    {
        std::cout << "Can't start a performance now this is closed!!" << std::endl;
        return;
    }
    if (isPerforming == true)
    {
        std::cout << "Someone is already perfomring!" << std::endl;
        return;
    }

    bool found = false;
    for (const auto &s : schedule)
    {
        if (s == show)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Show '" << show << "' is not in the schedule." << std::endl;
        return;
    }

    currentPerformance = show;
    isPerforming = true;
    std::cout << "Performance '" << show << "' started with Stage Manager " << currentStageManager << std::endl;
}

void PerformanceStage::pausePerformance()
{
    if (!isPerforming)
    {
        std::cout << "Crickets.... there is no performance at the moment" << std::endl;
        return;
    }
    std::cout << "Stop the " << name << "performance... for now!!" << std::endl;
    isPerforming = false;
}

void PerformanceStage::changeStageManager(std::string newManager)
{
    if (isPerforming)
    {
        std::cout << "Hold your horses, wait for the performance to stop or pause it before you switch out a manager." << std::endl;
        return;
    }

    std::cout << "Bye bye, " << currentStageManager << " helloooo " << newManager << std::endl;
    currentStageManager = newManager;
}

// observer
void PerformanceStage::handleNotice(Notice *notice)
{
}

// event component
void PerformanceStage::open()
{
    std::cout << "Now opening........" << name << ", everyone celebrate!" << std::endl;
    isOpen = true;
}

void PerformanceStage::close()
{
    std::cout << "Now closing " << name << ", everyone say goodbye!!" << std::endl;
    isOpen = false;
}

void PerformanceStage::reportStatus()
{
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Capacity: " << getCapacity() << " people" << std::endl;
    std::cout << "Is Performing: " << (isPerforming ? "Yes" : "No") << std::endl;
    std::cout << "Current Performance: " << (currentPerformance.empty() ? "None" : currentPerformance) << std::endl;
    std::cout << "Stage Manager: " << (currentStageManager.empty() ? "None Assigned" : currentStageManager) << std::endl;
    std::cout << "Schedule Count: " << schedule.size() << std::endl;

    if (!schedule.empty())
    {
        std::cout << "Schedule:" << std::endl;
        for (const auto &show : schedule)
        {
            std::cout << "  - " << show;
            if (!currentPerformance.empty() && currentPerformance == show && isPerforming)
            {
                std::cout << " [Performing]";
            }
            else if (!currentPerformance.empty() && currentPerformance == show && !isPerforming)
            {
                std::cout << " [Paused]";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "  No shows scheduled." << std::endl;
    }

    std::cout << "Location: " << (getIsOutdoor() ? "Outdoor" : "Indoor") << std::endl;
}

int PerformanceStage::getCapacity()
{
    return EventUnit::getCapacity();
}