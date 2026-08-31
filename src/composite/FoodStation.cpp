#include "../../include/composite/FoodStation.h"

FoodStation::FoodStation(std::string name, int capacity, std::string cuisineType) : EventUnit(name, false, capacity), cuisineType(cuisineType), isServing(false), currentChef("")
{
}

void FoodStation::prepareFood()
{
    if (!isServing)
    {
        std::cout << "Sorry no can do, we aren't serving at the moment..." << std::endl;
        return;
    }

    if (currentChef.empty())
    {
        std::cout << "Sorry... the chef is absent at the moment." << std::endl;
        return;
    }

    if (inventory.empty())
    {
        std::cout << "Oh no!! No more ingredients! Come back later!" << std::endl;
        return;
    }

    std::cout << "Preparing your meal now!" << std::endl;
}

void FoodStation::checkInventory()
{

    if (inventory.empty())
    {
        std::cout << "There is nothing in the inventory!!" << std::endl;
        return;
    }
    else
    {
        for (const auto &item : inventory)
        {
            std::cout << "  - " << item.first << ": " << item.second << " units";
            if (item.second < 10)
            {
                std::cout << " (LOW STOCK!)";
            }
            std::cout << std::endl;
        }
    }
}

void FoodStation::restock(std::string item, int amount)
{
    if (amount >= 1)
    {
        auto it = inventory.find(item);
        if (it != inventory.end())
        {
            it->second += amount;
        }
        else
        {
            inventory[item] = amount;
        }
        std::cout << "Added " << amount << "of " << item << std::endl;
        return;
    }
    std::cout << "Oops entered a wrong amount of your item" << std::endl;
}

void FoodStation::changeChef(std::string newChef)
{
    if (currentChef != "")
    {
        std::cout << "Our friend, " << currentChef << " has to leave unfortunately. However do not fear! " << newChef << " will be taking over" << std::endl;
        currentChef = newChef;
        return;
    }
    else
    {
        std::cout << "Please welcome our chef " << newChef << std::endl;
    }
}

// observer
void FoodStation::handleNotice(Notice *notice)
{
    if (!notice)
        return;

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
        std::cout << "EVERYBODY RUN! " << name << " has evacuated" << std::endl;
        break;
    case NoticeType::WeatherAlert:
        std::cout << "Incoming weather! " << name << " is indoor, safe to continue operating." << std::endl;
        break;
    case NoticeType::ScheduleChange:
        if (notice->hasDetail("new_chef"))
        {
            changeChef(notice->getDetail("new_chef"));
        }
        break;
    case NoticeType::MedicalAlert:
        if (isServing)
        {
            close();
            std::cout << "No more food for now. " << name << " is closed for medical emergency" << std::endl;
        }
        break;
    default:
        std::cout << name << " received unknown notice: " << notice->getMessage() << std::endl;
        break;
    }
}

// event component
void FoodStation::open()
{
    isServing = true;
    std::cout << name << " is now open and serving delicious " << cuisineType << std::endl;
}

void FoodStation::close()
{
    isServing = false;
    std::cout << name << " whomp whomp is now closed... " << cuisineType << std::endl;
}

void FoodStation::reportStatus()
{
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Cuisine Type: " << cuisineType << std::endl;
    std::cout << "Capacity: " << getCapacity() << " people" << std::endl;
    std::cout << "Is Serving: " << (isServing ? "Yes" : "No") << std::endl;
    std::cout << "Current Chef: " << (currentChef.empty() ? "None Assigned" : currentChef) << std::endl;
    std::cout << "Inventory Items: " << inventory.size() << std::endl;
    checkInventory();
    std::cout << "Location: " << (getIsOutdoor() ? "Outdoor" : "Indoor") << std::endl;
}

int FoodStation::getCapacity()
{
    return EventUnit::getCapacity();
}
