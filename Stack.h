#ifndef STACK_H
#define STACK_H

#include "Queue.h"

class Stack : public Queue {
public:
    Stack(int size = 10);
    void push(int value);
    int pop();
    int top() const;
};

#endif
