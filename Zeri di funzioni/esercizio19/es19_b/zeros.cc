// Librerie
#include <iostream>
#include <vector>
#include <math.h>

void trova_intervalli_void(double f(double), double a, double b, int n_steps)
{
    // Dichiarazione variabili
    int contatore_zeri = 0;
    double a_next = 0.0;
    double step = (b - a) / static_cast<double>(n_steps);

    for(int i = 0; i < n_steps; ++i)
    {
        a_next = a + step;

        if(f(a) * f(a_next) < 0.0)
        {
            ++contatore_zeri;
            std::cout << "Trovato uno zero nell'intervallo [ " << a << ", " << a_next << " ]" << '\n';
        }

        a = a_next;
    }

    if(contatore_zeri == 0)
    {
        std::cout << "Non sono stati rilevati zeri nel range specificato." << '\n';
    }

    std::cout << "Sono stati trovati " << contatore_zeri << " zeri nel range specificato." << '\n';
}

std::pair<std::vector<double>, std::vector<double>> trova_intervalli(double f(double), double a, double b, int n_steps)
{
    // Dichiarazione variabili
    int contatore_zeri = 0;
    double a_next = 0.0;
    double step = (b - a) / static_cast<double>(n_steps);
    std::pair<std::vector<double>, std::vector<double>> estremi;

    for(int i = 0; i < n_steps; ++i)
    {
        a_next = a + step;

        if(f(a) * f(a_next) < 0.0)
        {
            ++contatore_zeri;
            std::cout << "Trovato uno zero nell'intervallo [ " << a << ", " << a_next << " ]" << '\n';
            estremi.first.push_back(a);
            estremi.second.push_back(a_next);
        }

        a = a_next;
    }

    if(contatore_zeri == 0)
    {
        std::cout << "Non sono stati rilevati zeri nel range specificato." << '\n';
        return estremi;
    }

    std::cout << "Sono stati trovati " << contatore_zeri << " zeri nel range specificato." << '\n';

    return estremi;
}

double bisezione(double f(double), double a, double b, double precision)
{
    // Definizione variabili
	double x_m;

	if(f(a) * f(b) < 0.0)
	{
	    while((b - a) > precision)
	    {
		    x_m = (a + b) / 2.0;

			if(f(x_m) * f(b) < 0.0)
			{
				a = x_m;	
			}

			else if(f(a) * f(x_m) < 0.0)
			{
				b = x_m;
			}

			else if(f(x_m) == 0.0)
			{
			    return x_m;
			}	
		}
	}
	
	else
	{
		std::cout << "Non ci sono zeri nell'intervallo dato." << '\n';
		return 1;
	}

	return x_m;
}

double newton(double f(double), double f_der(double), double x, double a, double b, double precision)
{
	// Dichiarazione variabili
	double delta = (-1.0) * (f(x) / f_der(x));

	while(fabs(delta) > precision)	
	{
		delta = (-1.0) * (f(x) / f_der(x));
		x += delta;
	}

	if(x >= a && x <= b)
	{
		return x;
	}

	else 
	{
		std::cout << "Il metodo ha trovato uno zero diverso da quello richiesto." << '\n';
		return 1;
	}
}