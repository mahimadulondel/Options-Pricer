#include "BlackScholesMCPricer.h"

BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility) :
	_option(option), _initial_price(initial_price), _interest_rate(interest_rate), _volatility(volatility), _nb_paths(0), _estimation_price(0) {}

int BlackScholesMCPricer::getNbPaths()
{
	return _nb_paths;
}

void BlackScholesMCPricer::generate(int nb_paths)
{
	int m = 0;
	double t_1;
	if (_option->isAsianOption() == false)
	{
		m = 1;
		t_1 = _option->GetExpiry();
	}
	else
	{
		m = ((AsianOption*)_option)->getTimeSteps().size();
		t_1 = ((AsianOption*)_option)->getTimeSteps()[0];
	}

	std::vector<std::vector<double>> prices;
	prices.resize(nb_paths);

	for (int i = 0; i < nb_paths; i++)
	{
		prices[i].resize(m);

		prices[i][0] = _initial_price * exp((_interest_rate - _volatility * _volatility / 2) * t_1 + _volatility * sqrt(t_1) * MT::rand_norm());
		double pric = prices[i][0];
		if (m > 1)
		{
			std::vector<double> times = ((AsianOption*)_option)->getTimeSteps();
			for (int j = 1; j < m; j++)
			{
				prices[i][j] = prices[i][j - 1] * exp((_interest_rate - _volatility * _volatility / 2) * (times[j] - times[j - 1]) + _volatility * sqrt(times[j] - times[j - 1]) * MT::rand_norm());
			}
		}
	}

	double new_estimation = 0;
	double maturity = _option->GetExpiry();
	for (int k = 0; k < nb_paths; k++)
	{
		double payoff = _option->payoffPath(prices[k]);

		new_estimation += exp(-_interest_rate * maturity) * 1 / double(nb_paths) * payoff;

		_sum += exp(-_interest_rate * maturity) * payoff;
		_sum_squared += pow(exp(-_interest_rate * maturity) * payoff, 2);
	}

	_estimation_price = (_estimation_price * _nb_paths + new_estimation * nb_paths) / double(_nb_paths + nb_paths);

	_nb_paths += nb_paths;
}

double BlackScholesMCPricer::operator()()
{
	try
	{
		if (_nb_paths == 0)
		{
			throw std::string("There is no estimation at the moment, please use the method 'generate'");
		}
		
		return _estimation_price;
	}
	catch(const std::string& e)
	{
		std::cerr << e << std::endl;
	}
}

std::vector<double> BlackScholesMCPricer::confidenceInterval()
{
	double sd = sqrt(1 / double(_nb_paths) * _sum_squared - pow(1 / double(_nb_paths) * _sum, 2));

	std::vector<double> bounds;
	bounds.push_back(_estimation_price - 1.96 * sd / sqrt(_nb_paths));
	bounds.push_back(_estimation_price + 1.96 * sd / sqrt(_nb_paths));

	return bounds;
}
