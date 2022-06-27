/*Запрещается использовать контейнеры и алгоритмы STL.
 Реализовать необходимые конструкторы.
 Реализовать деструктор, конструкторы копирования и перемещения, операторы
копирующего и перемещающего присваивания.
 Память должна корректно выделяться и освобождаться.
 Реализовать методы, позволяющие осуществлять работу с объектами. (Необходимо
продумать, как объекты будут использоваться)
 Некоторые методы можно реализовать в виде перегруженных операторов (если подходят
по смыслу).
 Реализовать перегруженный оператор << для вывода информации в поток.
 Классы должны контролировать свои данные и не допускать создания объектов с
некорректным состоянием (рекомендуется выбрасывать исключения с помощью throw).
 Объявление класса должно быть в заголовочном файле (.h), а определения методов в
файле реализации (.cpp).
 В main продемонстрировать работу всех(!) методов, операторов и конструкторов.

Класс очереди с приоритетами на базе односвязного списка. Каждый элемент очереди имеет
 значение и приоритет (целое число). Элементы извлекаются в порядке FIFO, но элементы с
 более высоким приоритетом извлекаются в любом случае раньше. Написать методы для добавления
 и извлечения элементов, метод для удаления всех элементов с приоритетом равным или меньшим
 указанного. (В идеале класс должен быть шаблонным, но можно сделать только для типа int)

 */

#include <iostream>
#include"Queue.h"

int main()
{
    Queue<double> queue;

    // добавляем в очередь элементы
    queue.put(8,2);
    queue.put(15, 3);
    queue.put(16, 5);
    queue.put(100, 1);
    queue.put(-8,4);

    // выводим
    std::cout << "Start queue:\n";
    queue.print(std::cout);
    std::cout << '\n';

    // проверяем метод take, должно вернуться число, помещённое в очередь первым
    std::cout << "extract " << queue.take() << '\n';

    // ещё раз выводим
    std::cout << "Queue after first taking:\n";
    queue.print(std::cout);
    std::cout << '\n';

    Queue<double> queue2 = queue;	// здесь вызывается конструктор копирования (эквивалентно Queue queue2(queue);)

    // извлекаем ещё один элемент из исходнй очереди
    std::cout << "extract " << queue.take() << '\n';

    // и выводим, чтобы показать, что очереди разные
    std::cout << "After second taking\n";
    std::cout << "queue:\n";
    queue.print(std::cout);
    std::cout << "\nqueue2:\n";
    queue2.print(std::cout);
    std::cout << '\n';
    queue2 = std::move(queue);	// а вот здесь уже вызывается оператор присваивания

    std::cout << "queue2 after assignment:\n";
    queue2.print(std::cout);
    std::cout << "\nQueue with <<:\n";
    std::cout << queue2;


    std::cout << "\n queue4 - string:\n";
    Queue<std::string> queue4;
    queue4.put("oh", 4);
    queue4.put("my",6);
    queue4.put("dear",7);
    queue4.put("what",8);
    queue4.put("is it?",3);
    std::cout << queue4 << "\n";


    std::cout << "queue5 - int before removing:\n";
    Queue<int> queue5;
    queue5.put(4, 4);
    queue5.put(7,7);
    queue5.put(6,6);
    queue5.put(3,3);
    queue5.put(8,8);
    std::cout << queue5<< "\n\n\n\n";

    queue5.removeTill(5);
    std::cout << "\nQueue5remove till 5 <<:\n";
    std::cout << queue5;


    Queue<int> queue3;
    queue3.put(4, 4);
    queue3.put(2,7);
    queue3.put(3,6);
    queue3.put(5,3);
    queue3.put(1,8);
    std::cout << "\nQueue3 <<:\n";
    std::cout << queue3;

    queue3.removeTill(9);

    std::cout << "\nQueue3remove till 9 <<:\n";
    std::cout << queue3;

    Queue<double> queue10(queue);

    std::cout << "CC" << queue10;

    Queue<double> queue11(std::move(queue));
    std::cout << "MC" <<  queue10 << '\n' << queue;









try {
    std::cout << "Taked with priority:   " << queue4.take() << '\n';
    std::cout << queue4;
    std::cout << "Taked with priority:   " << queue4.take() << '\n';
    std::cout << queue4;
    std::cout << "Taked with priority " << queue4.take() << '\n';
    std::cout << queue4;
    std::cout << "Taked with priority " << queue4.take() << '\n';
    std::cout << queue4;
    std::cout << "Taked with priority " << queue4.take() << '\n';
    std::cout << queue4;
    std::cout << "Taked with priority " << queue4.take() << '\n';
    std::cout << queue4;

}

    catch (const std::logic_error &e)
    {
        std::cerr << e.what() ;

    }

    return 0;
}
