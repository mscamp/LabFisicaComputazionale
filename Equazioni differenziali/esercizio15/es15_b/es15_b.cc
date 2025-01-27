// Librerie
#include <iomanip>
#include <limits>
#include <fstream>
#include <vector>

void scrivi_su_file(std::string file_name, std::vector<double> t, std::vector<double> y)
{
	// Dichiarazione variabili
	std::ofstream file;
	file.open(file_name, std::ios::out);

    // Stampa con numero di cifre della precisione doppia
	file << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<double>::digits10);

	// Scrivi elementi del vector su file
	for(int i = 0; i < y.size(); ++i)
	{
		file << t.at(i) << '\t' << y.at(i) << '\n';
	}

	file.close();
}