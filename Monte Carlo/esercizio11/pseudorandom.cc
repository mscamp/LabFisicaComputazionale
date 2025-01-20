// Librerie
#include <stdlib.h>

double rand_range(double min, double max)
{
	return min + (max - min) * (rand() / static_cast<double>(RAND_MAX));
}

// F è l'inversa della CDF
double funzione_inversa(double F(double x))
{
	return F(rand_range(0.0, 1.0));
}