#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include "Queue.h"

class Deque {
private:
    Queue q1;
    Queue q2;

public:
    void addFront(int value);
    void addRear(int value);
    int removeFront();
    int removeRear();
    bool isEmpty() const;

    // Новый метод для отображения дека
    void display() const;
};

#endif
