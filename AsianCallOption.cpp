#include "AsianCallOption.h"

AsianCallOption::AsianCallOption(std::vector<double> times, double strike) : AsianOption(times)
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

double AsianCallOption::payoff(double payoff_path)
{
	if (payoff_path >= _strike)
	{
		return payoff_path - _strike;
	}
	return 0;
	
}