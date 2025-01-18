// Librerie
#include <cmath>
#include <math.h>

// Funzioni da integrare
double f_integrand(double x)
{
	return cosh(x);
}

// Metodo di Gauss
double f_gauss_legendre(double x)
{
	return (5.0 / 4.0) * (exp(2.5 * x + 5.5) + exp((-1.0) * 2.5 * x - 5.5));
}

double f_gauss_laguerre(double x)
{
	return 0.5 * (exp(8.0) - exp(3.0) + exp(-3.0) - exp(-8.0));
}

// Primitiva calcolata analiticamente
double primitive(double x)
{
	return sinh(x);
}