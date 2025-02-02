// Librerie
#include <complex>
#include <string>
#include <vector>

void scrivi_su_file(std::string file_name, std::vector<double> x, std::vector<double> y, std::vector<int> js);
std::complex<double> newton(std::complex<double> z);
void newton_fractal(double x_min, double x_max, double y_min, double y_max, int N, int K, double eps);