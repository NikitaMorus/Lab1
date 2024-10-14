#include "Queue.h"

void Queue::enqueue(int value) {
    q.push(value);
}

int Queue::dequeue() {
    if (!q.empty()) {
        int front = q.front();
        q.pop();
        return front;
    }
    throw std::out_of_range("Queue is empty!");
}

bool Queue::isEmpty() const {
    return q.empty();
}

int Queue::front() const {
    if (!q.empty()) {
        return q.front();  // Возвращаем первый элемент без удаления
    }
    throw std::out_of_range("Queue is empty!");
}

void Queue::display() const {
    std::queue<int> temp = q;  // Копируем очередь для отображения
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}
