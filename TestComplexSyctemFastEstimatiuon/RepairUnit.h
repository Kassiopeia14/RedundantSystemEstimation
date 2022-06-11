#pragma once

class RepairUnit
{
private:

	bool isWorking;
	int type_;
	double repairTime_;

public:
	RepairUnit();
	~RepairUnit();

	double getTime();
	int getType();
	void reset();
	void reset(const int type, const double repairTime);
	bool working();

};

