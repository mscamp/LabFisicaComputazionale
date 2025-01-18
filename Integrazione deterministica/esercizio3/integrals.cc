// Librerie
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

std::vector<double> return_points(int N, double a, double b)
{
	// Dichiarazione variabili
	std::vector<double> points;
	double x_i = 0.0;
	double h = (b - a) / (static_cast<double>(N) - 1.0);

	for(int i = 0; i < N; ++i)
	{
		x_i = a + h * i;
		points.push_back(x_i);
	}

	return points;
}

double trapezio_estesa(int N, double f(double x), double a, double b)
{
	// Dichiarazione variabili
	double res = 0.0;
	double h = (b - a) / (static_cast<double>(N) - 1.0);
	std::vector<double> points = return_points(N, a, b);
	
	// Calcolo trapezio
	for(int i = 0; i < N; ++i)
	{
		if(i == 0 || i == (N - 1))
		{
			res += 0.5 * f(points.at(i));
		}

		else
		{
			res += f(points.at(i));
		}
	}

	res *= h;

	return res;
} 

double simpson_estesa(int N, double f(double x), double a, double b)
{
	// Dichiarazione variabili
	double res = 0.0;
	double h = (b - a) / (static_cast<double>(N) - 1.0);
	std::vector<double> points = return_points(N, a, b);
	
	// Calcolo Simpson
	for(int i = 0; i < N; ++i)
	{
		if(i == 0 || i == (N - 1))
		{
			res += f(points.at(i));
		}

		else if(i % 2 == 0)
		{
			res += 4.0 * f(points.at(i));
		}

		else
		{
			res += 2.0 * f(points.at(i));
		}
	}

	res *= (1.0 / 3.0) * h;
	
	return res;
}

std::vector<double> trapezio_ricorsivo(int j_max, double f(double x), double a, double b)
{
	// Dichiarazione variabili
	double h = 0.0;
	double N = 0.0;
	double sum = 0.0;
	std::vector<double> T(j_max);
	T.at(0) = 0.5 * (b - a) * (f(a) + f(b));

	for(int j = 1; j < j_max; ++j)
	{
		h = (b - a) / pow(2.0, static_cast<double>(j));
		N = pow(2.0, static_cast<double>(j)) + 1.0;

		sum = 0.0;

		for(int k = 1; k <= (N - 1)/2; ++k)
		{
			sum += f(a + (2*k - 1) * h);
		}

		T.at(j) = (0.5 * T.at(j-1) + h * sum);
	}

	return T;
}

double romberg(int j_max, int k_max, double f(double x), double a, double b)
{
	// Dichiarazione variabili
	double tmp = 0.0;
	std::vector<std::vector<double>> R(k_max, std::vector<double>(j_max)); // Matrice di k_max righe e j_max colonne
	R.at(0) = trapezio_ricorsivo(j_max, f, a, b); // Prima riga data dal metodo del trapezio ricorsivo

	// Formula iterativa di Romberg per le restanti righe
	for(int k = 1; k < k_max; ++k)
	{	
		for(int j = 1; j < j_max; ++j)
		{
			if(j >= k)
			{
		 		(R.at(k)).at(j) = (pow(4.0, static_cast<double>(k)) * ((R.at(k-1)).at(j)) - (R.at(k-1)).at(j-1)) / (pow(4.0, static_cast<double>(k)) - 1.0);
			}

			else
			{
				(R.at(k)).at(j) = 0.0;
			}
		}
	}

	// Stampa a schermo gli elementi di R
	for(int k = 0; k < k_max; ++k)
	{
		for(int j = 0; j < j_max; ++j)
		{
			std::cout << "R( " << k << ", " << j << "): " << (R.at(k)).at(j) << '\n';
		}
	}

	return R.at(k_max - 1).at(j_max - 1);
}

double formula_aperta_3punti(double f(double x), double a, double b)
{
	// Dichiarazione variabili
	int N = 3;
	double res = 0.0;
	double h = (b - a) / (static_cast<double>(N) - 1.0);
	std::vector<double> points = return_points(N, a, b);
	
	// Calcolo formula aperta
	res = 2.0 * h * f(points.at(1));

	return res;
}

double formula_aperta_6punti(double f(double x), double a, double b)
{
	// Dichiarazione variabili
	int N = 6;
	double res = 0.0;
	double h = (b - a) / (static_cast<double>(N) - 1.0);
	std::vector<double> points = return_points(N, a, b);
	
	// Calcolo formula aperta
	for(int i = 0; i < N; ++i)
	{
		if(i == 0 || i == (N - 1))
		{
			res += 0.0;
		}

		else if (i == 1 || i == 4)
		
			res += 11.0 * f(points.at(i));

		else
		{
			res += f(points.at(i));
		}
	}

	res *= (5.0/24.0) * h;

	return res;
}

double gauss(std::string file_name, int n_points, double f(double x))
{
	// Apre il file per leggere punti e pesi
	std::ifstream file;
	file.open(file_name, std::ifstream::in);

	// Dichiarazione variabili
	int n = 0;
	double weight = 0.0;
	double point = 0.0;
	double sum = 0.0;

	// Lettura file di testo
	while(true)
  	{
		file >> n >> point >> weight;

		if(n == n_points)	
		{
			sum += weight * f(point); // Calcolo integrale
		}

		if(file.eof() == true)
		{
			break;
		}
  	}

	file.close();

	return sum;
}
