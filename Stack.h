#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stack>

class Stack {
private:
    std::stack<int> s;

public:
    void push(int value);
    int pop();
    bool isEmpty() const;
    int top() const;  // Метод для получения верхнего элемента

    // Метод для отображения стека
    void display() const;
};

#endif
