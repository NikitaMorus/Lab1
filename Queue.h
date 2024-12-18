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

    void enqueue(int value); // �������� � �������
    int dequeue(); // ������� �� �������
    int front() const; // �������� ������ �������� � �������
    bool isEmpty() const; // ���������, ����� �� �������
    bool isFull() const; // ���������, ����� �� �������
    void display() const override; // �������� ��� ��������
    void setValue(int value) override; // ���������� ��������
    int getValue() const override; // �������� ��������
};

#endif
