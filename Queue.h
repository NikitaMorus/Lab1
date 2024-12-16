#ifndef QUEUE_H
#define QUEUE_H

#include "Base.h"

class Queue : public Base {
protected:
    int* data;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

public:
    Queue(int size = 10);
    virtual ~Queue();

    void enqueue(int value); // Добавить в очередь
    int dequeue(); // Удалить из очереди
    int front() const; // Получить первое значение в очереди
    bool isEmpty() const; // Проверить, пуста ли очередь
    bool isFull() const; // Проверить, полна ли очередь
    void display() const override; // Показать все элементы
    void setValue(int value) override; // Установить значение
    int getValue() const override; // Получить значение
};

#endif
