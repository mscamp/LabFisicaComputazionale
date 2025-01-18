// Librerie
#include <cmath>
#include <math.h>

// Metodo di Gauss
double f_gauss_hermite(double x)
{
	return 0.5 * pow(x, 14.0);
}

double f_gauss_laguerre(double x)
{
	return pow(x, 14.0) * exp(x - x * x);
}