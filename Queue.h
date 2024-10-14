#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <queue>

class Queue {
private:
    std::queue<int> q;

public:
    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
    int front() const;  // Метод для получения первого элемента

    // Метод для отображения очереди
    void display() const;
};

#endif
