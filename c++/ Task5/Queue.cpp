//
// Created by Константин Тимохин on 05.06.2022.
//

#include "Queue.h"
// добавление элемента в очередь
//template<typename T>
//void Queue<T>::put(T d, int p) {
//    if (!head_) {
//        head_ = tail_ = new node_t;
//    } else {
//        tail_->next = new node_t;
//        tail_ = tail_->next;
//    }
//    tail_->prioryty = p;
//    tail_->data = d;
//    tail_->next = nullptr;
//}


//// Взять элемент с высшим приоритетом
//template<typename T>
//T Queue<T>::takeP() {
//    if (!head_) {
//        throw std::logic_error("Queue is empty");
//    }
//    node_t *temp = head_;
//    node_t *max = head_;
//    while (temp != tail_)
//    {
//        if (max->prioryty < temp->next->prioryty) { max = temp->next; }
//        temp = temp->next;
//    }
//
//    T res = max->data;
//    if (head_ == tail_)
//    {
//        head_ = tail_ = nullptr;
//        std::cout << " Emptened\n";
//    }
//    else if (max == head_)
//    {
//        head_ = head_->next;
//    }
//    else
//    {
//        temp = head_;
//        while (temp->next != max)
//        {
//            temp = temp->next;
//        }
//        if (max == tail_)
//        {
//            tail_ = temp;
//            temp->next = nullptr;
//        }
//        else
//        {
//            temp->next = max->next;
//        }
//    }
//    delete max;
//    return res;
//}

//template<typename T>
//void Queue<T>::removeTill(int mark)
//{
//    if (!head_)
//    {
//        throw std::logic_error("Queue is empty");
//    }
//
//    node_t *temp = head_;
//    int minPrioryty = mark;
//
//    while (minPrioryty <= mark)
//    {
//        node_t *min = head_;
//
//        while (temp != tail_)
//        {
//            if (min->prioryty > temp->next->prioryty) { min = temp->next; }
//            temp = temp->next;
//        }
//
//        minPrioryty = min->prioryty;
//
//        if (min->prioryty <= mark)
//        {
//            if (head_ == tail_)
//            {
//                head_ = tail_ = nullptr;
//                minPrioryty = mark + 1;
//            }
//            else if (min == head_){head_ = head_->next;}
//            else
//            {
//                temp = head_;
//                while (temp->next != min) {temp = temp->next;}
//                if (min == tail_)
//                {
//                    tail_ = temp;
//                    temp->next = nullptr;
//                }
//                else {temp->next = min->next;}
//            }
//            temp = head_;
//            delete min;
//        }
//    }
//}