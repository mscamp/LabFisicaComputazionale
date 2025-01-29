// Librerie
#include <iostream>
#include <string>
#include <vector>

std::vector<double> Eulero(int M, double t, std::vector<std::vector<double>> y, double h, double t_index, std::vector<double> f(double x, std::vector<double> vars))
{
    // Dichiarazione variabili
    std::vector<double> k_1(M);
    std::vector<double> t_snapshot_prev(M);
    std::vector<double> t_snapshot_next(M);

    // Prende lo snapshot precedente
    for(int m = 0; m < M; ++m) 
    {
        t_snapshot_prev.at(m) = ((y.at(m)).at(t_index - 1));
    }

    // Riempie il vettore degli incrementi
    for(int m = 0; m < M; ++m)
    {
        k_1.at(m) = (h * f(t, t_snapshot_prev).at(m));
    }

    // Evoluzione della soluzione
    for(int m = 0; m < M; ++m)
    {
        t_snapshot_next.at(m) = (t_snapshot_prev.at(m) + k_1.at(m));
    }

    return t_snapshot_next;
}

std::vector<double> RK_2(int M, double t, std::vector<std::vector<double>> y, double h, double t_index, std::vector<double> f(double x, std::vector<double> vars))
{
    // Dichiarazione variabili
    std::vector<double> k_1(M);
    std::vector<double> k_2(M);
    std::vector<double> tmp(M);
    std::vector<double> t_snapshot_prev(M);
    std::vector<double> t_snapshot_next(M);

    // Prende lo snapshot precedente
    for(int m = 0; m < M; ++m) 
    {
        t_snapshot_prev.at(m) = ((y.at(m)).at(t_index - 1));
    }

    // Riempie il vettore degli incrementi k1
    for(int m = 0; m < M; ++m)
    {
        k_1.at(m) = (h * f(t, t_snapshot_prev).at(m));
    }

    // Step intermedio
    for(int m = 0; m < M; ++m)
    {
        tmp.at(m) = (t_snapshot_prev.at(m) + 0.5 * k_1.at(m));
    }

    // Riempie il vettore degli incrementi k2
    for(int m = 0; m < M; ++m)
    {
        k_2.at(m) = (h * f(t, tmp).at(m));
    }

    // Evoluzione della soluzione
    for(int m = 0; m < M; ++m)
    {
        t_snapshot_next.at(m) = (t_snapshot_prev.at(m) + k_2.at(m));
    }

    return t_snapshot_next;
}

std::vector<double> RK_4(int M, double t, std::vector<std::vector<double>> y, double h, double t_index, std::vector<double> f(double x, std::vector<double> vars))
{
    // Dichiarazione variabili
    std::vector<double> k_1(M);
    std::vector<double> k_2(M);
    std::vector<double> k_3(M);
    std::vector<double> k_4(M);
    std::vector<double> tmp(M);
    std::vector<double> t_snapshot_prev(M);
    std::vector<double> t_snapshot_next(M);

    // Prende lo snapshot precedente
    for(int m = 0; m < M; ++m) 
    {
        t_snapshot_prev.at(m) = ((y.at(m)).at(t_index - 1));
    }

    // Riempie il vettore degli incrementi k1
    for(int m = 0; m < M; ++m)
    {
        k_1.at(m) = (h * f(t, t_snapshot_prev).at(m));
    }

    // Step intermedio
    for(int m = 0; m < M; ++m)
    {
        tmp.at(m) = (t_snapshot_prev.at(m) + 0.5 * k_1.at(m));
    }

    // Riempie il vettore degli incrementi k2
    for(int m = 0; m < M; ++m)
    {
        k_2.at(m) = (h * f(t, tmp).at(m));
    }

    // Step intermedio
    for(int m = 0; m < M; ++m)
    {
        tmp.at(m) = (t_snapshot_prev.at(m) + 0.5 * k_2.at(m));
    }

    // Riempie il vettore degli incrementi k3
    for(int m = 0; m < M; ++m)
    {
        k_3.at(m) = (h * f(t, tmp).at(m));
    }

    // Step intermedio
    for(int m = 0; m < M; ++m)
    {
        tmp.at(m) = (t_snapshot_prev.at(m) + k_3.at(m));
    }

    // Riempie il vettore degli incrementi k4
    for(int m = 0; m < M; ++m)
    {
        k_4.at(m) = (h * f(t, tmp).at(m));
    }

    // Evoluzione della soluzione
    for(int m = 0; m < M; ++m)
    {
        t_snapshot_next.at(m) = (t_snapshot_prev.at(m) + (1.0 / 6.0) * (k_1.at(m) + 2.0 * k_2.at(m) + 2.0 * k_3.at(m) + k_4.at(m)));
    }

    return t_snapshot_next;
}

std::pair<std::vector<double>, std::vector<std::vector<double>>> integratore(int M, std::vector<double> condizioni_iniziali, std::vector<double> f(double x, std::vector<double> vars), double t_start, double t_end, int t_steps, std::string choice)
{
    // Dichiarazione variabili
    double t = t_start;
    double h = (t_end - t_start) / static_cast<double>(t_steps);
    std::vector<double> t_snapshot; // "Snapshot" al tempo t

    // Soluzione numerica
    std::pair<std::vector<double>, std::vector<std::vector<double>>> y = {
        {t_start},
        {{condizioni_iniziali.at(0)}, {condizioni_iniziali.at(1)}, {condizioni_iniziali.at(2)}}
    }; 

    // Scelta del metodo
    if(choice == "Eulero")
    {
        for(int k = 1; k <= t_steps; ++k)
        {
            t += h;
            t_snapshot = Eulero(M, t, y.second, h, k, f);
            
            for(int m = 0; m < M; ++m)
            {
                (y.second.at(m)).push_back(t_snapshot.at(m));
            }

            y.first.push_back(t);
        }
    }

    else if(choice == "RK2") 
    {
        for(int k = 1; k <= t_steps; ++k)
        {
            t += h;
            t_snapshot = RK_2(M, t, y.second, h, k, f);
            
            for(int m = 0; m < M; ++m)
            {
                (y.second.at(m)).push_back(t_snapshot.at(m));
            }

            y.first.push_back(t);
        }
    }

    else if(choice == "RK4")
    {
        for(int k = 1; k <= t_steps; ++k)
        {
            t += h;
            t_snapshot = RK_4(M, t, y.second, h, k, f);
            
            for(int m = 0; m < M; ++m)
            {
                (y.second.at(m)).push_back(t_snapshot.at(m));
            }

            y.first.push_back(t);
        }
    }

    else 
    {
        std::cout << "Il metodo inserito non è valido." << '\n';
    }

    return y;
}
        