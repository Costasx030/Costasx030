//Конструкторы
//Методы доступа к полям если нужно
//Перегрузить оператор << для вывода в поток
// Проверка на состояние исключение через throw
//Некоторые методы можно реализовать в виде перегруженных операторов (если подходят
//по смыслу).
// Объявление класса должно быть в заголовочном файле (.h, не забывайте про header guard),
//а определения методов в файле реализации (.cpp).
// В main продемонстрировать работу всех(!) написанных методов и конструкторов.
//Разработать класс многочленов (для хранения коэффициентов можно использовать std::vector<>
// или встроенный массив фиксированного размера). Методы для вычисления значения
// многочлена для заданного аргумента, для сложения, вычитания и умножения многочленов.
// Created by Константин Тимохин on 29.05.2022.
//

#ifndef TASK4_POLYNOM_H
#define TASK4_POLYNOM_H

#include <iostream>
#include <vector>


class Polynom {
private:
    int topDegree_;
    std::vector<double> coefficient_;
public:
    //Конструктор без параметров
    Polynom();

    Polynom(int, const std::vector<double>&);

    void setCoefficientAt(int, double);

    double getPolynomAt(double, int ) const;

    double getPolynom(double) const;


// Перегрузка оператора <<
    friend std::ostream &operator<<(std::ostream &out, const Polynom &aPolynom);

  friend  Polynom operator+(const Polynom &first, const Polynom &second);
  friend  Polynom operator-(const Polynom &first, const Polynom &second);
  friend Polynom operator*(const Polynom &first, const Polynom &second);
};


#endif //TASK4_POLYNOM_H
Polynom operator+(const Polynom &first, const Polynom &second);
Polynom operator-(const Polynom &first, const Polynom &second);
Polynom operator*(const Polynom &first, const Polynom &second);