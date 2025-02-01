// Librerie
#include "functions.h"
#include "es19_b.h"
#include "zeros.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <string>

int main(int argc, char ** argv)
{
    // Controllo argomenti da riga di comando
    if(argc != 3)
    {
        std::cout << "Utilizzo: ./c.out a b" << '\n';
        return 1;
    }
    
    else if(std::stod(argv[1]) > std::stod(argv[2]))
    {
        std::cout << "a deve essere minore di b." << '\n';
        return 1;
    }

    // Dichiarazione variabili
    int choice = 0;
    double zero = 0.0;
    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);
    double precision_bisezione = pow(10.0, -6.0); // Precisione per il metodo di bisezione
    double precision_newton = pow(10.0, -6.0); // Precisione per il metodo di Newton-Raphson
    int n_steps = 100000; // Numero di step per la ricerca di intervalli

    std::pair<std::vector<double>, std::vector<double>> estremi;
    std::vector<double> bisection_zeros;
    std::vector<double> newton_zeros;

    // Nomi dei file
    std::string bisection_zeros_file_name = "zeri_bisezione.txt";
    std::string newton_zeros_file_name = "zeri_newton.txt";

    // Scelta dell'operazione
    std::cout << "Scegliere tra le seguenti opzioni: " << '\n';
    std::cout << "[1]: Cerca gli intervalli in cui sono presenti zeri all'interno del range specificato" << '\n';
    std::cout << "[2]: Cerca uno zero nel range specificato e restituisce il suo valore se presente" << '\n';
    std::cout << "[3]: Determina tutti gli zeri della funzione nel range specificato" << '\n';
    std::cout << "--> ";

    std::cin >> choice;

    if(choice == 1)
    {
        trova_intervalli_void(f, a, b, n_steps);
    }

    else if(choice == 2)
    {
        std::cout << "Bisezione: x = " << bisezione(f, a, b, precision_bisezione) << '\n';
        std::cout << "Newton: x = " << newton(f, f_der, a, a, b, precision_newton) << '\n';
    }

    else if(choice == 3)
    {
        estremi = trova_intervalli(f, a, b, n_steps);

        std::cout << "--- BISEZIONE ---" << '\n';

        for(int i = 0; i < estremi.first.size(); ++i)
        {
            zero = bisezione(f, estremi.first.at(i), estremi.second.at(i), precision_bisezione);
            std::cout << "Trovato uno zero in [ " << estremi.first.at(i) << ", " << estremi.second.at(i) << " ]: x_" << i << " = " << zero << '\n';
            bisection_zeros.push_back(zero);
        }

        std::cout << "--- NEWTON-RAPHSON ---" << '\n';

        for(int i = 0; i < estremi.first.size(); ++i)
        {
            zero = newton(f, f_der, estremi.first.at(i), estremi.first.at(i), estremi.second.at(i), precision_newton);
            std::cout << "Trovato uno zero in [ " << estremi.first.at(i) << ", " << estremi.second.at(i) << " ]: x_" << i << " = " << zero << '\n';
            newton_zeros.push_back(zero);
        }

        // Stampa su file gli zeri
        scrivi_su_file(bisection_zeros_file_name, bisection_zeros);
        scrivi_su_file(newton_zeros_file_name, newton_zeros);
    }

    else 
    {
        std::cout << "La scelta non è valida." << '\n';
        return 1;
    }

    return 0;
}