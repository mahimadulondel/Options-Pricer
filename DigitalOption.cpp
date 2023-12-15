#include "DigitalOption.h"

DigitalOption::DigitalOption(double expiry, double strike) : Option(expiry)
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

double DigitalOption::GetStrike()
{
	return _strike;
}
