#include "AsianPutOption.h"

AsianPutOption::AsianPutOption(std::vector<double> times, double strike) : AsianOption(times)
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

double AsianPutOption::payoff(double payoff_path)
{
	if (payoff_path <= _strike)
	{
		return _strike - payoff_path;
	}
	return 0;

}