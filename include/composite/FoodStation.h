#ifndef FOOD_STATION _H
#define FOOD_STATION _H

#include "EventUnit.h"

class FoodStation : public EventUnit
{
private:
	std::map<std::string, int> inventory;
	std::string cuisineType;
	bool isServing;
	std::string currentChef;

public:
	FoodStation(std::string name, int capacity, std::string cuisineType);
	void prepareFood();
	void checkInventory();
	void restock(std::string item, int amount);
	void changeChef(std::string newChef);

	// event unit
	void handleNotice(Notice *notice) override;
	// event component
	void open() override;
	void close() override;
	void reportStatus() override;
	int getCapacity() override;
};

#endif
