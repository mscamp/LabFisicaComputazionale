// Librerie
#include <vector>
#include <math.h>

double distanza(std::vector<double> v_1, std::vector<double> v_2)
{
    // Definizione variabili
    double dist = 0.0;

    for(int i = 0; i < v_1.size(); ++i)
    {
        dist += pow((v_1.at(i) - v_2.at(i)), 2.0);
    }

    dist = sqrt(dist);

    return dist;
}

double g(double m_b, double m_c, std::vector<double> r_a, std::vector<double> r_b, std::vector<double> r_c, int index)
{
    return (-1.0) * m_b * ((r_a.at(index) - r_b.at(index)) / pow(distanza(r_a, r_b), 3.0)) + (-1.0) * m_c * ((r_a.at(index) - r_c.at(index)) / pow(distanza(r_a, r_c), 3.0));
}

// Definizione delle componenti di f
// x_1
double f_0(double x, std::vector<double> y)
{
    return y.at(9);
}

// y_1
double f_1(double x, std::vector<double> y)
{
    return y.at(10);
}

// z_1
double f_2(double x, std::vector<double> y)
{
    return y.at(11);
}

// x_2
double f_3(double x, std::vector<double> y)
{
    return y.at(12);
}

// y_2
double f_4(double x, std::vector<double> y)
{
    return y.at(13);
}

// z_2
double f_5(double x, std::vector<double> y)
{
    return y.at(14);
}

// x_3
double f_6(double x, std::vector<double> y)
{
    return y.at(15);
}

// y_3
double f_7(double x, std::vector<double> y)
{
    return y.at(16);
}

// z_3
double f_8(double x, std::vector<double> y)
{
    return y.at(17);
}

// v_1x
double f_9(double x, std::vector<double> y)
{
    // Parametri
    double m_2 = 0.4;
    std::vector<double> r_1 = {y.at(0), y.at(1), y.at(2)};
    std::vector<double> r_2 = {y.at(3), y.at(4), y.at(5)};
    std::vector<double> r_3 = {y.at(6), y.at(7), y.at(8)};

    return g(m_2, m_2, r_1, r_2, r_3, 0);
}

// v_1y
double f_10(double x, std::vector<double> y)
{
    // Parametri
    double m_2 = 0.4;
    std::vector<double> r_1 = {y.at(0), y.at(1), y.at(2)};
    std::vector<double> r_2 = {y.at(3), y.at(4), y.at(5)};
    std::vector<double> r_3 = {y.at(6), y.at(7), y.at(8)};

    return g(m_2, m_2, r_1, r_2, r_3, 1);
}

// v_1z
double f_11(double x, std::vector<double> y)
{
    // Parametri
    double m_2 = 0.4;
    std::vector<double> r_1 = {y.at(0), y.at(1), y.at(2)};
    std::vector<double> r_2 = {y.at(3), y.at(4), y.at(5)};
    std::vector<double> r_3 = {y.at(6), y.at(7), y.at(8)};

    return g(m_2, m_2, r_1, r_2, r_3, 2);
}

// v_2x
double f_12(double x, std::vector<double> y)
{
    // Parametri
    double m_1 = 1.6;
    double m_2 = 0.4;
    std::vector<double> r_1 = {y.at(0), y.at(1), y.at(2)};
    std::vector<double> r_2 = {y.at(3), y.at(4), y.at(5)};
    std::vector<double> r_3 = {y.at(6), y.at(7), y.at(8)};

    return g(m_1, m_2, r_2, r_1, r_3, 0);
}

// v_2y
double f_13(double x, std::vector<double> y)
{
    // Parametri
    double m_1 = 1.6;
    double m_2 = 0.4;
    std::vector<double> r_1 = {y.at(0), y.at(1), y.at(2)};
    std::vector<double> r_2 = {y.at(3), y.at(4), y.at(5)};
    std::vector<double> r_3 = {y.at(6), y.at(7), y.at(8)};

    return g(m_1, m_2, r_2, r_1, r_3, 1);
}

// v_2z
double f_14(double x, std::vector<double> y)
{
    // Parametri
    double m_1 = 1.6;
    double m_2 = 0.4;
    std::vector<double> r_1 = {y.at(0), y.at(1), y.at(2)};
    std::vector<double> r_2 = {y.at(3), y.at(4), y.at(5)};
    std::vector<double> r_3 = {y.at(6), y.at(7), y.at(8)};

    return g(m_1, m_2, r_2, r_1, r_3, 2);
}

// v_3x
double f_15(double x, std::vector<double> y)
{
    // Parametri
    double m_1 = 1.6;
    double m_2 = 0.4;
    std::vector<double> r_1 = {y.at(0), y.at(1), y.at(2)};
    std::vector<double> r_2 = {y.at(3), y.at(4), y.at(5)};
    std::vector<double> r_3 = {y.at(6), y.at(7), y.at(8)};

    return g(m_1, m_2, r_3, r_1, r_2, 0);
}

// v_3y
double f_16(double x, std::vector<double> y)
{
    // Parametri
    double m_1 = 1.6;
    double m_2 = 0.4;
    std::vector<double> r_1 = {y.at(0), y.at(1), y.at(2)};
    std::vector<double> r_2 = {y.at(3), y.at(4), y.at(5)};
    std::vector<double> r_3 = {y.at(6), y.at(7), y.at(8)};

    return g(m_1, m_2, r_3, r_1, r_2, 1);
}

// v_3z
double f_17(double x, std::vector<double> y)
{
    // Parametri
    double m_1 = 1.6;
    double m_2 = 0.4;
    std::vector<double> r_1 = {y.at(0), y.at(1), y.at(2)};
    std::vector<double> r_2 = {y.at(3), y.at(4), y.at(5)};
    std::vector<double> r_3 = {y.at(6), y.at(7), y.at(8)};

    return g(m_1, m_2, r_3, r_1, r_2, 2);
}

std::vector<double> f(double x, std::vector<double> y)
{
    // Componenti di f
    std::vector<double> componenti = {
        f_0(x, y), // x_1
        f_1(x, y), // y_1
        f_2(x, y), // z_1
        f_3(x, y), // x_2
        f_4(x, y), // y_2
        f_5(x, y), // z_2
        f_6(x, y), // x_3
        f_7(x, y), // y_3
        f_8(x, y), // z_3
        f_9(x, y), // v_1x
        f_10(x, y), // v_1y
        f_11(x, y), // v_1z
        f_12(x, y), // v_2x
        f_13(x, y), // v_2y
        f_14(x, y), // v_2z
        f_15(x, y), // v_3x
        f_16(x, y), // v_3y
        f_17(x, y)  // v_3z
    };

    return componenti;
}

double energia_totale(std::vector<double> mass, std::vector<double> y)
{
    // Definizione variabili
    double K = 0.0;
    double U = 0.0;
    double dist = 0.0;
    std::vector<double> r_1 = {y.at(0), y.at(1), y.at(2)};
    std::vector<double> r_2 = {y.at(3), y.at(4), y.at(5)};
    std::vector<double> r_3 = {y.at(6), y.at(7), y.at(8)};
    std::vector<std::vector<double>> rs = {r_1, r_2, r_3};

    for(int i = 0; i < 3; ++i)
    {
        K += 0.5 * mass.at(i) * (pow(y.at(9 + 3 * i), 2.0) + pow(y.at(10 + 3 * i), 2.0) + pow(y.at(11 + 3 * i), 2.0));

        for(int j = 0; j < i; ++j)
        {
            U += (-1.0) * mass.at(i) * mass.at(j) * (1.0 / distanza(rs.at(i), rs.at(j)));
        }
    }

    return (K + U);
}