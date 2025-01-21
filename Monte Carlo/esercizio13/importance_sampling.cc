// Librerie
#include <stdlib.h>

double rand_range(double min, double max)
{
	return min + (max - min) * (rand() / static_cast<double>(RAND_MAX));
}

double importance_sampling(int N, double f(double x))
{
    // Dichiarazione variabili
    double res = 0.0;

    for(int i = 0; i < N; ++i)
    {
        res += f(rand_range(0.0, 1.0));
    }

    res *= 1.0 / static_cast<double>(N);

    return res;
}