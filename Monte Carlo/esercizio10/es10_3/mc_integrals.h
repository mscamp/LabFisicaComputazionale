// Librerie
#include <string>
#include <vector>

double rand_range(double min, double max);
std::pair<double, double> monte_carlo(double f(double x), double a, double b, int N);
std::pair<double, double> hit_or_miss(double g(double), double a, double b, double y_min, double y_max, int N);