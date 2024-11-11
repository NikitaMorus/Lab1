#include "Deque.h"

Deque::Deque(int size) : Queue(size) {}

void Deque::addFront(int value) {
    if (isFull()) {
        throw std::overflow_error("Дек заполнен!");
    }
    frontIndex = (frontIndex - 1 + capacity) % capacity;
    data[frontIndex] = value;
    count++;
}

void Deque::addRear(int value) {
    enqueue(value);  // Используем метод добавления из Queue
}

int Deque::removeFront() {
    return dequeue();  // Используем метод удаления из Queue
}

int Deque::removeRear() {
    if (isEmpty()) {
        throw std::underflow_error("Дек пуст!");
    }
    int value = data[rearIndex];
    rearIndex = (rearIndex - 1 + capacity) % capacity;
    count--;
    return value;
}
