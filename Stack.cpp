#include "Stack.h"
#include <stdexcept>
#include <iostream>

Stack::Stack(int size) : Queue(size) {
    std::cout << "������ ����������� �����\n";
}


Stack::~Stack() {
    std::cout << "������ ���������� �����\n";
}

void Stack::push(int value) {
    enqueue(value);
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("���� ����!");
    }
    int value = data[rearIndex];
    rearIndex = (rearIndex - 1 + capacity) % capacity;
    --count;
    return value;
}

int Stack::top() const {
    if (isEmpty()) {
        throw std::underflow_error("���� ����!");
    }
    return data[rearIndex];
}

void Stack::display() const {
    if (isEmpty()) {
        std::cout << "���� ����!" << std::endl;
        return;
    }

    std::cout << "����: ";
    for (int i = rearIndex; i >= frontIndex; --i) {
        std::cout << data[i % capacity] << " ";
    }
    std::cout << std::endl;
}


