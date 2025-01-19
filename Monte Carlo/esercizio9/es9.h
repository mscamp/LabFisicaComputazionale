// Librerie
#include <vector>
#include <string>

double rand_range(double a, double b, bool estremi);
std::vector<double> rand_TCL(double a, double b, int M, int N, bool estremi);
void scrivi_su_file(std::string file_name, std::vector<double> v);
double momento_k_campione(std::vector<double> sample, int k);
std::pair<double, double> momenti_gaussiana(int N);