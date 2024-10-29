#include "Queue.h"

Queue::Queue(int size) : capacity(size), frontIndex(0), rearIndex(-1), count(0) {
    data = new int[capacity];
}

Queue::~Queue() {
    delete[] data;
}

void Queue::enqueue(int value) {
    if (isFull()) {
        throw std::overflow_error("Очередь заполнена!");
    }
    rearIndex = (rearIndex + 1) % capacity;
    data[rearIndex] = value;
    count++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Очередь пуста!");
    }
    int value = data[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    count--;
    return value;
}

int Queue::front() const {
    if (isEmpty()) {
        throw std::underflow_error("Очередь пуста!");
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
        std::cout << "Очередь пуста!" << std::endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        std::cout << data[(frontIndex + i) % capacity] << " ";
    }
    std::cout << std::endl;
}
