// Librerie
#include <vector>

void trova_intervalli_void(double f(double), double a, double b, int n_steps);
std::pair<std::vector<double>, std::vector<double>> trova_intervalli(double f(double), double a, double b, int n_steps);
double bisezione(double f(double), double a, double b, double precision);
double newton(double f(double), double f_der(double), double x, double a, double b, double precision);