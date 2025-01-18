// Librerie
#include <math.h>

// Funzioni da integrare
double f_integrand(double x)
{
	return 0.5 * pow(log(1.0 / x), 2.0);
}

// Metodo di Gauss
double f_gauss_hermite(double x)
{
	return 0.5 * exp(-9.0) * pow((fabs(x) + 3.0), 5.0) * exp(-6.0 * fabs(x));
}

double f_gauss_laguerre(double x)
{
	return exp(-9.0) * pow((x + 3.0), 5.0) * exp((-1.0) * (x * x + 5 * x));
}