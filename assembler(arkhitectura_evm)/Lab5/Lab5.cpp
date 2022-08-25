 
#include <iostream>
#include <stdio.h>

long long var1, var2;

long long bi(long long &dec) {
    int bi = 0,
        k = 1;
    while (dec) {
        bi += (dec % 2) * k;
        k *= 10;
        dec /= 2;
    }
    return bi;
}
void shift_stack(long long a, long long& b)
{
    _asm
    {
        mov eax, [ebp + 8]      // передача входного значения в EAX
        add eax, 1              // инкремент младших разрядов
 //       inc eax               // команда не подходит так как не устанавливает флаг переноса
        mov ebx, [ebp + 12]     // передача старших разрядов входного значения
        adc ebx, 0             // передача бита переноса в старший разряд
        mov esi, [ebp + 16]     // передача адреса выходного параметра
        mov [esi], eax          //косвеннвая пердача младших разрядов из входного в выходное значение
        mov[esi + 4], ebx       // косвеннвая пердача старших разрядов из входного в выходное значение
    }
}
long long shift_register()
{
    _asm {
    //    mov eax, [ebp + 8]
        add eax, 1
    //    mov edx, [ebp + 12]
        adc edx, 0
    }
}

void shift_global()
{
    _asm {
        lea esi, var1
        mov ebx, [esi]
        add ebx, 1
        mov eax, [esi + 4]
        adc eax, 0
        lea esi, var2
        mov [esi + 4], eax
        mov [esi], ebx
    }
    
}
int main()
{
 //  setlocale(LC_ALL, "Russian");
    long long a;
    long long b;
    a = 0b10111111111111111111111111111111111111111111111111111111111111;
  //  std::cout << "Please enter a value ";
   // std::cin >> a;
    //Передача через стек
    shift_stack(a, b);
    std::cout << "Increment with stack: " << b << std::endl;
    //Передача через регистры
    b = 0;
    _asm {
        lea ebx, a
        mov eax, [ebx]
        mov edx, [ebx+4]
    }
    b = shift_register();
    std::cout << "Increment with register: " << b << std::endl;
    //Передача через глобальные переменные
    b = 0;
    var1 = a;
    shift_global();
    std::cout << "Increment with global memory space : " << var2  << std::endl;
    return 0;
}
