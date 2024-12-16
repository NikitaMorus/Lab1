#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base {
public:
    virtual ~Base() { std::cout << "Вызван деструктор базового класса.\n"; }

    virtual void display() const = 0; // Для отображения содержимого
    virtual void setValue(int value) = 0; // Установить значение
    virtual int getValue() const = 0; // Получить значение
};

#endif
