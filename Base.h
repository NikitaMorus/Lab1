#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string>

class Base {
public:
    Base() { std::cout << "Base конструктор\n"; }
    virtual ~Base() { std::cout << "Base деструктор\n"; }
    virtual void display() const = 0;
    virtual void setValue(int value) = 0;
};

#endif
