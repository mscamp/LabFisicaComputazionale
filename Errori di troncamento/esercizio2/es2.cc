// Librerie
#include <iostream>
#include <iomanip>
#include <limits>

void print_results_pt1(int n, float epsilon_f, float delta_n_f, double epsilon_d, double delta_n_d, long double epsilon_ld, long double delta_n_ld)
{

    // Stampa con numero di cifre della precisione quadrupla * 2 (altrimenti si ottengono valori di eps nulli in precisione quadrupla)
	std::cout << std::fixed << std::showpoint << std::setprecision(2 * std::numeric_limits<long double>::digits10);
 
    // Stampa risultati a schermo
	std::cout << '\n';
	std::cout << " *** PARTE 1 *** " << '\n';
	std::cout << "N = " << n << "\n\n";

	std::cout << "--- PRECISIONE SINGOLA ---" << '\n';
	std::cout << "Epsilon: " << epsilon_f << '\n';
	std::cout << "Scarto: " << delta_n_f << '\n';
	std::cout << "\n\n";
	
	std::cout << "--- PRECISIONE DOPPIA ---" << '\n';
	std::cout << "Epsilon: " << epsilon_d << '\n';
	std::cout << "Scarto: " << delta_n_d << '\n';
	std::cout << "\n\n";
	
	std::cout << "--- PRECISIONE QUADRUPLA ---" << '\n';
	std::cout << "Epsilon: " << epsilon_ld << '\n';
	std::cout << "Scarto: " << delta_n_ld << '\n';
	std::cout << '\n';
}

void print_results_pt3(int n, float epsilon_f, float delta_n_f, long double epsilon_ld, long double delta_n_ld)
{
 
    // Stampa con numero di cifre della precisione quadrupla * 2 (altrimenti si ottengono valori di eps nulli in precisione quadrupla)
	std::cout << std::fixed << std::showpoint << std::setprecision(2 * std::numeric_limits<long double>::digits10);

    // Stampa risultati a schermo
	std::cout << '\n';
	std::cout << " *** PARTE 3 *** " << '\n';
	std::cout << "N = " << n << "\n\n";

	std::cout << "--- PRECISIONE SINGOLA ---" << '\n';
	std::cout << "Epsilon: " << epsilon_f << '\n';
	std::cout << "Scarto: " << delta_n_f << '\n';
	std::cout << "\n\n";
	
	std::cout << "--- PRECISIONE QUADRUPLA ---" << '\n';
	std::cout << "Epsilon: " << epsilon_ld << '\n';
	std::cout << "Scarto: " << delta_n_ld << '\n';
	std::cout << '\n';
}
