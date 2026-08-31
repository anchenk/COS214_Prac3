#ifndef PERFORMANCE_STAGE _H
#define PERFORMANCE_STAGE _H

#include "EventUnit.h"
/**
 * @brief Concrete Leaf - Performance stage for live entertainment.
 * 
 * Represents a stage where performances are held. Reacts to weather
 * alerts by pausing performances, schedule changes, and medical alerts.
 * @author Caleb Jennings - u25173805, Anchen Kruger - u25073703, Chloe Larsen - u25004141
 */
class PerformanceStage : public EventUnit
{
private:
	std::vector<std::string> schedule;
	std::string currentPerformance;
	bool isPerforming;
	bool isOpen;
	std::string currentStageManager;

public:
	/**
	 * @brief The constructor for the Performance stage object
	 *
	 * @param name of the performance
	 * @param capacity of the performance
	 */
	PerformanceStage(std::string name, int capacity);

	/**
	 * @brief Starting the performance based on certain conditions
	 *
	 * @param show the current show that wants to start
	 */
	void startPerformance(std::string show);

	/**
	 * @brief pausing the performance it has not completed yet
	 */
	void pausePerformance();

	/**
	 * @brief change the current manager to another manager
	 *
	 * @param newManager the manager that will be changed to be the current manager
	 */
	void changeStageManager(std::string newManager);

	/**
     * @brief Handle a received notice from the Subject.
     * 
     * Reacts to different notice types:
     * - Open: Opens the stage
     * - Close: Pauses performance and closes stage
     * - WeatherAlert: Pauses performance
     * - Evacuate: Pauses performance and closes
     * - ScheduleChange: Changes stage manager (if "new_manager" detail exists)
     * - MedicalAlert: Pauses performance
     * 
     * @param notice The notice to handle
     */
	void handleNotice(Notice *notice) override;
	// event component

	/**
	 * @brief Open up the stage to be performed on
	 */
	void open() override;

	/**
	 * @brief Close the stage as there can no longer be performed on
	 */
	void close() override;

	/**
	 * @brief General overview of the performance
	 */
	void reportStatus() override;

	/** 
	 * @brief the capacity that the performance is able to take
	 * @return the capacity value of the performance stage
	 */
	int getCapacity() override;
};

#endif
