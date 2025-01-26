// Librerie
#include "functions.h"
#include "es14.h"
#include "diffeq.h"
#include <string>
#include <vector>
#include <numbers>

int main(int argc, char ** argv)
{
    // Dichiarazione variabili
    int M = 2; // Dimensione del sistema
    double t_start = 0.0; // Istante iniziale
    double t_end = 2 * std::numbers::pi_v<double>; // Istante finale
    int t_steps_spacing = 10;
    int max_iter = 200;
    std::vector<double> condizioni_iniziali = {0.0, 1.0};
    std::pair<std::vector<double>, std::vector<std::vector<double>>> y_sol_eulero; // Soluzioni numeriche
    std::pair<std::vector<double>, std::vector<std::vector<double>>> y_sol_RK_2;
    std::pair<std::vector<double>, std::vector<std::vector<double>>> y_sol_RK_4;

    // Nomi dei file
    std::string file_name_eulero;
    std::string file_name_RK_2;
    std::string file_name_RK_4;

    // Ciclo sul passo di integrazione
    for(int t_steps = t_steps_spacing; t_steps <= max_iter; t_steps += t_steps_spacing)
    {
        // Evoluzione
        y_sol_eulero = integratore(M, condizioni_iniziali, f, t_start, t_end, t_steps, "Eulero");
        y_sol_RK_2 = integratore(M, condizioni_iniziali, f, t_start, t_end, t_steps, "RK2");
        y_sol_RK_4 = integratore(M, condizioni_iniziali, f, t_start, t_end, t_steps, "RK4");

        // Stampa su file
        for(int m = 0; m < M; ++m)
        {
            // Nomi dei file
            file_name_eulero = "Eulero_" + std::to_string(m) + '_' + std::to_string(t_steps) + ".txt";
            file_name_RK_2 = "RK2_" + std::to_string(m) + '_' + std::to_string(t_steps) + ".txt";
            file_name_RK_4 = "RK4_" + std::to_string(m) + '_' + std::to_string(t_steps) + ".txt";

            scrivi_su_file(file_name_eulero, y_sol_eulero.first, y_sol_eulero.second.at(m));
            scrivi_su_file(file_name_RK_2, y_sol_RK_2.first, y_sol_RK_2.second.at(m));
            scrivi_su_file(file_name_RK_4, y_sol_RK_4.first, y_sol_RK_4.second.at(m));
        }

    }

    return 0;
}