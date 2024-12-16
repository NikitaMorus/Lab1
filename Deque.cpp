#include "Deque.h"
#include <stdexcept>
#include <iostream>

Deque::Deque(int size) : Queue(size) {
    std::cout << "������ ����������� ����\n";
}

Deque::~Deque() {
    std::cout << "������ ���������� ����\n";
}

void Deque::addFront(int value) {
    if (isFull()) {
        throw std::overflow_error("��� ��������!");
    }
    frontIndex = (frontIndex - 1 + capacity) % capacity;
    data[frontIndex] = value;
    ++count;
}

void Deque::addRear(int value) {
    enqueue(value);
}

int Deque::removeFront() {
    return dequeue();
}

int Deque::removeRear() {
    if (isEmpty()) {
        throw std::underflow_error("��� ����!");
    }
    int value = data[rearIndex];
    rearIndex = (rearIndex - 1 + capacity) % capacity;
    --count;
    return value;
}
void Deque::display() const {
    if (isEmpty()) {
        std::cout << "��� ����!" << std::endl;
        return;
    }

    std::cout << "���: ";
    for (int i = 0; i < count; ++i) {
        std::cout << data[(frontIndex + i) % capacity] << " ";
    }
    std::cout << std::endl;
}



