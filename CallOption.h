#pragma once
#include "VanillaOption.h"

class CallOption : public VanillaOption
{
public:
	CallOption(double expiry, double strike);
	double payoff(double asset_price);
	OptionType GetOptionType();
};

