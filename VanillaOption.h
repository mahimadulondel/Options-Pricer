#pragma once
#include <iostream>
#include "Option.h"
#include "OptionType.h"

class VanillaOption : public Option
{
private:
	double _strike;
public:
	VanillaOption(double expiry, double strike);
	virtual OptionType GetOptionType() = 0;
	double GetStrike();
	friend class BlackScholesPricer;
};



