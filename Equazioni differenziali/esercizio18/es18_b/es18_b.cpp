// Librerie
#include "functions.h"
#include "es18_b.h"
#include "diffeq.h"
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char ** argv)
{
    // Controllo degli argomenti passati da riga di comando
    if(argc != 2)
    {
        std::cout << "Utilizzo: ./c.out t_steps" << '\n';
        return 1;
    }

    else if(std::stoi(argv[1]) <= 0)
    {
        std::cout << "t_steps deve essere strettamente maggiore di zero." << '\n';
        return 1;
    }

    // Dichiarazione variabili
    int M = 18; // Dimensione del sistema
    double t_start = 0.0; // Istante iniziale
    double t_end = 30.0; // Istante finale
    int t_steps = std::stoi(argv[1]);
    std::vector<double> mass = {1.6, 0.4, 0.4};

    std::vector<double> condizioni_iniziali = {

        1.0,    // x_1
        0.0,    // y_1
        0.0,    // z_1

        -1.0,   // x_2
        0.0,    // y_2
        0.0,    // z_2

        0.0,    // x_3
        0.0,    // y_3
        0.0,    // z_3

        0.0,    // v_1x
        0.4,   // v_1y
        0.0,   // v_1z

        0.0,   // v_2x
        -0.8, // v_2y
        0.7,  // v_2z

        0.0,   // v_3x
        -0.8,   // v_3y
        -0.7    // v_3z
        
    };

    std::pair<std::vector<double>, std::vector<std::vector<double>>> y_sol_RK_4; // Soluzione numerica
    std::vector<double> * E_tot_ptr = new std::vector<double>(t_steps + 1); // Energia totale

    // Nomi dei file
    std::string file_name_RK_4;
    std::string file_name_energia = "energia_totale.txt";

    // Valore iniziale dell'energia
    (*E_tot_ptr).at(0) = energia_totale(mass, condizioni_iniziali);

    // Evoluzione
    y_sol_RK_4 = integratore(M, condizioni_iniziali, f, t_start, t_end, t_steps, "RK4", E_tot_ptr, mass);

    // Stampa su file
    for(int m = 0; m < M; ++m)
    {
        // Nomi dei file
        file_name_RK_4 = "RK4_" + std::to_string(m) + '_' + std::to_string(t_steps) + ".txt";

        scrivi_su_file(file_name_RK_4, y_sol_RK_4.first, y_sol_RK_4.second.at(m));
    }

    scrivi_su_file(file_name_energia, y_sol_RK_4.first, *E_tot_ptr);

    // Deallocazione memoria
    delete E_tot_ptr;

    return 0;
}