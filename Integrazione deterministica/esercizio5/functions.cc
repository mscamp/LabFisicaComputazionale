// Librerie
#include <math.h>

// Funzioni da integrare
double f_integrand(double x)
{
	return (x * x + x * sin(4.0 * x));
}

// Metodo di Gauss
double f_gauss_legendre(double x)
{
	return 4.5 * ((81.0 / 4.0) * pow((x + 1.0), 2.0) + 1.0 - 9.0 * (x + 1.0) + (4.5 * x + 3.5) * sin(18.0 * x + 14));
}

// Primitiva calcolata analiticamente
double primitive(double x)
{
	return (1.0 / 48.0) * (16.0 * pow(x, 3.0) + 3.0 * sin(4.0 * x) - 12.0 * x * cos(4.0 * x));
}