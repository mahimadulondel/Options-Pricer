#include "Option.h"

Option::Option(double expiry)
{
	if (expiry >= 0)
	{
		_expiry = expiry;
	}
	else
	{
		expiry = 0;
	}
}

double Option::GetExpiry()
{
	return _expiry;
}

double Option::payoffPath(std::vector<double> prices)
{
	return payoff(prices.back());
}

bool Option::isAsianOption()
{
	return false;
}


bool Option::isAmericanOption()
{
	return false;
}