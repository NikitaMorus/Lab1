#include "Queue.h"
#include <stdexcept>
#include <iostream>

Queue::Queue(int size) : capacity(size), frontIndex(0), rearIndex(-1), count(0) {
    data = new int[capacity];
    std::cout << "������ ����������� ������� � ����������\n";
}

Queue::~Queue() {
    delete[] data;
    std::cout << "������ ���������� �������\n";
}

void Queue::enqueue(int value) {
    if (isFull()) {
        throw std::overflow_error("������� ���������!");
    }
    rearIndex = (rearIndex + 1) % capacity;
    data[rearIndex] = value;
    ++count;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("������� �����!");
    }
    int value = data[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    --count;
    return value;
}

int Queue::front() const {
    if (isEmpty()) {
        throw std::underflow_error("������� �����!");
    }
    return data[frontIndex];
}

bool Queue::isEmpty() const {
    return count == 0;
}

bool Queue::isFull() const {
    return count == capacity;
}

void Queue::display() const {
    if (isEmpty()) {
        std::cout << "������� �����!" << std::endl;
        return;
    }

    std::cout << "�������: ";
    for (int i = 0; i < count; ++i) {
        std::cout << data[(frontIndex + i) % capacity] << " ";
    }
    std::cout << std::endl;
}



void Queue::setValue(int value) {
    enqueue(value);  // ��������� ������ ���� ��������
}


int Queue::getValue() const {
    return front();
}
