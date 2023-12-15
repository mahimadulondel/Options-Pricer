#include "MT.h"

MT MT::instance;

MT::MT() : generator(std::random_device()()) {}

double MT::rand_unif()
{
	std::uniform_real_distribution<double> unif_distr(0.0, 1.0);
	return unif_distr(instance.generator);
}

double MT::rand_norm()
{
	std::normal_distribution<double> norm_distr(0.0, 1.0);
	return norm_distr(instance.generator);
}



MT::~MT() {}