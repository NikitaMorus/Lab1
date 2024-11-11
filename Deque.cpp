#include "Deque.h"

Deque::Deque(int size) : Queue(size) {}

void Deque::addFront(int value) {
    if (isFull()) {
        throw std::overflow_error("��� ��������!");
    }
    frontIndex = (frontIndex - 1 + capacity) % capacity;
    data[frontIndex] = value;
    count++;
}

void Deque::addRear(int value) {
    enqueue(value);  // ���������� ����� ���������� �� Queue
}

int Deque::removeFront() {
    return dequeue();  // ���������� ����� �������� �� Queue
}

int Deque::removeRear() {
    if (isEmpty()) {
        throw std::underflow_error("��� ����!");
    }
    int value = data[rearIndex];
    rearIndex = (rearIndex - 1 + capacity) % capacity;
    count--;
    return value;
}
