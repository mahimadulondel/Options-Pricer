#include "CRRPricer.h"

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate):
	 _depth(depth), _asset_price(asset_price), _up(0), _down(0), _interest_rate(0)
{
	try
	{
		if (option->isAsianOption())
		{
			throw std::invalid_argument("Asian option is not handle by CRR Pricer");
		}

		_option = option;

		if (down < interest_rate && interest_rate < up)
		{
			_up = up;
			_down = down;
			_interest_rate = interest_rate;
		}

		_tree.setDepth(_depth);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what();
	}
}

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double r, double volatility) :
	_depth(depth), _asset_price(asset_price), _up(0), _down(0), _interest_rate(0)
{
	try
	{
		if (option->isAsianOption())
		{
			throw std::invalid_argument("Asian option is not handle by CRR Pricer");
		}

		_option = option;

		double expiry = _option->GetExpiry();
		double h = expiry / _depth;

		_up = std::exp((r + volatility * volatility / 2) * h + volatility * std::sqrt(h)) - 1;
		_down = std::exp((r + volatility * volatility / 2) * h - volatility * std::sqrt(h)) - 1;
		_interest_rate = std::exp(r * h) - 1;

		_tree.setDepth(_depth);

		if (_option->isAmericanOption())
		{
			_exercise_condition.setDepth(_depth);
		}
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what();
	}
}


void CRRPricer::compute()
{
	for (int n = 0; n < _depth; n++)
	{
		for (int i = 0; i <= n; i++)
		{
			double asset_price = _asset_price * puissance(1 + _up, i) * puissance(1 + _down, n - i);
			_tree.setNode(n, i, asset_price);
		}
	}
}

BinaryTree<double> CRRPricer::getTree()
{
	return _tree;
}

double CRRPricer::get(int n, int i)
{
	BinaryTree<double> _option_price_tree;
	_option_price_tree.setDepth(_depth);

	bool american = _option->isAmericanOption();

	double q = (_interest_rate - _down) / (_up - _down);
	for (int i = 0; i < _depth; i++)
	{
		_option_price_tree.setNode(_depth - 1, i, _option->payoff(_tree.getNode(_depth - 1, i)));

		if (american == true)
		{
			_exercise_condition.setNode(_depth - 1, i, true);
		}
	}
	for (int n = _depth - 2; n >= 0; n--)
	{
		for (int i = 0; i <= n; i++)
		{
			double option_price = (q * _option_price_tree.getNode(n + 1, i + 1) + (1 - q) * _option_price_tree.getNode(n + 1, i)) / (1 + _interest_rate);

			if (american == true)
			{
				double intrinsic_value = _option->payoff(_tree.getNode(n, i));
				if (option_price <= intrinsic_value)
				{
					_option_price_tree.setNode(n, i, intrinsic_value);
					_exercise_condition.setNode(n, i, true);
				}
				else
				{
					_option_price_tree.setNode(n, i, option_price);
					_exercise_condition.setNode(n, i, false);
				}
			}
			else
			{
				_option_price_tree.setNode(n, i, option_price);
			}

			
		}
	}

	return _option_price_tree.getNode(n, i);
}


double CRRPricer::operator()(bool closed_form)
{
	compute();

	if (closed_form == false)
	{
		return get(0, 0);
	}
	else
	{
		double q = (_interest_rate - _down) / (_up - _down);
		double somme = 0;
		double binome = 1;
		for (int j = 0; j < _depth; j++)
		{
			somme += binome * puissance(q, j) * puissance(1 - q, double(_depth) - 1 - j) * get(_depth - 1, j);
			binome = binome * (double(_depth) - 1 - j) / (double(j) + 1);
		}
		return somme / puissance(1 + _interest_rate, double(_depth) - 1);
	}
}

bool CRRPricer::getExercise(int n, int i)
{
	return _exercise_condition.getNode(n, i);
}


int factorielle(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * factorielle(n - 1);
	}
}

double puissance(double nombre, double exposant)
{
	double produit = 1;
	for (int i = 0; i < exposant; i++)
	{
		produit = produit * nombre;
	}
	return produit;
}