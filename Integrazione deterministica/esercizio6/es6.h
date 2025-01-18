// Librerie
#include <string>
#include <vector>

void output_scarto_to_file(std::string name, std::vector<int> v, double eps, double a, double b, double analytic_val, std::string choice);
void stampa_risultati(int N, std::vector<int> N_vec, int j_max, int k_max, double eps, double a, double b, double analytic_value, std::string f_hermite, std::string f_laguerre_alpha_zero);