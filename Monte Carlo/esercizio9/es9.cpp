// Librerie
#include <iostream>
#include <vector>
#include "es9.h"

int main(int argc, char ** argv) 
{
	// Random seed
	srand(time(NULL));

	// Controllo argomenti passati da riga di comando
	if(argc != 2)
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
	double a = -1.0;
	double b = 1.0;
	int N = atoi(argv[1]); // Numero di elementi su cui viene effettuata la media
	int M = 10000; // Dimensione del pacchetto (fissata)

	// Vettori dei sample
	std::vector<double> vec_interni;
	std::vector<double> vec_estremi;

	// Vettori dei momenti (1 = x^4/x^2, 2 = x^6/x^4 )
	std::vector<double> vec_momenti_1_interni;
	std::vector<double> vec_momenti_2_interni;
	std::vector<double> vec_momenti_1_estremi;
	std::vector<double> vec_momenti_2_estremi;
	std::vector<double> vec_momenti_1_gauss;
	std::vector<double> vec_momenti_2_gauss;

	// Nomi dei file
	std::string file_name_interni = "";
	std::string file_name_estremi = "";
	std::string file_name_momenti_1_interni = "momenti_1_interni.txt";
	std::string file_name_momenti_2_interni = "momenti_2_interni.txt";
	std::string file_name_momenti_1_estremi = "momenti_1_estremi.txt";
	std::string file_name_momenti_2_estremi = "momenti_2_estremi.txt";
	std::string file_name_momenti_1_gauss = "momenti_1_gauss.txt";
	std::string file_name_momenti_2_gauss = "momenti_2_gauss.txt";

	// Scrivi su file
	for(int n = 1; n <= N; ++n)
	{ 
		// Distribuzione in (-1,1)
		vec_interni = rand_TCL(a, b, M, n, false);
		file_name_interni = "gauss_TCL_interni_N" + std::to_string(n) + ".txt";
		scrivi_su_file(file_name_interni, vec_interni);

		// Distribuzione agli estremi -1, 1
		vec_estremi = rand_TCL(a, b, M, n, true);
		file_name_estremi = "gauss_TCL_estremi_N" + std::to_string(n) + ".txt";
		scrivi_su_file(file_name_estremi, vec_estremi);

		// Calcolo dei momenti del campione
		vec_momenti_1_interni.push_back(momento_k_campione(vec_interni, 4) / momento_k_campione(vec_interni, 2));
		vec_momenti_2_interni.push_back(momento_k_campione(vec_interni, 6) / momento_k_campione(vec_interni, 4));
		vec_momenti_1_estremi.push_back(momento_k_campione(vec_estremi, 4) / momento_k_campione(vec_estremi, 2));
		vec_momenti_2_estremi.push_back(momento_k_campione(vec_estremi, 6) / momento_k_campione(vec_estremi, 4));

		// Calcolo momenti della distribuzione aspettata
		vec_momenti_1_gauss.push_back(momenti_gaussiana(n).first);
		vec_momenti_2_gauss.push_back(momenti_gaussiana(n).second);
	}

	// Scrivi su file i momenti del campione
	scrivi_su_file(file_name_momenti_1_interni, vec_momenti_1_interni);
	scrivi_su_file(file_name_momenti_2_interni, vec_momenti_2_interni);
	scrivi_su_file(file_name_momenti_1_estremi, vec_momenti_1_estremi);
	scrivi_su_file(file_name_momenti_2_estremi, vec_momenti_2_estremi);
	
	// Scrivi su file i momenti di una gaussiana
	scrivi_su_file(file_name_momenti_1_gauss, vec_momenti_1_gauss);
	scrivi_su_file(file_name_momenti_2_gauss, vec_momenti_2_gauss);

	return 0;
}
