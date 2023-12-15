#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "VanillaOption.h"
#include "DigitalOption.h"

class BlackScholesPricer
{
private:
	VanillaOption* _option_v;
	DigitalOption* _option_d;
	double _asset_price;
	double _interest_rate;
	double _volatility;
public:
	BlackScholesPricer(VanillaOption* option_v, double asset_price, double interest_rate, double volatility);
	BlackScholesPricer(DigitalOption* option_d, double asset_price, double interest_rate, double volatility);
	double operator()();
	double delta();
};

double normalPDF(double x);
double normalCDF(double x);

