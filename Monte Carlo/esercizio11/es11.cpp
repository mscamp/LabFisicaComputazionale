// Librerie
#include <iostream>
#include "es11.h"
#include "functions.h"
#include "pseudorandom.h"

int main (int argc, char ** argv)
{

	// Controllo argomenti passati da riga di comando
	if(argc != 2)
	{
		std::cout << "Utilizzo: ./c.out N" << '\n';
		return 1;
	}

	else if(std::stoi(argv[1]) <= 0)
	{
		std::cout << "N deve essere strettamente positivo." << '\n';
		return 1;
	}

	// Seed random
	srand(time(NULL));

	// Dichiarazione variabili
	int N = std::stoi(argv[1]);
	std::vector<double> rand_1;
	std::vector<double> rand_2;
	std::vector<double> rand_3;

	// Nomi dei file
	std::string file_name_1 = "random_1.txt";
	std::string file_name_2 = "random_2.txt";
	std::string file_name_3 = "random_3.txt";

	// Ciclo su N
	for(int i = 0; i < N; ++i)
	{
		rand_1.push_back(funzione_inversa(cdf_inversa_1));
		rand_2.push_back(funzione_inversa(cdf_inversa_2));
		rand_3.push_back(funzione_inversa(cdf_inversa_3));
	}

	// Scrivi su file
	scrivi_su_file(file_name_1, rand_1);
	scrivi_su_file(file_name_2, rand_2);
	scrivi_su_file(file_name_3, rand_3);

	return 0;
}
