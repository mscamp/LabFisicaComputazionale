// Librerie
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <vector>
#include "importance_sampling.h"

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

void stampa_risultati(int N, double G_inverse_1(double x), double G_inverse_2(double x), double analytic_value_1, double analytic_value_2)
{
	// Stampa con numero di cifre della precisione doppia
	std::cout << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<double>::digits10);

	// Stampa a schermo i risultati
	std::cout << "Risultato integrale 1 (N = " << N << "): " << importance_sampling(N, G_inverse_1) << '\n';
	std::cout << "Risultato integrale 2 (N = " << N << "): " << importance_sampling(N, G_inverse_2) << '\n';

	// Valore analitico degli integrali
	std::cout << "Risultato analitico 1: " << analytic_value_1 << '\n';
	std::cout << "Risultato analitico 2: " << analytic_value_2 << '\n';
}