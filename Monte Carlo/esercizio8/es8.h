// Librerie
#include <vector>
#include <string>

double rand_range(double min, double max);
std::vector<double> genera_punto(int dim, double min, double max);
double norma(std::vector<double> point);
int fattoriale(int n);
int fattoriale_doppio_dispari(int n);
double sfera_midpoint(int m, int n_intervals, double * time_midpoint);
std::pair<double, double> sfera_montecarlo(int m, int n_points, double * time_mc);
double analytic_value(int m);
void output_to_file(std::string name, std::vector<double> v);