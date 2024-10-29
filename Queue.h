#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

class Queue {
protected:
    int* data;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

public:
    Queue(int size = 10);
    virtual ~Queue();

    virtual void enqueue(int value);
    virtual int dequeue();
    virtual int front() const;
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
};

#endif
