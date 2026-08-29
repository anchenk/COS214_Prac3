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
    else
    {
        isPerforming = true;
        return;
    }
}

void PerformanceStage::pausePerformance()
{
    if (!isPerforming)
    {
        std::cout << "Crickets.... there is no performance at the moment" << std::endl;
        return;
    }
    std::cout << "Stop the " << name << "performance!! I object!" << std::endl;
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

    isOpen = false;
}

void PerformanceStage::reportStatus()
{
}

int PerformanceStage::getCapacity()
{
    return EventUnit::getCapacity();
}