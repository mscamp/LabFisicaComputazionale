// Librerie
#include <vector>

// Definizione delle componenti di f
double f_0(double x, std::vector<double> y)
{
    return y.at(1);
}

double f_1(double x, std::vector<double> y)
{
    return (-1.0) * y.at(0);
}

std::vector<double> f(double x, std::vector<double> y)
{
    // Componenti di f
    std::vector<double> componenti = {f_0(x, y), f_1(x, y)};

    return componenti;
}