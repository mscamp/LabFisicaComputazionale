// Librerie
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numbers>
#include <limits>

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
T direct_sum(int n)
{
	T somma_parziale = 0.0;

	for(int k = 1; k <= n; ++k)
	{
		somma_parziale += 1.0 / (k * k);
	}

	return somma_parziale;
}

template<typename T>
T inverse_sum(int n)
{
	T somma_parziale = 0.0;

	for(int k = n; k > 0; --k)
	{
		somma_parziale += 1.0 / (k * k);
	}

	return somma_parziale;
}

template<typename T>
void output_to_file(std::string name, std::vector<int> v, std::string type)
{
	// Apre il file per scrivere i punti
	std::ofstream f;
	f.open(name, std::ofstream::out);

	// Dichiarazione variabili
	T termine_generale = 0.0;
	T pi = std::numbers::pi_v<T>;

	for(int i = 0; i < v.size(); ++i)
	{
		if(type == "direct")
		{
			termine_generale = direct_sum<T>(v.at(i)) - ((pi*pi) / 6.0);
		}

		else if (type == "inverse") 
		{
			termine_generale = inverse_sum<T>(v.at(i)) - ((pi*pi) / 6.0);
		}

		else 
		{
			std::cout << "Errore: l'argomento '" << type << "' deve essere 'direct' o 'inverse'." << '\n';
		}

		// Gli scarti devono essere positivi
		termine_generale = modulo<T>(termine_generale);
		
		f << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<double>::digits10); // Usa notazione decimale
		f << termine_generale;
		f << '\n';
	}
	
	f.close();
}