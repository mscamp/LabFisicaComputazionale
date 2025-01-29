// Librerie
#include <vector>

// Definizione delle componenti di f
double f_0(double x, std::vector<double> y)
{
    // Parametri
    double sigma_par = 10.0;

    return sigma_par * (y.at(1) - y.at(0));
}

double f_1(double x, std::vector<double> y)
{
    // Parametri
    double rho_par = 28.0;

    return y.at(0) * (rho_par - y.at(2)) - y.at(1);
}

double f_2(double x, std::vector<double> y)
{
    // Parametri
    double beta_par = (8.0 / 3.0);

    return y.at(0) * y.at(1) + (-1.0) * beta_par * y.at(2);
}

std::vector<double> f(double x, std::vector<double> y)
{
    // Componenti di f
    std::vector<double> componenti = {f_0(x, y), f_1(x, y), f_2(x, y)};

    return componenti;
}