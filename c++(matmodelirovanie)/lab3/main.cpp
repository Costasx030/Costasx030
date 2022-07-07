

#include <iostream>
#include <fstream>
#include <cmath>

const double Yt = 0.05 * 10.2678;
const long N = 4294967296 / 1000;

double Muller();

double CPT();

double Randomizing();

void checkGen(double(*)(), double, double);

int main() {


        std::ifstream in("input.txt");

        if (!in.is_open())
        {
            std::cerr << "File can not be opened\n";
            return 1;
        }

            int row = 0, col = 0;

            std::cout << "Please enter number of rows" << '\n';
            std::cin >> row;
            std::cout << "Please enter number of columns" << '\n';
            std::cin >> col;

    while (!in.eof()) {
        double **matrix = new double *[row];
        for (int i = 0; i < row; ++i) {
            matrix[i] = new double[col];
            for (int j = 0; j < col; ++j) {
                in >> matrix[i][j];
                std::cout << std::setw(10) << matrix[i][j];
            }
            std::cout << '\n';
        }
        in.close();
//        }
        //Зашумление графика
        for (int i = 0; i < row; ++i) {
                matrix[i][1] += Muller();
            std::cout   << matrix[i][1] << '\n';
        }
    }

//        Двумерные динамические массивы. Освобождение памяти
//        for (int i = 0; i < row; ++i) {
//            delete[] matrix[i];
//        }
//        delete[] matrix;



        return 0;
}

double CPT() {

    double randSum = 0, Z = 0, x = 0;
    int N = 100;
    for (int i = 1; i < N; ++i) {
        randSum += arc4random() / pow(2, 32);
    }
    Z = (randSum - 0.5 * N) / (sqrt(N / 12.0));
//     std::cout << "Z:   " << Z << '\n';
    //    Масштабирование
    x = Z * Yt;
    return x;
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

void checkGen(double (*randomize)(), double Range, double L)
{
    double randomNumber = 0,
            randSum = 0,
            difRandom = 0,
            x = 0,

            m_r = 0,
            D_r = 0,
            sigma = 0;
    int count1 = 0,
            count2 = 0,
            count3 = 0,
            count4 = 0,
            count5 = 0,
            count6 = 0,
            count7 = 0,
            count8 = 0,
            count9 = 0,
            count10 = 0;

    //Вычисление мат ожидания:
    for (long i = 1; i < N; ++i) {

//
        randomNumber = randomize();
        if (randomNumber >= L && randomNumber <= L + 0.1 * Range) count1 += 1;
        else if (randomNumber > L + 0.1 * Range && randomNumber <= L + 0.2 * Range) count2 += 1;
        else if (randomNumber > L + 0.2 * Range && randomNumber <= L + 0.3 * Range) count3 += 1;
        else if (randomNumber > L + 0.3 * Range && randomNumber <= L + 0.4 * Range) count4 += 1;
        else if (randomNumber > L + 0.4 * Range && randomNumber <= L + 0.5 * Range) count5 += 1;
        else if (randomNumber > L + 0.5 * Range && randomNumber <= L + 0.6 * Range) count6 += 1;
        else if (randomNumber > L + 0.6 * Range && randomNumber <= L + 0.7 * Range) count7 += 1;
        else if (randomNumber > L + 0.7 * Range && randomNumber <= L + 0.8 * Range) count8 += 1;
        else if (randomNumber > L + 0.8 * Range && randomNumber <= L + 0.9 * Range) count9 += 1;
        else if (randomNumber > L + 0.9 * Range && randomNumber <= L + 1 * Range) count10 += 1;
//         else std::cout << "randomNumber is abnormal:   " << randomNumber << '\n';


        randSum += randomNumber;
    }
    // Распределение:
    std::cout << "dispersion by columns:   " << '\n' << count1 << '\n';
    std::cout << count2 << '\n';
    std::cout << count3 << '\n';
    std::cout << count4 << '\n';
    std::cout << count5 << '\n';
    std::cout << count6 << '\n';
    std::cout << count7 << '\n';
    std::cout << count8 << '\n';
    std::cout << count9 << '\n';
    std::cout << count10 << '\n';
    m_r = randSum / N;

    //Вычисление дисперсии  и СКО:
    randSum = 0;
    for (long i = 1; i < N; ++i) {
        difRandom = (randomize() - m_r);
        randSum += pow(difRandom, 2);
    }
    D_r = randSum / N;
    sigma = sqrt(D_r);
    std::cout << "Expectation " << m_r << "  Dispersion is   " << D_r << "  SKO is   " << sigma << std::endl;

}

double Randomizing() {
    return arc4random() / pow(2, 32);
}