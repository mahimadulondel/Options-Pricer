#include "AmericanPutOption.h"

AmericanPutOption::AmericanPutOption(double expiry, double strike) : AmericanOption(expiry, strike) {}

double AmericanPutOption::payoff(double asset_price)
{
	if (asset_price <= GetStrike())
	{
		return GetStrike() - asset_price;
	}
	return 0;
}