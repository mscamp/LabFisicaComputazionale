// Librerie
#include <string>
#include <vector>

std::vector<double> return_points(int N, double a, double b);
double trapezio_estesa(int N, double f(double x), double a, double b);
double simpson_estesa(int N, double f(double x), double a, double b); 
std::vector<double> trapezio_ricorsivo(int j_max, double f(double x), double a, double b);
double romberg(int j_max, int k_max, double f(double x), double a, double b);
double formula_aperta_3punti(double f(double x), double a, double b);
double formula_aperta_6punti(double f(double x), double a, double b);
double gauss(std::string file_name, int n_points, double f(double x));