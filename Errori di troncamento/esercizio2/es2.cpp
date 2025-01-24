// Librerie
#include "es2.h"

int main(int argc, char ** argv)
{
	// Controllo argomenti
	if(argc != 2)
	{
		std::cout << "Utilizzo ./c.out n" << '\n';
		return 1;
	}

	else if(std::stoi(argv[1]) <= 0)
	{
		std::cout << "Inserire un numero intero maggiore o uguale di 1." << '\n';
		return 1;
	}

	// Dichiarazione variabili 
	int n = std::stoi(argv[1]);

	// Precisione singola
	float phi1_f = std::numbers::phi_v<float> - 1.0; // 0.618
	float phi2_f = (-1.0) * std::numbers::phi_v<float>; // -1.618
	float chi0_f = 1.0;
	float chi1_f = phi1_f; 
	float delta_n_f = delta_n<float>(n, chi0_f, chi1_f, phi1_f);
	float epsilon_f = stima_epsilon<float>(n, chi0_f, chi1_f, phi1_f, phi2_f); 

	// Precisione doppia
	double phi1_d = std::numbers::phi_v<double> - 1.0; // 0.618
	double phi2_d = (-1.0) * std::numbers::phi_v<double>; // -1.618
	double chi0_d = 1.0;
	double chi1_d = phi1_d; 
	double delta_n_d = delta_n<double>(n, chi0_d, chi1_d, phi1_d);
	double epsilon_d = stima_epsilon<double>(n, chi0_d, chi1_d, phi1_d, phi2_d); 
	
	// Precisione quadrupla
	long double phi1_ld = std::numbers::phi_v<long double> - 1.0; // 0.618
	long double phi2_ld = (-1.0) * std::numbers::phi_v<long double>; // -1.618
	long double chi0_ld = 1.0;
	long double chi1_ld = phi1_ld; 
	long double delta_n_ld = delta_n<long double>(n, chi0_ld, chi1_ld, phi1_ld);
	long double epsilon_ld = stima_epsilon<long double>(n, chi0_ld, chi1_ld, phi1_ld, phi2_ld); 
	
	// PRIMA PARTE DELL'ESERCIZIO: CALCOLARE DELTA N IN PRECISIONE SINGOLA, DOPPIA E QUADRUPLA
	
	// Stampa il risultato a schermo
	print_results_pt1(n, epsilon_f, delta_n_f, epsilon_d, delta_n_d, epsilon_ld, delta_n_ld);

	// SECONDA PARTE DELL'ESERCIZIO: PLOT DI DELTA N IN FUNZIONE DI N

	// Dichiarazione variabili
	int spacing = 5;
	std::vector<int> v_points;

	// Riempie il vector con punti da 1 a N, con uguale spaziatura
	for(int i = spacing; i <= n; i += spacing)
	{
		v_points.push_back(i);
	}	

	// Nomi dei file
	std::string f_deltaN_singola = "deltaN_precisione_singola.txt";
	std::string f_deltaN_doppia = "deltaN_precisione_doppia.txt";
	std::string f_deltaN_quadrupla = "deltaN_precisione_quadrupla.txt";
	std::string f_chiNplus1_singola = "chiNplus1_precisione_singola.txt";
	std::string f_chiNplus1_doppia = "chiNplus1_precisione_doppia.txt";
	std::string f_chiNplus1_quadrupla = "chiNplus1_precisione_quadrupla.txt";
	std::string f_epsilon_singola = "epsilon_precisione_singola.txt";
	std::string f_epsilon_doppia = "epsilon_precisione_doppia.txt";
	std::string f_epsilon_quadrupla = "epsilon_precisione_quadrupla.txt";

	// Plot di DeltaN 
	output_deltaN_to_file<float>(f_deltaN_singola, v_points, chi0_f, chi1_f, phi1_f);	
	output_deltaN_to_file<double>(f_deltaN_doppia, v_points, chi0_d, chi1_d, phi1_d);	
	output_deltaN_to_file<long double>(f_deltaN_quadrupla, v_points, chi0_ld, chi1_ld, phi1_ld);	

	// Plot di ChiN
	output_chiNplus1_to_file<float>(f_chiNplus1_singola, v_points, chi0_f, chi1_f);
	output_chiNplus1_to_file<double>(f_chiNplus1_doppia, v_points, chi0_d, chi1_d);
	output_chiNplus1_to_file<long double>(f_chiNplus1_quadrupla, v_points, chi0_ld, chi1_ld);

	// Plot di epsilon
	output_epsilon_to_file<float>(f_epsilon_singola, v_points, chi0_f, chi1_f, phi1_f, phi2_f);
	output_epsilon_to_file<double>(f_epsilon_doppia, v_points, chi0_d, chi1_d, phi1_d, phi2_d);
	output_epsilon_to_file<long double>(f_epsilon_quadrupla, v_points, chi0_ld, chi1_ld, phi1_ld, phi2_ld);
	
	// TERZA PARTE DELL'ESERCIZIO: FISSATO EPSILON=10^(-8) CONFRONTARE PRECISIONE SINGOLA E QUADRUPLA
	// Precisione singola
	float epsilon_f_fixed = pow(10.0, -8.0);
	float chi0_f_fixed = 1.0;
	float chi1_f_fixed = phi1_f + epsilon_f_fixed * phi2_f; 
	float delta_n_f_fixed = delta_n<float>(n, chi0_f_fixed, chi1_f_fixed, phi1_f);
	
	// Precisione quadrupla
	long double epsilon_ld_fixed = pow(10.0, -8.0);
	long double chi0_ld_fixed = 1.0;
	long double chi1_ld_fixed = phi1_ld + epsilon_ld_fixed * phi2_ld; 
	long double delta_n_ld_fixed = delta_n<long double>(n, chi0_ld_fixed, chi1_ld_fixed, phi1_ld);

	// Stampa i risultati a schermo
	print_results_pt3(n, epsilon_f_fixed, delta_n_f_fixed, epsilon_ld_fixed, delta_n_ld_fixed);
	
	// Nomi file
	std::string f_deltaN_fixed_singola = "deltaN_fixed_precisione_singola.txt";
	std::string f_deltaN_fixed_quadrupla = "deltaN_fixed_precisione_quadrupla.txt";
	std::string f_chiNplus1_fixed_singola = "chiNplus1_fixed_precisione_singola.txt";
	std::string f_chiNplus1_fixed_quadrupla = "chiNplus1_fixed_precisione_quadrupla.txt";
	
	// Plot di DeltaN 
	output_deltaN_to_file<float>(f_deltaN_fixed_singola, v_points, chi0_f_fixed, chi1_f_fixed, phi1_f);	
	output_deltaN_to_file<long double>(f_deltaN_fixed_quadrupla, v_points, chi0_ld_fixed, chi1_ld_fixed, phi1_ld);	

	// Plot di ChiN
	output_chiNplus1_to_file<float>(f_chiNplus1_fixed_singola, v_points, chi0_f_fixed, chi1_f_fixed);
	output_chiNplus1_to_file<long double>(f_chiNplus1_fixed_quadrupla, v_points, chi0_ld_fixed, chi1_ld_fixed);

	return 0;
}
