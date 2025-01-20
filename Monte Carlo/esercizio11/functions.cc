// Librerie
#include <math.h>

// Inversa della cdf di e^(-x) in (0,2)
double cdf_inversa_1(double y)
{
	return -log(1.0 - y * (1.0 - exp(-2.0)));
}

// Inversa della cdf di e^(-x) in (1,+inf)
double cdf_inversa_2(double y)
{
	return 1.0 - log(1.0 - y);
}

// Inversa della cdf di x*e^(-x^2) in (0,+inf)
double cdf_inversa_3(double y)
{
	return sqrt(-log(1.0 - y));
}