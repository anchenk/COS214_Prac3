#ifndef FOOD_STATION _H
#define FOOD_STATION _H

#include "EventUnit.h"

/**
 * @brief Concrete Leaf - Food preparation and tasting station.
 * 
 * Represents a food station in the bazaar that serves prepared food.
 * Reacts to weather alerts, evacuation, and shift changes.
 */
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

	/**
	 *  @brief Handle a received notice from the Subject.
	 *
	 * Reacts to different notice types:
	 * - Open: Opens the station
	 * - Close: Closes the station
	 * - WeatherAlert: Remains open
	 * - Evacuate: Closes station
	 * - ScheduleChange: Changes chef (if "new_chef" detail exists)
	 * - MedicalAlert: Closes station (if serving)
	 *
	 * @param notice The notice to handle
	 */
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
	 * @brief a general overview of the food station
	 */
	void reportStatus() override;

	/**
	 * @brief get the capacity of the food station from the base station
	 * @return the capacity of the food station
	 */
	int getCapacity() override;
};

#endif
