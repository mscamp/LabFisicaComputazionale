// Librerie
#include <math.h>

// Definizione della funzione
double f(double x)
{
    return (46189.0 * pow(x, 10.0) + (-1.0) * 109395.0 * pow(x, 8.0) + 90090.0 * pow(x, 6.0) + (-1.0) * 30030.0 * pow(x, 4.0) + 3465.0 * x * x + (-1.0) * 63.0) / 256.0;
}

double f_der(double x)
{
    return (55.0 / 128.0) * x * (4199.0 * pow(x, 8.0) + (-1.0) * 7956.0 * pow(x, 6.0) + 4914.0 * pow(x, 4.0) + (-1.0) * 1092.0 * x * x + 63.0);
}