//
// Created by Константин Тимохин on 05.06.2022.
//

#include <iostream>

#ifndef _TASK5_QUEUE_H
#define _TASK5_QUEUE_H

// Чтобы слинковалсась перегрузка оператора <<
template<typename T>
class Queue;  // pre-declare the template class itself
template<typename T>
std::ostream &operator<<(std::ostream &out, const Queue<T> &aQueue);


template<typename T>
class Queue {
public:
    Queue();
    Queue(const Queue &);                   // конструктор копирования
    Queue(Queue &&) noexcept;               // конструктор перемещения
    ~Queue();                               // деструктор

    Queue &operator=(const Queue &);        // перегруженный оператор копирующего присваивания
    Queue &operator=(Queue &&) noexcept;    // перегруженный оператор перемещающего присваивания

    void swap(Queue &) noexcept;            // обмен двух очередей значениями (используется в операторе присваивания)
     void put(const T &d, int p);                  // добавить элемент в очередь с сортировкой
    T take();                               // взять элемент из очереди
    void removeTill(int);             // удалить элементы с приоритетом ниже или равным указанного
//                                              в отсортированной очереди
    void print(std::ostream &stream) const  // вывод очереди на экран
    {
        node_t *temp = head_;
        while (temp) {
            std::cout << temp->data << '\n';
            temp = temp->next;
        }
    }

    friend std::ostream &operator<<<>(std::ostream &,const Queue<T> &aQueue);


private:
    struct node_t           // элемент очереди
    {
        T data;             // данные
        int prioryty;       // приоритет
        node_t *next;       // указатель на следующий элемент
    };

    node_t *head_;          // указатель на начало очереди
    node_t *tail_;          // указатель на конец очереди


};

template<typename T>
Queue<T>::Queue() :

        head_(nullptr),
        tail_(nullptr) {}


// конструктор копирования

template<typename T>
Queue<T>::Queue(const Queue &queue) :
        head_(nullptr),
        tail_(nullptr) {
    // собираем копию очереди внутри временного объекта, чтобы не допустить утечки памяти
    // в случае возникновения исключения при выделени памяти под очередной элемент
    Queue temp;
    node_t *src = queue.head_;
    while (src) {
        temp.put(src->data, src->prioryty);
        src = src->next;
    }
    swap(temp);
}

// конструктор перемещения
template<typename T>
Queue<T>::Queue(Queue &&queue) noexcept :
        head_(nullptr),
        tail_(nullptr) {
    swap(queue);
}

// деструктор
template<typename T>
Queue<T>::~Queue() {
    while (head_) {
        node_t *temp = head_;
        head_ = head_->next;
        delete temp;
    }
}

// оператор копирующего присваивания
template<typename T>
Queue<T> &Queue<T>::operator=(const Queue &queue) {
    // если присваиваем объект самому себе, то делать ничего не нужно
    if (this == &queue) {
        return *this;
    }
    // создаём копию присваиваемой очереди
    Queue tempQueue(queue);
    // меняем содержимое временной копии и контекстного объекта
    swap(tempQueue);
    // возвращаем ссылку на контекстный объект
    return *this;

    // временный объект tempQueue будет уничтожен при завершении метода
    // и его деструктор освободит память, занятую элементами изначальной очереди;
    // такой приём написания оператора присваивания называется copy-and-swap
}

// оператор перемещающего присваивания
template<typename T>
Queue<T> &Queue<T>::operator=(Queue &&queue) noexcept {
    swap(queue);
    return *this;
}

// обмен значениями аргумента и контекстного объекта (просто меняем указатели)
template<typename T>
void Queue<T>::swap(Queue &queue) noexcept {
    std::swap(head_, queue.head_);
    std::swap(tail_, queue.tail_);
}


// извлечение элемента из очереди
template<typename T>
T Queue<T>::take() {
    if (!head_) {
        throw std::logic_error("Queue is empty");
    }
    T res = head_->data;
    node_t *temp = head_;
    if (head_ == tail_)
    {
        head_ = tail_ = nullptr;
    }
    else
    {
        head_ = head_->next;
    }
    delete temp;
    return res;
}




// добавление элемента в очередь c сортировкой
template<typename T>
void Queue<T>::put(const T &d, int p)
{
    node_t *input = new node_t;
    input->data = d;
    input->prioryty = p;
    input->next = nullptr;


    if (!head_)
    {
        head_ = tail_ = input;
    }
    else if (head_->prioryty < input->prioryty)
    {
        input->next = head_;
        head_ = input;
    }
    else
    {
        node_t *temp = head_;
        while (temp != tail_)
        {
            if (temp->prioryty > input->prioryty && temp->next->prioryty <= input->prioryty)
            {
                input->next = temp->next;
                temp->next = input;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (temp == tail_) {
            tail_->next = input;
            tail_ = tail_->next;
        }
    }
}


template<typename T>
void Queue<T>::removeTill(int mark)
{
    if (!head_) {throw std::logic_error("Queue is empty");}

    node_t *temp = head_;

    if (head_->prioryty <= mark)
    {
        head_ = tail_ = nullptr;
        delete temp;
        std::cout << "Queue has been emptened\n";
    }
    else
    {
        while (temp != tail_)
        {
            if (temp->next->prioryty > mark){temp = temp->next;}
            else
            {
                delete temp->next;
                tail_ = temp;
                tail_->next = nullptr;
            }
        }
    }
}

#endif //_TASK5_QUEUE_H

template<typename T>
std::ostream &operator<<(std::ostream &out, const Queue<T> &aQueue) {
    aQueue.print(out);
    return out;
}
