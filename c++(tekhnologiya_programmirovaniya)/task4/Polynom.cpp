
#include "Polynom.h"
#include <utility>
#include <vector>
#include <cmath>


//Конструктор без параметров
Polynom::Polynom() :
        topDegree_(0),
        coefficient_(1) {
    coefficient_[0] = 0;
}
//Конструктор с параметром высший порядок, заполнять коэффициенты вручную
Polynom::Polynom(int topDegree, const std::vector<double> &coefficients) :
        topDegree_(topDegree),
        coefficient_(coefficients) {
    if (topDegree_ == -1) throw std::invalid_argument("Negative order");
}

// Конструктор копирования не нужен в простых классах
//Polynom::Polynom(const Polynom &c) {
//    topDegree_ = c.topDegree_;
//    coefficient_ = c.coefficient_;
//    //  std::copy(c.coefficient_.begin(), c.coefficient_.end(), coefficient_);
//}

// Установить коэффициент в требуемый порядок
void Polynom::setCoefficientAt(int order, double value) {
    coefficient_[order] = value;
}

// Получить результат вычисления полинома по значению аргумента
double Polynom::getPolynom(double x) const{
    double res = 0;

    for (int i = 0; i <= topDegree_; ++i)
        res += coefficient_[i] * pow(x, i);
    return res;
}
// Получить результат вычисления значения введенной степени полинома по  значению аргумента

double Polynom::getPolynomAt(double x, int order) const{

    double res = coefficient_[order] * pow(x, order);
    return res;
}



Polynom operator+(const Polynom &first, const Polynom &second) {
    Polynom temp;
    if (first.topDegree_ < second.topDegree_) {
        temp.topDegree_ = second.topDegree_;
    } else { temp.topDegree_ = first.topDegree_; }

    temp.coefficient_.reserve(temp.topDegree_);

    for (int i = 0; i <= temp.topDegree_; ++i) {
        temp.coefficient_[i] = first.coefficient_[i] + second.coefficient_[i];
    }
    return temp;
}

Polynom operator-(const Polynom &first, const Polynom &second) {
    Polynom temp;
    if (first.topDegree_ < second.topDegree_) {
        temp.topDegree_ = second.topDegree_;
    } else { temp.topDegree_ = first.topDegree_; }
    temp.coefficient_.reserve(temp.topDegree_);

    for (int i = 0; i <= temp.topDegree_; ++i)
    {
        temp.coefficient_[i] = first.coefficient_[i] - second.coefficient_[i];
    }
    return temp;
}

//// Перегрузка оператора *
Polynom operator*(const Polynom &first, const Polynom &second) {
    Polynom temp;
    temp.topDegree_ = first.topDegree_ + second.topDegree_;
    temp.coefficient_.reserve(first.topDegree_ + second.topDegree_ + 1);
    for (int i = 0; i <= first.topDegree_; ++i)
        for (int j = 0; j <= second.topDegree_; ++j) {
            temp.coefficient_[i + j] += first.coefficient_[i] * second.coefficient_[j];
        }
    return temp;
}

std::ostream &operator<<(std::ostream &out, const Polynom &aPolynom) {
    if (aPolynom.topDegree_ > 1) {
        for (int i = aPolynom.topDegree_; i > 1; i--) {
            if (aPolynom.coefficient_[i])
            {
                out << aPolynom.coefficient_[i] << "x^" << i;
                if (aPolynom.coefficient_[i - 1] > 0) { out << '+'; }
            }
        }

    }
    if (aPolynom.coefficient_[1]) {
        out << aPolynom.coefficient_[1] << "x";
        if (aPolynom.coefficient_[0] > 0) {
            out << '+';
        }
    }

    if (aPolynom.coefficient_[0]) { out << aPolynom.coefficient_[0]; }
    out << '\n';
    return out;
}


