// lab 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    float k = 1.1, l = 2.2, m = 3.3;
    float sum, nan, ex;
    int cword;
    //summary
    _asm {
        finit
        
        fld k
        fld l
        fld m
        fadd
        fadd 
        fstp sum
    }
    std::cout << k << '+' << l << '+' << m << '=' << sum << "\n";
    // getting NaN
    _asm {
        finit
        fld k
        fldz
        fdiv
        fstp nan
    }
    std::cout << k << '/' << '0' <<  '=' << nan << "\n";

// getting exception
_asm
{
    finit
    fld l
    fldz
//    fstcw cword
//    and cword, 0
//not cword
//or cword, 1
//not cword
    fdiv
    fstp ex
    fld ex
    fld ex
    fldcw cword
    fdiv
    fstp ex
}
    std::cout << 'Nan' << '/' << 'Nan' << '=' << ex << "\n";
}
