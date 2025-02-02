// Librerie
#include "es20.h"
#include <math.h>

int main(int argc, char ** argv)
{
    // Dichiarazione variabili
    double x_min = -2.0; // Intervallo su asse reale
    double x_max = 2.0;
    double y_min = -2.0; // Intervallo su asse immaginario
    double y_max = 2.0;
    int K = 50; // Numero massimo di iterazioni di Newton
    int N = 1000; // Dimensione della griglia
    double eps = pow(10.0, -3.0);

    newton_fractal(x_min, x_max, y_min, y_max, N, K, eps);

    return 0;
}