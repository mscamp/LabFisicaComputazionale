// Librerie
#include <iostream>
#include <math.h>
#include "es12.h"
#include "pseudorandom.h"
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
	std::vector<double> gauss_metodo_esatto;
	std::vector<double> gauss_accept_reject;
	double A = 1.0 / sqrt(std::numbers::pi_v<double>);

	// Nomi file
	std::string file_name_metodo_esatto = "gauss_metodo_esatto.txt";
	std::string file_name_accept_reject = "gauss_accept_reject.txt";

	// Ciclo su N
	for(int i = 0; i < N; ++i)
	{
		gauss_metodo_esatto.push_back(metodo_esatto());
		gauss_accept_reject.push_back(accept_reject(f, h_norm, h_cdf_inversa, 3.0 * A));
	}

	// Scrivi su file
	scrivi_su_file(file_name_metodo_esatto, gauss_metodo_esatto);
	scrivi_su_file(file_name_accept_reject, gauss_accept_reject);

	return 0;
}
