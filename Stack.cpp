#include "Stack.h"

void Stack::push(int value) {
    s.push(value);
}

int Stack::pop() {
    if (!s.empty()) {
        int top = s.top();
        s.pop();
        return top;
    }
    throw std::out_of_range("Stack is empty!");
}

bool Stack::isEmpty() const {
    return s.empty();
}

int Stack::top() const {
    if (!s.empty()) {
        return s.top();  // Возвращаем верхний элемент без удаления
    }
    throw std::out_of_range("Stack is empty!");
}

void Stack::display() const {
    std::stack<int> temp = s;  // Копируем стек для отображения
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}
