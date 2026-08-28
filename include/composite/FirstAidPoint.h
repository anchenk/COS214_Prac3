#ifndef FIRST_AID_POINT_H
#define FIRST_AID_POINT_H

#include "EventUnit.h"

class FirstAidPoint : public EventUnit {

private:
	std::vector<std::string> medicalStaff;
	int suppliesLevel;
	bool isOperational;
	int patientsTreated;
	std::string currentDoctor;
	std::vector<std::string> activeIncidents;
	bool isEvacuating;

public:
	FirstAidPoint(std::string name, int capacity);
	void treatPatient(std::string condition);
	void assistEvacuation();
	void checkSupplies();
	void prepareForInjuries();
	void restockSupplies(int amount);
	void dispatchTeam(std::string location);
	void changeDoctor(std::string newDoctor);

	//event unit
	void handleNotice(Notice *notice) override;
    // event component
    void open() override;
    void close() override;
    void reportStatus() override;
    int getCapacity() override;
};

#endif
