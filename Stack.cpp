#include "Stack.h"

Stack::Stack(int size) : Queue(size) {}

void Stack::push(int value) {
    enqueue(value);  // Используем метод добавления из Queue
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Стек пуст!");
    }
    int value = data[rearIndex];
    rearIndex = (rearIndex - 1 + capacity) % capacity;
    count--;
    return value;
}

int Stack::top() const {
    if (isEmpty()) {
        throw std::underflow_error("Стек пуст!");
    }
    return data[rearIndex];
}
