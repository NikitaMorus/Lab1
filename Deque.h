#ifndef DEQUE_H
#define DEQUE_H

#include "Queue.h"

class Deque : public Queue {
public:
    Deque(int size = 10);
    void addFront(int value);
    void addRear(int value);
    int removeFront();
    int removeRear();
};

#endif
