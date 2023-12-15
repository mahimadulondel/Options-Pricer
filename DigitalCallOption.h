#pragma once
#include "DigitalOption.h"

class DigitalCallOption : public DigitalOption
{
public:
	DigitalCallOption(double expiry, double strike);
	double payoff(double asset_price);
	OptionType GetOptionType();
};

