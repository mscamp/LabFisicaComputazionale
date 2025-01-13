// Librerie
#include "es1.h"

int main(int argc, char ** argv)
{
	// Dichiarazione variabili
	int N; // Numero di termini della somma 
	int spacing = 100; // Spaziatura
	std::vector<int> v_points;

	// Controllo sugli argomenti passati da riga di comando
	if(argc != 2)
	{
		std::cout << "Utilizzo ./c.out numero_iterazioni" << '\n';
		return 1;
	}

	else if(atoi(argv[1]) < spacing)
	{
		std::cout << "Inserire un numero intero maggiore o uguale a 100." << '\n';
		return 1;
	}

	// Assegnamento variabili
	N = atoi(argv[1]);

	// Riempie il vector con punti da 1 a N, con uguale spaziatura
	for(int i = spacing; i <= N; i += spacing)
	{
		v_points.push_back(i);
	}

	// Usa notazione decimale
	std::cout << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<double>::digits10);

	// Calcolo della somma (single precision)
	std::cout << "Somma diretta con N = " << N << " (single): " << direct_sum<float>(N) << '\n';
	std::cout << "Somma inversa con N = " << N << " (single): " << inverse_sum<float>(N) << "\n\n";

	// Calcolo della somma (double precision)
	std::cout << "Somma diretta con N = " << N << " (double): " << direct_sum<double>(N) << '\n';
	std::cout << "Somma inversa con N = " << N << " (double): " << inverse_sum<double>(N) << '\n';

	// Delta N (somma diretta, single precision)
	output_to_file<float>("deltaN_direct_single.txt", v_points, "direct");

	// Delta N (somma inversa, single precision)
	output_to_file<float>("deltaN_inverse_single.txt", v_points, "inverse");

	// Delta N (somma diretta, double precision)
	output_to_file<double>("deltaN_direct_double.txt", v_points, "direct");

	// Delta N (somma inversa, double precision)
	output_to_file<double>("deltaN_inverse_double.txt", v_points, "inverse");
	
	return 0;
} 
