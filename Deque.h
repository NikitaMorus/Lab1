#ifndef DEQUE_H
#define DEQUE_H

#include "Queue.h"

class Deque {
    Queue q1, q2;

public:
    void addFront(int value);   // Добавить элемент в начало дека
    void addRear(int value);    // Добавить элемент в конец дека
    int removeFront();          // Удалить элемент с начала дека
    int removeRear();           // Удалить элемент с конца дека
    bool isEmpty() const;       // Проверка на пустоту дека
};

#endif
