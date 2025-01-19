// Librerie
#include <math.h>

// Funzioni da integrare
double f(double x)
{
	return pow(x, 7.0) * exp(-x);
}

// Primitiva calcolata analiticamente
double primitive(double x)
{
	return (-1.0) * exp(-x) * (pow(x, 7.0) + 7.0 * pow(x, 6.0) + 42.0 * pow(x, 5.0) + 210.0 * pow(x, 4.0) + 840.0 * pow(x, 3.0) + 2520.0 * pow(x, 2.0) + 5040.0 * x + 5040.0);
}