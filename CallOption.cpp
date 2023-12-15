#include "CallOption.h"

CallOption::CallOption(double expiry, double strike) : VanillaOption(expiry, strike) {}

double CallOption::payoff(double asset_price)
{
	if (asset_price >= GetStrike())
	{
		return asset_price - GetStrike();
	}
	return 0;
}

OptionType CallOption::GetOptionType()
{
	return OptionType::Call;
}

