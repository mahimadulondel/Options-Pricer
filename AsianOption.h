#pragma once
#include "Option.h"

class AsianOption : public Option
{
private:
	std::vector<double> _times;
public:
	AsianOption(std::vector<double> times);
	std::vector<double> getTimeSteps();
	double payoffPath(std::vector<double> prices);
	bool isAsianOption();
};

