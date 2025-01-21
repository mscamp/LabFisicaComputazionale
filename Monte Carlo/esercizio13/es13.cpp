// Librerie
#include <iostream>
#include <math.h>
#include <numbers>
#include "es13.h"
#include "importance_sampling.h"
#include "functions.h"

int main (int argc, char ** argv)
{
	// Controllo argomenti passati da riga di comando
	if (argc != 2)
	{
		std::cout << "Utilizzo: ./c.out N" << '\n';
		return 1;
	}

	else if(atoi(argv[1]) <= 0)
	{
		std::cout << "N deve essere strettamente positivo." << '\n';
		return 1;
	}

	// Dichiarazione variabili
	int N = atoi(argv[1]);
	int spacing = 100;
	std::vector<double> scarti_integrale_1;
	std::vector<double> scarti_integrale_2;
	double analytic_value_1 = 0.5 * (std::numbers::pi_v<double> - 2.0);
	double analytic_value_2 = std::numbers::pi_v<double>;

	// Nomi file
	std::string file_name_scarti_integrale_1 = "scarti_integrale_1.txt";
	std::string file_name_scarti_integrale_2 = "scarti_integrale_2.txt";

	// Ciclo su N
	for(int i = spacing; i <= N; i += spacing)
	{
		scarti_integrale_1.push_back(fabs(importance_sampling(i, G_inverse_1) - analytic_value_1));
		scarti_integrale_2.push_back(fabs(importance_sampling(i, G_inverse_2) - analytic_value_2));
	}

	// Stampa a schermo il risultato
	stampa_risultati(N, G_inverse_1, G_inverse_2, analytic_value_1, analytic_value_2);

	// Scrivi su file
	scrivi_su_file(file_name_scarti_integrale_1, scarti_integrale_1);
	scrivi_su_file(file_name_scarti_integrale_2, scarti_integrale_2);

	return 0;
}