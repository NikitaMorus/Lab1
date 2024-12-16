#include "Deque.h"
#include <stdexcept>
#include <iostream>

Deque::Deque(int size) : Queue(size) {
    std::cout << "Вызван конструктор деки\n";
}

Deque::~Deque() {
    std::cout << "Вызван деструктор деки\n";
}

void Deque::addFront(int value) {
    if (isFull()) {
        throw std::overflow_error("Дек заполнен!");
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
        throw std::underflow_error("Дек пуст!");
    }
    int value = data[rearIndex];
    rearIndex = (rearIndex - 1 + capacity) % capacity;
    --count;
    return value;
}
void Deque::display() const {
    if (isEmpty()) {
        std::cout << "Дек пуст!" << std::endl;
        return;
    }

    std::cout << "Дек: ";
    for (int i = 0; i < count; ++i) {
        std::cout << data[(frontIndex + i) % capacity] << " ";
    }
    std::cout << std::endl;
}



