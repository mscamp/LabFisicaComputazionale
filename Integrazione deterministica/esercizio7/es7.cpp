// Librerie
#include "es7.h"
#include "functions.h"
#include <math.h>
#include <numbers>

int main(int argc, char ** argv)
{
	// Dichiarazione variabili
	double analytic_value = (135135.0 / 256.0) * sqrt(std::numbers::pi_v<double>); // Valore analitico dell'integrale

	// Nomi dei file 
	std::string f_hermite = "hermite.txt"; // File di pesi e punti 
	std::string f_laguerre_alpha_zero = "laguerre.txt"; // File di pesi e punti 

	// Stampa a schermo i risultati
	stampa_risultati(analytic_value, f_hermite, f_laguerre_alpha_zero);

	return 0;
}
