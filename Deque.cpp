#include "Deque.h"

void Deque::addFront(int value) {
    q1.enqueue(value);
}

void Deque::addRear(int value) {
    q2.enqueue(value);
}

int Deque::removeFront() {
    if (!q1.isEmpty()) {
        return q1.dequeue();
    }
    throw std::out_of_range("Deque is empty at front!");
}

int Deque::removeRear() {
    if (!q2.isEmpty()) {
        return q2.dequeue();
    }
    throw std::out_of_range("Deque is empty at rear!");
}

bool Deque::isEmpty() const {
    return q1.isEmpty() && q2.isEmpty();
}

void Deque::display() const {
    std::cout << "Front deque: ";
    q1.display();
    std::cout << "Rear deque: ";
    q2.display();
}
