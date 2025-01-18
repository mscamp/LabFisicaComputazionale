// Librerie
#include "integrals.h"
#include "functions.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <math.h>
#include <string>

void stampa_risultati(double analytic_value, std::string f_hermite, std::string f_laguerre_alpha_zero)
{
	// Stampa con numero di cifre della precisione doppia
	std::cout << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<double>::digits10);

	// Stampa a schermo i risultati di D
	std::cout << '\n';

	std::cout << "Risultato Gauss (Hermite, N = 2): " << gauss(f_hermite, 2, f_gauss_hermite) << '\n';
	std::cout << "Risultato Gauss (Hermite, N = 4): " << gauss(f_hermite, 4, f_gauss_hermite) << '\n';
	std::cout << "Risultato Gauss (Hermite, N = 8): " << gauss(f_hermite, 8, f_gauss_hermite) << '\n';

	std::cout << "Risultato Gauss (Laguerre, alpha = 0, N = 2): " << gauss(f_laguerre_alpha_zero, 2, f_gauss_laguerre) << '\n';
	std::cout << "Risultato Gauss (Laguerre, alpha = 0, N = 4): " << gauss(f_laguerre_alpha_zero, 4, f_gauss_laguerre) << '\n';
	std::cout << "Risultato Gauss (Laguerre, alpha = 0, N = 8): " << gauss(f_laguerre_alpha_zero, 8, f_gauss_laguerre) << '\n';
	std::cout << "Risultato Gauss (Laguerre, alpha = 0, N = 24): " << gauss(f_laguerre_alpha_zero, 24, f_gauss_laguerre) << '\n';
	std::cout << "Risultato Gauss (Laguerre, alpha = 0, N = 64): " << gauss(f_laguerre_alpha_zero, 64, f_gauss_laguerre) << '\n';
	
	// Valore analitico dell'integrale
	std::cout << "Risultato analitico: " << analytic_value << '\n';
}