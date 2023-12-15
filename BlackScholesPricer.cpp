#include "BlackScholesPricer.h"

BlackScholesPricer::BlackScholesPricer(VanillaOption* option_v, double asset_price, double interest_rate, double volatility) :
	_option_v(option_v), _asset_price(asset_price), _interest_rate(interest_rate), _volatility(volatility) 
{
	_option_d = NULL;
}

BlackScholesPricer::BlackScholesPricer(DigitalOption* option_d, double asset_price, double interest_rate, double volatility) :
	_option_d(option_d), _asset_price(asset_price), _interest_rate(interest_rate), _volatility(volatility)
{
	_option_v = NULL;
}

double BlackScholesPricer::operator()()
{

	if (_option_v != NULL)
	{
		double _maturity = _option_v->GetExpiry();
		double _strike = _option_v->_strike;
		double d1 = 1 / (_volatility * std::sqrt(_maturity)) * (std::log(_asset_price / _strike) + (_interest_rate + _volatility * _volatility / 2) * _maturity);
		double d2 = d1 - _volatility * std::sqrt(_maturity);

		if ((*_option_v).GetOptionType() == OptionType::Call)
		{
			return _asset_price * normalCDF(d1) - _strike * std::exp(-_interest_rate * _maturity) * normalCDF(d2);
		}
		else if ((*_option_v).GetOptionType() == OptionType::Put)
		{
			return -_asset_price * normalCDF(-d1) + _strike * std::exp(-_interest_rate * _maturity) * normalCDF(-d2);
		}
	}
	else if(_option_d != NULL)
	{
		double _maturity = _option_d->GetExpiry();
		double _strike = _option_d->_strike;
		double d1 = 1 / (_volatility * std::sqrt(_maturity)) * (std::log(_asset_price / _strike) + (_interest_rate + _volatility * _volatility / 2) * _maturity);
		double d2 = d1 - _volatility * std::sqrt(_maturity);

		if ((*_option_d).GetOptionType() == OptionType::Digital_Call)
		{
			return std::exp(-_interest_rate * _maturity) * normalCDF(d2);
		}
		else if ((*_option_d).GetOptionType() == OptionType::Digital_Put)
		{
			return std::exp(-_interest_rate * _maturity) * normalCDF(-d2);
		}
	}

}

double BlackScholesPricer::delta()
{
	if (_option_v != NULL)
	{
		double _maturity = _option_v->GetExpiry();
		double _strike = _option_v->_strike;
		double d1 = 1 / (_volatility * std::sqrt(_maturity)) * (std::log(_asset_price / _strike) + (_interest_rate + _volatility * _volatility / 2) * _maturity);
		double d2 = d1 - _volatility * std::sqrt(_maturity);

		if ((*_option_v).GetOptionType() == OptionType::Call)
		{
			return normalCDF(d1);
		}
		else if ((*_option_v).GetOptionType() == OptionType::Put)
		{
			return normalCDF(d1) - 1;
		}
	}
	else if (_option_d != NULL)
	{
		double _maturity = _option_d->GetExpiry();
		double _strike = _option_d->_strike;
		double d1 = 1 / (_volatility * std::sqrt(_maturity)) * (std::log(_asset_price / _strike) + (_interest_rate + _volatility * _volatility / 2) * _maturity);
		double d2 = d1 - _volatility * std::sqrt(_maturity);

		if ((*_option_d).GetOptionType() == OptionType::Digital_Call)
		{
			return std::exp(-_interest_rate * _maturity) * normalPDF(d2) / (_asset_price * _volatility * std::sqrt(_maturity));
		}
		else if ((*_option_d).GetOptionType() == OptionType::Digital_Put)
		{
			return - std::exp(-_interest_rate * _maturity) * normalPDF(-d2) / (_asset_price * _volatility * std::sqrt(_maturity));
		}
	}

	
}


double normalPDF(double x)
{
	return 1 / std::sqrt(2 * M_PI) * std::exp(-x * x / 2);
}

double normalCDF(double x)
{
	return std::erfc(-x / std::sqrt(2)) / 2;
}