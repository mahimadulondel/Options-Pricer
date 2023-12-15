#include "PutOption.h"

PutOption::PutOption(double expiry, double strike) : VanillaOption(expiry, strike) {}

double PutOption::payoff(double asset_price)
{
	if (asset_price <= GetStrike())
	{
		return GetStrike() - asset_price;
	}
	return 0;
}

OptionType PutOption::GetOptionType()
{
	return OptionType::Put;
}