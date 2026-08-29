#ifndef PERFORMANCE_STAGE _H
#define PERFORMANCE_STAGE _H

#include "EventUnit.h"

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

	// event unit
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
	 */
	int getCapacity() override;
};

#endif
