#include <iostream>
#include <fstream>

int **createMatrix(int size);

void showMatrix(int **, int size, std::ostream &stream);

void dominoMatrix(int **, int, int, int);

void deleteMatrix(int **, int);

int main() {

    int size = 0,
            k = 0,
            m = 0;
    std::cout << "Please enter starting value of size" << '\n';
    std::cin >> size;
    std::ofstream out("outfile.txt");
    out << "Here we go!!!" << '\n' << '\n';
    out.close();
    while (size) {
        int **matrix = createMatrix(size);
        std::cout << "Please enter strike's coordinates k and m, should be less than " << size << '\n';
        std::cin >> k >> m;
        dominoMatrix(matrix, size, k, m);
        showMatrix(matrix, size, std::cout);
        std::ofstream out("outfile.txt", std::ios::app);
        showMatrix(matrix, size, out );
        deleteMatrix(matrix, size);
        std::cout << "Please enter nex value of size (for exit enter 0)" << '\n';
        std::cin >> size;
    }
      out.close();
    return 0;
}

int **createMatrix(int size) {
    int **matrix = nullptr;
    matrix = new int *[size];

    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }
    return matrix;
}

void showMatrix(int **const matrix, int size, std::ostream &stream) {


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            stream << ' ' << matrix[i][j];
        }
         stream << '\n';

    }
    stream << '\n';
}

void dominoMatrix(int **matrix, int size, int row, int col) {
    for (int k = 0; k < size; ++k) {
        if ((row - k) >= 0) {
            for (int m = -k; m <= k; ++m) {
                if ((col + m) >= 0 && (col + m) < size)
                    matrix[row - k][col + m] = k + 1;
            }
        }
        if ((row + k) < size) {
            for (int m = -k; m <= k; ++m) {
                if ((col + m) >= 0 && (col + m) < size)
                    matrix[row + k][col + m] = k + 1;
            }
        }
        if ((col - k) >= 0) {
            for (int m = -k; m <= k; ++m) {
                if ((row + m) >= 0 && (row + m) < size)
                    matrix[row + m][col - k] = k + 1;
            }
        }
        if ((col + k) < size) {
            for (int m = -k; m <= k; ++m) {
                if ((row + m) >= 0 && (row + m) < size)
                    matrix[row + m][col + k] = k + 1;
            }
        }
    }
}

void deleteMatrix(int **matrix, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}