#include "DigitalPutOption.h"

DigitalPutOption::DigitalPutOption(double expiry, double strike) : DigitalOption(expiry, strike) {}

double DigitalPutOption::payoff(double asset_price)
{
	if (asset_price <= GetStrike())
	{
		return 1;
	}
	return 0;
}

OptionType DigitalPutOption::GetOptionType()
{
	return OptionType::Digital_Put;
}
