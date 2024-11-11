#include "Stack.h"

Stack::Stack(int size) : Queue(size) {}

void Stack::push(int value) {
    enqueue(value);  // ���������� ����� ���������� �� Queue
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("���� ����!");
    }
    int value = data[rearIndex];
    rearIndex = (rearIndex - 1 + capacity) % capacity;
    count--;
    return value;
}

int Stack::top() const {
    if (isEmpty()) {
        throw std::underflow_error("���� ����!");
    }
    return data[rearIndex];
}
