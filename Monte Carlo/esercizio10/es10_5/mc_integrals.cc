// Librerie
#include <math.h>

double rand_range(double min, double max)
{
	return min + (max - min) * (rand() / static_cast<double>(RAND_MAX));
}

std::pair<double, double> monte_carlo(double f(double x), double a, double b, int N)
{
	// Dichiarazione variabili
	std::pair<double, double> result;
	double integrale = 0.0;
	double incertezza = 0.0;
	double media_f = 0.0;
	double media_f2 = 0.0;

	// Calcolo integrale
	for(int i = 0; i < N; ++i)
	{
		media_f += f(rand_range(a, b));
		media_f2 += pow(f(rand_range(a, b)), 2.0);
	}

	media_f *= 1.0 / static_cast<double>(N);
	media_f2 *= 1.0 / static_cast<double>(N);
	integrale = media_f * (b - a);
	
	// Calcolo incertezza
	incertezza = ((b - a) * sqrt(media_f2 - pow(media_f, 2.0))) / sqrt(N);

	result.first = integrale;
	result.second = incertezza;

	return result;	
}

std::pair<double, double> hit_or_miss(double g(double), double a, double b, double y_min, double y_max, int N)
{
    std::pair<double, double> integrale;

    int n_hit = 0;
    double x = 0.0;
    double y = 0.0;
    double A = (b - a) * (y_max - y_min);
    double p = 0.0;

    for(int i = 0; i < N; ++i)
    {
        x = rand_range(a, b);
        y = rand_range(y_min, y_max);

        if(y < g(x))
        {
            ++n_hit;
        }
    }

    p = static_cast<double>(n_hit) / N;

    integrale.first = A * (static_cast<double>(n_hit) / static_cast<double>(N));
    integrale.second = (A / sqrt(static_cast<double>(N))) * sqrt(p*(1-p));

    return integrale;
}
