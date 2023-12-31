#include "AmericanOption.h"

AmericanOption::AmericanOption(double expiry, double strike) : Option(expiry)
{
	if (strike >= 0)
	{
		_strike = strike;
	}
	else
	{
		_strike = 0;
	}
}

double AmericanOption::GetStrike()
{
	return _strike;
}

bool AmericanOption::isAmericanOption()
{
	return true;
}