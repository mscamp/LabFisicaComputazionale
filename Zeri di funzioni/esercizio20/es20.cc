// Librerie
#include <iomanip>
#include <limits>
#include <fstream>
#include <string>
#include <vector>
#include <complex>

void scrivi_su_file(std::string file_name, std::vector<double> x, std::vector<double> y, std::vector<int> js)
{
	// Dichiarazione variabili
	std::ofstream file;
	file.open(file_name, std::ios::out);

    // Stampa con numero di cifre della precisione doppia
	file << std::fixed << std::showpoint << std::setprecision(std::numeric_limits<double>::digits10);

	// Scrivi elementi del vector su file
	for(int i = 0; i < y.size(); ++i)
	{
		file << x.at(i) << '\t' << y.at(i) << '\t' << js.at(i) << '\n';
	}

	file.close();
}

std::complex<double> newton(std::complex<double> z)
{
	return z - (((z * z * z) - 1.0) / (3.0 * z * z));
}

void newton_fractal(double x_min, double x_max, double y_min, double y_max, int N, int K, double eps)
{
	// Dichiarazione variabili
	int j = 0;
	std::vector<double> x;
	std::vector<double> y;
	std::vector<int> js;
	double step_x = fabs(x_max - x_min) / static_cast<double>(N);
	double step_y = fabs(y_max - y_min) / static_cast<double>(N);
	std::complex<double> z_next;

	// Nome del file
	std::string file_name_newton_fractal = "newton_fractal.txt";

 	// Loop sulla griglia di punti
	for(int n_1 = 0; n_1 < N; ++n_1)
	{
		for(int n_2 = 0; n_2 < N; ++n_2)
		{
			std::complex<double> z(x_min + n_1 * step_x, y_min + n_2 * step_y);
			x.push_back(z.real());
			y.push_back(z.imag());
			
			z_next = newton(z);
			j += 1;

			while(abs(z_next - z) > eps && j < K)
			{
				z = z_next;
				z_next = newton(z);
				j += 1;
			} 

			js.push_back(j);
			j = 0;
		}
	}

	// Scrivi su file
	scrivi_su_file(file_name_newton_fractal, x, y, js);
}