// Librerie
#include <math.h>

// Funzioni da integrare
double f(double x)
{
	return cosh(x);
}

// Primitiva calcolata analiticamente
double primitive(double x)
{
	return sinh(x);
}
