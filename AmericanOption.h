#pragma once
#include "Option.h"

class AmericanOption : public Option
{
private:
	double _strike;

public:
	AmericanOption(double expiry, double strike);
	double GetStrike();
	bool isAmericanOption();
};

