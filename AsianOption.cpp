#include "AsianOption.h"

AsianOption::AsianOption(std::vector<double> times) : Option(times.back())
{
	_times = times;
}

std::vector<double> AsianOption::getTimeSteps()
{
	return _times;
}

double AsianOption::payoffPath(std::vector<double> prices)
{
	double sum = 0;
	int m = prices.size();
	for (int i = 0; i < m; i++)
	{
		sum = sum + 1 / double(m) * prices[i];
	}
	return payoff(sum);
}

bool AsianOption::isAsianOption()
{
	return true;
}