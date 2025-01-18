// Librerie
#include <vector>
#include <math.h>
#include <numbers>
#include <time.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>

double rand_range(double min, double max)
{
	return min + (max - min) * (rand() / static_cast<double>(RAND_MAX));
}

std::vector<double> genera_punto(int dim, double min, double max)
{
	// Definizione variabili 
	std::vector<double> point;

	for(int i = 0; i < dim; ++i)
	{
		point.push_back(rand_range(min, max));
	}

	return point;
}

double norma(std::vector<double> point)
{
	// Definizione variabili 
	double res = 0.0;

	for(int i = 0; i < point.size(); ++i)
	{
		res += pow(point.at(i), 2.0);
	}

	return sqrt(res);
}

int fattoriale(int n)
{
	// Dichiarazione variabili
	int res = 1.0;

	for(int k = n; k > 1; --k)
	{
		res *= k;
	}

	return res;
}

int fattoriale_doppio_dispari(int n) 
{
	// Dichiarazione variabili
	int res = 1.0;
	
	// Dato che n dispari
	for(int k = (n + 1) / 2; k > 1; --k)
	{
		res *= (2 * k) - 1;
	}
	
	return res;
}

double sfera_midpoint(int m, int n_intervals, double * time_midpoint)
{		
	// Tempo di esecuzione (in secondi)
	clock_t tStart = clock();

	// Dichiarazione variabili
	int point = 0;
	int n_points = 1;
	int x_i = 0;
	int dim = 0;
	double h = 0.0;
	double norm = 0.0;
	double vol = 0.0;

	// Calcola il numero totale dei punti (n_intervals punti per direzione coordinata)
	for(int d = 1; d <= (m - 1); ++d)
	{
		n_points *= n_intervals;
	}

	// Spaziatura della griglia
	h = 1.0 / static_cast<double>(n_intervals);

	// Ciclo principale sul numero di punti
	for(int n = 0; n < n_points; ++n)
	{
		point = n;
		norm = 0.0;
		dim = n_points / n_intervals; // Numero di punti per direzione coordinata (variabile) 

		// Ciclo sulla dimensione
		for(int j = 1; j <= (m - 1); ++j) 
		{
			x_i = point / dim;
			norm += pow(h * static_cast<double>(x_i) + (h / 2.0), 2.0);
			point = point - (x_i * dim);
			dim /= n_intervals;
		}

		if(norm <= 1.0)
		{
			vol += sqrt(1.0 - norm);
		}
	}	

	vol *= pow(2.0, static_cast<double>(m)) / static_cast<double>(n_points);
	
	// Tempo di esecuzione (in secondi)
	*(time_midpoint) = (clock() - tStart) / static_cast<double>(CLOCKS_PER_SEC);

	return vol;
}

std::pair<double, double> sfera_montecarlo(int m, int n_points, double * time_mc)
{
	// Tempo di esecuzione (in secondi)
	clock_t tStart = clock();
	
	// Dichiarazione variabili
	std::pair<double, double> integral;
	std::vector<double> x;
	int hit_count = 0;
	double a = -1.0;
	double b = 1.0;
	double vol = pow((b - a), static_cast<double>(m));
	double p = 0.0;

	for(int n = 0; n < n_points; ++n)
	{
		x = genera_punto(m, a, b);

		if(norma(x) <= 1.0)
		{
			++hit_count;
		}
	}

	p = (static_cast<double>(hit_count) / static_cast<double>(n_points));

	integral.first = p * vol;
	integral.second = sqrt(((vol * vol) / n_points) * p * (1.0 - p));

	// Tempo di esecuzione (in secondi)
	*(time_mc) = (clock() - tStart) / static_cast<double>(CLOCKS_PER_SEC);

	return integral;
}

double analytic_value(int m)
{
	// Dichiarazione variabili
	double res = 0.0;	

	if(m % 2 == 0)
	{
		res = pow(std::numbers::pi_v<double>, static_cast<double>(m / 2)) / fattoriale(m / 2);
	}

	else
	{
		res = (pow(2.0, static_cast<double>((m + 1) / 2)) * pow(std::numbers::pi_v<double>, static_cast<double>((m - 1) / 2))) / fattoriale_doppio_dispari(m);
	}

	return res;
}

void output_to_file(std::string name, std::vector<double> v)
{
	// Apre il file per scrivere i punti
	std::ofstream file;
	file.open(name, std::ofstream::out);

	for(int i = 0; i < v.size(); ++i)
	{
    	// Stampa con numero di cifre della precisione doppia
		file << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<double>::digits10);
		file << v.at(i);
		file << '\n';
	}

	file.close();
}