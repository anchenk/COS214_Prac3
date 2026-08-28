#ifndef PERFORMANCE_STAGE _H
#define PERFORMANCE_STAGE _H

#include "EventUnit.h"

class PerformanceStage : public EventUnit
{
private:
	std::vector<std::string> schedule;
	std::string currentPerformance;
	bool isPerforming;
	std::string currentStageManager;

public:
	PerformanceStage(std::string name, int capacity);
	void startPerformance(std::string show);
	void pausePerformance();
	void changeStageManager(std::string newManager);

	// event unit
	void handleNotice(Notice *notice) override;
	// event component
	void open() override;
	void close() override;
	void reportStatus() override;
	int getCapacity() override;
};

#endif
