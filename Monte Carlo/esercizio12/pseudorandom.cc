// Librerie
#include <stdlib.h>
#include <math.h>
#include <numbers>

double rand_range(double min, double max)
{
	return min + (max - min) * (rand() / static_cast<double>(RAND_MAX));
}

double metodo_esatto()
{
	// Dichiarazione variabili
	double r = sqrt(-log(rand_range(0.0, 1.0)));
	double alpha = rand_range(0.0, 1.0);

	return r * cos(2 * std::numbers::pi_v<double> * alpha);
}

double accept_reject(double f(double x), double h(double x), double cdf_inv(double x), double C)
{
	// Dichiarazione variabili
	double t = 0.0;
	double u = 0.0;

	do	
	{
		t = cdf_inv(rand_range(0.0, 1.0));
		u = rand_range(0.0, 1.0);

	}while((f(t) / (C * h(t))) < u);

	return t;
}
