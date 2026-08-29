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
	/**
	 * @brief Create foodstation object
	 *
	 * @param name of the foodstation
	 * @param capacity of the foodstation
	 * @param cuisineType of the foodstation
	 */
	FoodStation(std::string name, int capacity, std::string cuisineType);

	/**
	 * @brief indicate that food is beind prepped, in context of availability of everything involved
	 */
	void prepareFood();

	/**
	 * @brief check that there exists something in inventory and list it's name and amount
	 */
	void checkInventory();

	/**
	 * @brief will increase the amount of a certain item with a certain amount
	 *
	 * @param item who's stock numnber will be increased
	 * @param amount with which the certain item will increase
	 */
	void restock(std::string item, int amount);

	/**
	 * @brief the currentChef will be changed
	 *
	 * @param newChef to which currentChef is being changed
	 */
	void changeChef(std::string newChef);

	// event unit
	void handleNotice(Notice *notice) override;
	// event component

	/**
	 * @brief open up the stall by changing the isServing description to true
	 */
	void open() override;

	/**
	 * @brief close up the stall by changing the isServing description to false
	 */
	void close() override;

	/** 
	 * @brief a general overview of the foodstation 
	 */
	void reportStatus() override;

	/** 
	 * @brief get the capacity of the food station from the base station
	 */
	int getCapacity() override;
};

#endif
