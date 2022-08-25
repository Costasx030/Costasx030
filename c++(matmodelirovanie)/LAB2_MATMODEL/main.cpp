#include <iostream>
#include <cmath>

const double Yt = 0.05 * 10.2678;
const long N = 4294967296 / 1000;
const int T = 1000;
double Muller();

double Summary(double tau, double b, const double yE[])
{
    double
    x = 5,
    k = 2,
    y = 0,
    z1 = 0,
    z2 = 0,
    z3 = 0,
    h = 0.05,
    dz1 = 0,
    dz2 =0,
    dz3 = 0,

CF = 0;

for (int t = 0; t < T; ++t) {

    dz1 = z1 + h * z2;
    dz2 = z2 + h * z3;
    dz3 = z3 + h * (5 - z1 - ((tau / 2) + b) * z2 - ((tau * b) / 2 + (tau * tau / 6)) * z3) * 6 / (tau * tau * b);

    y = k * z1 - (k * tau / 2) * z2 + (k * tau * tau / 6) * z3;

    z1 = dz1;
    z2 = dz2;
    z3 = dz3;

//std::cout << y << '\n';


     CF += (yE[t] - y)*(yE[t] - y);

}
   CF*= (1.0/(T +1 ));
//    std::cout << CF << '\n';
return CF;
}
double (*F)(double, double, const double*) = Summary;

int main() {

    double
            k = 2,
            st = 0.05,
            tauE = 4,
            bE = 2,
            z1E = 0,
            z2E = 0,
            z3E = 0,
            dz1E = 0,
            dz2E = 0,
            dz3E = 0,
            yE[T]{0};
    for (int t = 0; t < T; ++t)
    {
        dz1E = z1E + st * z2E;
        dz2E = z2E + st * z3E;
        dz3E = z3E + st * (5 - z1E - ((tauE / 2) + bE) * z2E - ((tauE * bE) / 2 + (tauE * tauE / 6)) * z3E) * 6 /
                     (tauE * tauE * bE);

        yE[t] = k * z1E - (k * tauE / 2) * z2E + (k * tauE * tauE / 6) * z3E + Muller();
//        yE[t] = k * z1E - (k * tauE / 2) * z2E + (k * tauE * tauE / 6) * z3E;

        z1E = dz1E;
        z2E = dz2E;
        z3E = dz3E;

    }
    for (int k = 0; k < T/10; ++k) {
        std::cout << k*10 << '\t' << yE[k*10] << '\n';
    }

    //Объявление переменных
    const int SIZE = 2,
            OPT_N = 10000;

    int axis = 0,
            sigma = 0;
    double s = 0.5, e = 0.00001, F0 = 0;
    double X[SIZE]{15,1};

//Ввод переменных:
    std::cout << "Entered tau = , b = , s = 0.5, e = 0.00001 " << '\n';
//    std::cin >> X[0] >> X[1] >> s >> e;
//Вычисление функции:
    F0 = F(X[0], X[1], yE);
//Создание вектора шагов:
    double h[SIZE];
    for (double &i: h) i = s;
    //Движение по осям:
    for (int j = 1; j < OPT_N; ++j) {
        X[axis] += h[axis];
        // Условие прерывания по точности:
        if (abs(F(X[0], X[1], yE) - F0) < e) sigma += 1;
        else sigma = 0;
        if (sigma > 10) break;
    //Условия направления и шага:
        if (F(X[0], X[1], yE) <= F0) {
            F0 = F(X[0], X[1], yE);
            h[axis] *= 3;
            axis += 1;
            if (axis >= SIZE) axis = 0;
        }
        else {
            X[axis] -= h[axis];
            h[axis] *= -0.5;
            axis += 1;
            if (axis >= SIZE) axis = 0;
        }
    }
  //  std::cout << "x is  " << X[0] << "  Y is " << X[1] << '\n';


    return 0;
}
double Muller() {
    double randomNumber = 0,
            randNumber2 = 0,
            x = 0,
            Z1 = 0,
            Z2 = 0;

    randomNumber = arc4random() / pow(2, 32);
    randNumber2 = arc4random() / pow(2, 32);
    Z1 = cos(2 * M_PI * randomNumber) * sqrt(-2.0 * log(randNumber2));
    //  Z2 = sin(2 * M_PI * randomNumber)* sqrt(-2 * log(randNumber2));
    //    Масштабирование
    x = Z1 * Yt;
    return x;
}



