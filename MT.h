#pragma once
#include <random>


class MT
{
private:
	MT();
	~MT();
	std::mt19937 generator;
	static MT instance;

public:
	MT(const MT&) = delete;
	static double rand_unif();
	static double rand_norm();
};

