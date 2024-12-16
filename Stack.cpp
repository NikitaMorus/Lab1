#include "Stack.h"
#include <stdexcept>
#include <iostream>

Stack::Stack(int size) : Queue(size) {
    std::cout << "Вызван конструктор стека\n";
}


Stack::~Stack() {
    std::cout << "Вызван деструктор стека\n";
}

void Stack::push(int value) {
    enqueue(value);
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Стек пуст!");
    }
    int value = data[rearIndex];
    rearIndex = (rearIndex - 1 + capacity) % capacity;
    --count;
    return value;
}

int Stack::top() const {
    if (isEmpty()) {
        throw std::underflow_error("Стек пуст!");
    }
    return data[rearIndex];
}

void Stack::display() const {
    if (isEmpty()) {
        std::cout << "Стек пуст!" << std::endl;
        return;
    }

    std::cout << "Стек: ";
    for (int i = rearIndex; i >= frontIndex; --i) {
        std::cout << data[i % capacity] << " ";
    }
    std::cout << std::endl;
}


