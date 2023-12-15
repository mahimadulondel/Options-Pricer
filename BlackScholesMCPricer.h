#pragma once
#include "Option.h"
#include "AsianOption.h"
#include "MT.h"


class BlackScholesMCPricer
{
private:
	int _nb_paths;
	double _estimation_price;

	Option* _option;
	double _initial_price;
	double _interest_rate;
	double _volatility;

	double _sum;
	double _sum_squared;
public:
	BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility);
	int getNbPaths();
	void generate(int nb_paths);
	double operator()();
	std::vector<double> confidenceInterval();
};

