// Librerie
#include "integrals.h"
#include "functions.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <math.h>
#include <vector>
#include <string>

void output_scarto_to_file(std::string name, std::vector<int> v, double eps, double a, double b, double analytic_val, std::string choice)
{
	// Apre il file per scrivere i punti
	std::ofstream file;
	file.open(name, std::ofstream::out);

	// Dichiarazione variabili
	double tmp = 0.0;

	for(int i = 0; i < v.size(); ++i)
	{
		if(choice == "trapezio")
		{
			tmp = fabs(analytic_val - (formula_aperta_3punti(f_integrand, eps, a) + trapezio_estesa(v.at(i), f_integrand, a, b)));
		}
		
		else if (choice == "simpson") 
		{
			tmp = fabs(analytic_val - (formula_aperta_3punti(f_integrand, eps, a) + simpson_estesa(v.at(i), f_integrand, a, b)));
		}

		else
		{
			std::cout << "Errore: l'argomento '" << choice << "' deve essere 'trapezio' o 'simpson'." << '\n';
		}

    	// Stampa con numero di cifre della precisione doppia
		file << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<double>::digits10);
		file << tmp;
		file << '\n';
	}

	file.close();
}

void stampa_risultati(int N, std::vector<int> N_vec, int j_max, int k_max, double eps, double a, double b, double analytic_value, std::string f_hermite, std::string f_laguerre_alpha_zero)
{
	// Stampa con numero di cifre della precisione doppia
	std::cout << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<double>::digits10);

	// Stampa a schermo i risultati di A, B, C
	std::cout << "Risultato trapezio (N = " << N << "): " << formula_aperta_3punti(f_integrand, eps, a) + trapezio_estesa(N, f_integrand, a, b) << '\n';
	std::cout << "Risultato Simpson (N = " << N << "): " << formula_aperta_3punti(f_integrand, eps, a) + simpson_estesa(N, f_integrand, a, b) << '\n';
	std::cout << "Risultato Romberg: " << '\n' << formula_aperta_3punti(f_integrand, eps, a) + romberg(j_max, k_max, f_integrand, a, b) << " (N = " << pow(2.0, static_cast<double>(j_max)) + 1.0 << ")" << '\n';

	// Stampa a schermo i risultati di D
	std::cout << '\n';

	std::cout << "Risultato Gauss (Hermite, N = 2): " << gauss(f_hermite, 2, f_gauss_hermite) << '\n';
	std::cout << "Risultato Gauss (Hermite, N = 4): " << gauss(f_hermite, 4, f_gauss_hermite) << '\n';
	std::cout << "Risultato Gauss (Hermite, N = 8): " << gauss(f_hermite, 8, f_gauss_hermite) << '\n';
	std::cout << "Risultato Gauss (Hermite, N = 100): " << gauss(f_hermite, 100, f_gauss_hermite) << '\n';

	std::cout << "Risultato Gauss (Laguerre, alpha = 0, N = 2): " << gauss(f_laguerre_alpha_zero, 2, f_gauss_laguerre) << '\n';
	std::cout << "Risultato Gauss (Laguerre, alpha = 0, N = 4): " << gauss(f_laguerre_alpha_zero, 4, f_gauss_laguerre) << '\n';
	std::cout << "Risultato Gauss (Laguerre, alpha = 0, N = 8): " << gauss(f_laguerre_alpha_zero, 8, f_gauss_laguerre) << '\n';
	
	// Valore analitico dell'integrale
	std::cout << "Risultato analitico: " << analytic_value << '\n';
}