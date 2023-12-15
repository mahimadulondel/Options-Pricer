#include "DigitalCallOption.h"

DigitalCallOption::DigitalCallOption(double expiry, double strike) : DigitalOption(expiry, strike) {}

double DigitalCallOption::payoff(double asset_price)
{
	if (asset_price >= GetStrike())
	{
		return 1;
	}
	return 0;
}

OptionType DigitalCallOption::GetOptionType()
{
	return OptionType::Digital_Call;
}