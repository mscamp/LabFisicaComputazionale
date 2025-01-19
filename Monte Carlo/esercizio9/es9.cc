// Librerie
#include <iomanip>
#include <limits>
#include <fstream>
#include <string>
#include <vector>
#include <numbers>
#include <math.h>

double rand_range(double a, double b, bool estremi)
{
	// Dichiarazione variabili
	double r = 0.0;
	int r_int = 0;
	
	if(estremi == false)
	{
		do
		{

			r = a + (b - a) * (rand() / static_cast<double>(RAND_MAX));

		} while(r == a || r == b);

		return r;
	}
	
	else
	{
		r_int = rand();

		if(r_int > static_cast<double>(RAND_MAX) / 2.0)
		{
			return a;
		}

		else
		{
			return b;
		}
	}
}

std::vector<double> rand_TCL(double a, double b, int M, int N, bool estremi)
{
	// Dichiarazione variabili
	double r_n = 0.0;
	double x_i = 0.0;
	std::vector<double> x;

	for(int i = 0; i < M; ++i)
	{
		for(int n = 1; n <= N; ++n)
		{
			r_n = rand_range(a, b, estremi);
			x_i += r_n;
		}

		x_i *= (1.0 / static_cast<double>(N));

		x.push_back(x_i);
		x_i = 0.0;
	}

	return x;
}

void scrivi_su_file(std::string file_name, std::vector<double> v)
{
	// Dichiarazione variabili
	std::ofstream file;
	file.open(file_name, std::ios::out);

    // Stampa con numero di cifre della precisione doppia
	file << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<double>::digits10);

	// Scrivi elementi del vector su file
	for(int i = 0; i < v.size(); ++i)
	{
		file << v.at(i) << '\n';
	}

	file.close();
}

double momento_k_campione(std::vector<double> sample, int k)
{
	double momento_k = 0.0;
	int N = sample.size();

	for(int i = 0; i < N; ++i)
	{
		momento_k += pow(sample.at(i), static_cast<double>(k));
	}

	momento_k *= 1.0 / static_cast<double>(N);

	return momento_k;
}

std::pair<double, double> momenti_gaussiana(int N)
{
	// Dichiarazione variabili
	std::pair<double, double> result;
	double x2 = 1.0 / static_cast<double>(N);
	double x4 = 3.0 * (x2 * x2);
	double x6 = 15.0 * (x2 * x2 * x2);

	result.first = x4 / x2;
	result.second = x6 / x4;
	
	return result;
}
