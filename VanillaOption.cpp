#include "VanillaOption.h"

VanillaOption::VanillaOption(double expiry, double strike) : Option(expiry)
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

double VanillaOption::GetStrike()
{
	return _strike;
}
