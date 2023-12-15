#pragma once
#include "DigitalOption.h"

class DigitalPutOption : public DigitalOption
{
public:
	DigitalPutOption(double expiry, double strike);
	double payoff(double asset_price);
	OptionType GetOptionType();
};

