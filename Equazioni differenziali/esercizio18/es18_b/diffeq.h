// Librerie
#include <string>
#include <vector>

std::vector<double> Eulero(int M, double t, std::vector<std::vector<double>> y, double h, double t_index, std::vector<double> f(double x, std::vector<double> vars));
std::vector<double> RK_2(int M, double t, std::vector<std::vector<double>> y, double h, double t_index, std::vector<double> f(double x, std::vector<double> vars));
std::vector<double> RK_4(int M, double t, std::vector<std::vector<double>> y, double h, double t_index, std::vector<double> f(double x, std::vector<double> vars));
std::pair<std::vector<double>, std::vector<std::vector<double>>> integratore(int M, std::vector<double> condizioni_iniziali, std::vector<double> f(double x, std::vector<double> vars), double t_start, double t_end, int t_steps, std::string choice, std::vector<double> * E_ptr, std::vector<double> mass);