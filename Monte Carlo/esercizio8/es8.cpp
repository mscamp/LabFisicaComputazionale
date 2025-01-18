// Librerie
#include <iostream>
#include "es8.h"

int main (int argc, char ** argv)
{
	// Random seed
	srand(time(NULL));

	// Controllo sugli argomenti passati da riga di comando
	if(argc != 2)	
	{
		std::cout << "Utilizzo: ./c.out dimensione_sfera" << '\n';
		return 1;
	}

	else if (atoi(argv[1]) <= 0)
	{
		std::cout << "Inserisci un numero intero positivo e diverso da zero." << '\n';
		return 1;
	}

	// Dichiarazione variabili
	int m = atoi(argv[1]);
	int n_intervals = 20;
	int n_points = 100000;
	double mc_integral = 0.0;
	double mc_integral_error = 0.0;
	double * time_midpoint = new double(0.0);
	double * time_mc = new double(0.0);
	std::vector<double> v_time_midpoint;
	std::vector<double> v_time_mc;

	// Nomi dei file
	std::string f_time_midpoint = "tempo_esecuzione_midpoint.txt";
	std::string f_time_mc = "tempo_esecuzione_mc.txt";

	// Ciclo sulla dimensione della sfera
	for(int r = 1; r <= (m - 1); ++r)
	{
		mc_integral = sfera_montecarlo(r, n_points, time_mc).first;
		mc_integral_error = sfera_montecarlo(r, n_points, time_mc).second;

		std::cout << "##### " << r << "-sfera #####" << '\n';
     	std::cout << "Integrale deterministico: " << sfera_midpoint(r, n_intervals, time_midpoint) << '\n';
     	std::cout << "Integrale Monte Carlo: " << mc_integral << " +/- " << mc_integral_error << '\n';
		std::cout << "Risultato analitico: "  << analytic_value(r) << '\n';

     	std::cout << '\n';
		std::cout << "---------------------------------" << '\n';
		std::cout << "Tempo di esecuzione (midpoint): " << *(time_midpoint) << " s " << '\n';
		std::cout << "Tempo di esecuzione (MC): " << *(time_mc) << " s " << '\n';
		std::cout << "---------------------------------" << '\n';
     	std::cout << '\n';

		// Riempie vector dei tempi di esecuzione
		v_time_midpoint.push_back(*(time_midpoint));
		v_time_mc.push_back(*(time_mc));
	}

	// Scrive i valori dei tempi di esecuzione su un file
	output_to_file(f_time_midpoint, v_time_midpoint);
	output_to_file(f_time_mc, v_time_mc);

	// Deallocazione memoria
	delete time_midpoint;
	delete time_mc;

	return 0;
}
