// Librerie
#include "es6.h"
#include "functions.h"
#include <math.h>
#include <vector>

int main(int argc, char ** argv)
{
	// Dichiarazione variabili
	int N = 100; // Numero di punti
	int spacing = 10; // Spaziatura
	std::vector<int> N_vec; // Vettore dei punti
	int j_max = 10; // j_max per Romberg
	int k_max = 10; // k_max per Romberg
	double eps = 0.0; // Estremi di integrazione 
	double a = exp(-9.0) / static_cast<double>(N);
	double b = exp(-9.0);
	double analytic_value = 50.5 * exp(-9.0); // Valore analitico dell'integrale

	// Nomi dei file 
	std::string f_trapezio = "scarto_trapezio.txt";
	std::string f_simpson = "scarto_simpson.txt";
	std::string f_hermite = "hermite.txt"; // File di pesi e punti 
	std::string f_laguerre_alpha_zero = "laguerre.txt"; // File di pesi e punti 

	// Riempie il vettore N_vec
	for(int i = spacing; i <= N; i += spacing)
	{
		N_vec.push_back(i);
	}

	// Stampa a schermo i risultati
	stampa_risultati(N, N_vec, j_max, k_max, eps, a, b, analytic_value, f_hermite, f_laguerre_alpha_zero);

	// Scrive i valori degli integrali su file
	output_scarto_to_file(f_trapezio, N_vec, eps, a, b, analytic_value, "trapezio");
	output_scarto_to_file(f_simpson, N_vec, eps, a, b, analytic_value, "simpson");

	return 0;
}
