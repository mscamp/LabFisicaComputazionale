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
    double gamma_par = 1.0;
    double A_par = 1.0;

    return (-1.0) * sin(y.at(0)) + (-1.0) * gamma_par * y.at(1) + A_par * sin((2.0 / 3.0) * x);
}

std::vector<double> f(double x, std::vector<double> y)
{
    // Componenti di f
    std::vector<double> componenti = {f_0(x, y), f_1(x, y)};

    return componenti;
}