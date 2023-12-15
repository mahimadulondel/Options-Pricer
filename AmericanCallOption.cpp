#include "AmericanCallOption.h"

AmericanCallOption::AmericanCallOption(double expiry, double strike) : AmericanOption(expiry, strike) {}

double AmericanCallOption::payoff(double asset_price)
{
	if (asset_price >= GetStrike())
	{
		return asset_price - GetStrike();
	}
	return 0;
}