// Librerie
#include <vector>
#include <math.h>

// Definizione delle componenti di f
double f_0(double x, std::vector<double> y)
{
    return y.at(1);
}

double f_1(double x, std::vector<double> y)
{
    // Parametri
    double alpha_par = 0.5;
    double beta_par = 0.63;
    double gamma_par = 0.03;

    return (-1.0) * gamma_par * y.at(1) + (beta_par * cos(x) - alpha_par) * sin(y.at(0));
}

std::vector<double> f(double x, std::vector<double> y)
{
    // Componenti di f
    std::vector<double> componenti = {f_0(x, y), f_1(x, y)};

    return componenti;
}