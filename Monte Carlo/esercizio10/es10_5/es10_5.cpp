// Librerie
#include "es10_5.h"
#include "mc_integrals.h"
#include "functions.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

int main(int argc, char ** argv)
{
	// Controllo degli argomenti passati da riga di comando
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

	// Seed random
	srand(time(NULL));

	// Dichiarazione variabili
	int N = atoi(argv[1]);
	int spacing = 100;
	std::vector<int> N_vec;
	double a = -1.0; // Estremi di integrazione 
	double b = 8.0;
	double y_min = 0.0; // Intervallo sulle y per hit or miss
	double y_max = f(b);
	double analytic_value = primitive(b) - primitive(a); // Valore analitico dell'integrale
	std::vector<double> integrale_mc;
	std::vector<double> integrale_hm;
	std::vector<double> integrale_mc_scarti; // Scarto con valore analitico
	std::vector<double> integrale_hm_scarti; // Scarto con valore analitico
	std::vector<double> incertezza_mc;
	std::vector<double> incertezza_hm;

	// Nomi file
	std::string file_name_mc = "monte_carlo_scarto.txt";
	std::string file_name_hm = "hit_or_miss_scarto.txt";
	std::string file_name_mc_incertezza = "monte_carlo_incertezza.txt";
	std::string file_name_hm_incertezza = "hit_or_miss_incertezza.txt";

    // Stampa con numero di cifre della precisione doppia
	std::cout << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<double>::digits10);

	// Riempie il vettore degli N
	for(int i = spacing; i <= N; i += spacing)
	{
		N_vec.push_back(i);
	}

	// Ciclo su N
	for(int i = 0; i < N_vec.size(); ++i)
	{
		// Calcolo integrali
		integrale_mc.push_back(monte_carlo(f, a, b, N_vec.at(i)).first);
		integrale_hm.push_back(hit_or_miss(f, a, b, y_min, y_max, N_vec.at(i)).first);

		// Calcolo integrali (scarto con il valore analitico)
		integrale_mc_scarti.push_back(fabs(integrale_mc.at(i) - analytic_value));
		integrale_hm_scarti.push_back(fabs(integrale_hm.at(i) - analytic_value));

		// Calcolo incertezza
		incertezza_mc.push_back(monte_carlo(f, a, b, N_vec.at(i)).second);
		incertezza_hm.push_back(hit_or_miss(f, a, b, y_min, y_max, N_vec.at(i)).second);

		// Stampa a schermo i risultati
		std::cout << "--- N = " << N_vec.at(i) << " ---" << '\n';
     	std::cout << "Monte Carlo = " << integrale_mc.at(i) << " +/- " << incertezza_mc.at(i) << '\n';
     	std::cout << "Hit or miss = " << integrale_hm.at(i) << " +/- " << incertezza_hm.at(i) << '\n';
		std::cout << "Risultato analitico: " << analytic_value << '\n';
     	std::cout << "Scarto con valore analitico (MC) = " << integrale_mc_scarti.at(i) << '\n';
     	std::cout << "Scarto con valore analitico (HM) = " << integrale_hm_scarti.at(i) << '\n';
		std::cout << '\n';
		
	}
	
	// Scrivi su file di testo
	scrivi_su_file(file_name_mc, integrale_mc_scarti);
	scrivi_su_file(file_name_hm, integrale_hm_scarti);
	scrivi_su_file(file_name_mc_incertezza, incertezza_mc);
	scrivi_su_file(file_name_hm_incertezza, incertezza_hm);

	return 0;
}
