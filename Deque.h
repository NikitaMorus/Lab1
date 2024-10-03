#ifndef DEQUE_H
#define DEQUE_H

#include "Queue.h"

class Deque {
    Queue q1, q2;

public:
    void addFront(int value);   // �������� ������� � ������ ����
    void addRear(int value);    // �������� ������� � ����� ����
    int removeFront();          // ������� ������� � ������ ����
    int removeRear();           // ������� ������� � ����� ����
    bool isEmpty() const;       // �������� �� ������� ����
};

#endif
