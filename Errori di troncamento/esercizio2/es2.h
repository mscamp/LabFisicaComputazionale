// Librerie
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <numbers>
#include <vector>
#include <string>

template<typename T>
T modulo(T val)
{
	if(val < 0)
	{
		val *= -1.0;
		return val;
	}
	
	return val;
}

template<typename T>
T formula_ricorsiva(int n, T chi_n_minus_one, T chi_n) 
{
	T chi_n_plus_one = 0.0;

	for(int i = 0; i < n; ++i)
	{
		chi_n_plus_one = chi_n_minus_one - chi_n;		
		chi_n_minus_one = chi_n;
		chi_n = chi_n_plus_one;
	}

	return chi_n_plus_one;
}

template<typename T>
T delta_n(int n, T chi_n_minus_one, T chi_n, T phi1)
{
	T scarto = formula_ricorsiva<T>(n, chi_n_minus_one, chi_n) - pow(phi1, static_cast<T>(n));

	// Gli scarti devono essere positivi
	scarto = modulo<T>(scarto);

	return scarto;
}

template<typename T>
T stima_epsilon(int n, T chi_n_minus_one, T chi_n, T phi1, T phi2)
{
	T epsilon = delta_n<T>(n, chi_n_minus_one, chi_n, phi1) / pow(modulo<T>(phi2), static_cast<T>(n));
			
	return epsilon;
}

template<typename T>
void output_deltaN_to_file(std::string name, std::vector<int> v, T chi_n_minus_one, T chi_n, T phi1)
{
	// Apre il file per scrivere i punti
	std::ofstream f;
	f.open(name, std::ofstream::out);

	// Dichiarazione variabili
	T tmp = 0.0;

	for(int i = 0; i < v.size(); ++i)
	{
		tmp = delta_n<T>(v.at(i), chi_n_minus_one, chi_n, phi1);

    	// Stampa con numero di cifre della precisione quadrupla
		f << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<long double>::digits10);
		f << tmp;
		f << '\n';
	}

	f.close();
}

template<typename T>
void output_chiNplus1_to_file(std::string name, std::vector<int> v, T chi_n_minus_one, T chi_n)
{
	// Apre il file per scrivere i punti
	std::ofstream f;
	f.open(name, std::ofstream::out);

	// Dichiarazione variabili
	T tmp = 0.0;

	for(int i = 0; i < v.size(); ++i)
	{
		tmp = formula_ricorsiva<T>(v.at(i), chi_n_minus_one, chi_n);

    	// Stampa con numero di cifre della precisione quadrupla
		f << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<long double>::digits10);
		f << tmp;
		f << '\n';
	}

	f.close();
}

template<typename T>
void output_epsilon_to_file(std::string name, std::vector<int> v, T chi_n_minus_one, T chi_n, T phi1, T phi2)
{
	// Apre il file per scrivere i punti
	std::ofstream f;
	f.open(name, std::ofstream::out);

	// Dichiarazione variabili
	T tmp = 0.0;

	for(int i = 0; i < v.size(); ++i)
	{
		tmp = stima_epsilon<T>(v.at(i), chi_n_minus_one, chi_n, phi1, phi2);

    	// Stampa con numero di cifre della precisione quadrupla * 2 (altrimenti si ottengono valori di eps nulli in precisione quadrupla)
		f << std::fixed << std::showpoint << std::setprecision(2 * std::numeric_limits<long double>::digits10);
		f << tmp;
		f << '\n';
	}

	f.close();
}

void print_results_pt1(int n, float epsilon_f, float delta_n_f, double epsilon_d, double delta_n_d, long double epsilon_ld, long double delta_n_ld);
void print_results_pt3(int n, float epsilon_f, float delta_n_f, long double epsilon_ld, long double delta_n_ld);
