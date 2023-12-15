#pragma once
#include <iostream>
#include <vector>

class Option
{
private:
	double _expiry;
public:
	virtual double payoff(double) = 0;
	Option(double expiry);
	double GetExpiry();

	virtual double payoffPath(std::vector<double> prices);
	virtual bool isAsianOption();

	virtual bool isAmericanOption();
};
