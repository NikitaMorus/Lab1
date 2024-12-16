#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base {
public:
    virtual ~Base() { std::cout << "������ ���������� �������� ������.\n"; }

    virtual void display() const = 0; // ��� ����������� �����������
    virtual void setValue(int value) = 0; // ���������� ��������
    virtual int getValue() const = 0; // �������� ��������
};

#endif
