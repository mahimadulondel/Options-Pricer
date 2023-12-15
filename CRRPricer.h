#pragma once
#include <iostream>
#include "Option.h"
#include "BinaryTree.h"
#include "AsianOption.h"

class CRRPricer
{
private:
	Option* _option;
	int _depth;
	double _asset_price;
	double _up;
	double _down;
	double _interest_rate;
	BinaryTree<double> _tree;
	BinaryTree<bool> _exercise_condition;

public:
	CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
	CRRPricer(Option* option, int depth, double asset_price, double r, double volatility);
	void compute();
	BinaryTree<double> getTree();
	double get(int n, int i);
	double operator()(bool closed_form = false);

	bool getExercise(int n, int i);
};

int factorielle(int n);
double puissance(double nombre, double exposant);