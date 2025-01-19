// Librerie
#include <math.h>

// Funzioni da integrare
double f(double x)
{
	return (x * x) + x * (sin(4.0 * x));
}

// Primitiva calcolata analiticamente
double primitive(double x)
{
	return (1.0/48.0) * (16.0 * (x * x * x) + 3.0 * sin(4.0*x) - (12.0 * x * cos(4.0 * x)));
}
