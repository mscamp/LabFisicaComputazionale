// Librerie
#include <math.h>
#include <numbers>

// Distribuzione da campionare
double f(double x)
{
	return (1.0 / sqrt(std::numbers::pi_v<double>)) * exp((-1.0) * x * x);
}

// PDF ricavata simmetrizzando g e imponendo la normalizzazione
double h_norm(double x)
{
	if(x >= -1.0 && x <= 1.0)
	{
		return (1.0 / 3.0);
	}

	else if(x > 1.0)
	{
		return (1.0 / 3.0) * x * exp(1 - x * x);
	}

	else
	{
		return ((-1.0) / 3.0) * x * exp(1 - x * x);
	}
}

// Inversa della CDF di h
double h_cdf_inversa(double x)
{
	if(x >= 0.0 && x < (1.0 / 6.0))
	{
		return (-1.0) * sqrt(1.0 - log(6.0 * x));
	}

	else if(x >= (1.0 / 6.0) && x <= (5.0 / 6.0))
	{
		return 3 * x - (3.0 / 2.0);
	}

	else if(x > (5.0 / 6.0) && x <= 1)
	{
		return sqrt(1.0 - log(6.0 - 6.0 * x));
	}

	else 
	{
		return 0.0;
	}
}