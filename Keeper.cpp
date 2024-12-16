#include "Keeper.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "Queue.h"

Keeper::Keeper(int initialCapacity) : size(0), capacity(initialCapacity) {
    objects = new Base * [capacity];
}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete objects[i];
    }
    delete[] objects;
}

void Keeper::resize() {
    capacity *= 2;
    Base** newObjects = new Base * [capacity];
    for (int i = 0; i < size; ++i) {
        newObjects[i] = objects[i];
    }
    delete[] objects;
    objects = newObjects;
}

void Keeper::addObject(Base* obj) {
    if (size == capacity) {
        resize();
    }
    objects[size++] = obj;
}

void Keeper::removeObject(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Неверный индекс!");
    }
    delete objects[index];
    for (int i = index; i < size - 1; ++i) {
        objects[i] = objects[i + 1];
    }
    --size;
}

void Keeper::displayObjects() const {
    for (int i = 0; i < size; ++i) {
        std::cout << "Объект " << i + 1 << ": ";
        objects[i]->display();  // Вызов метода display для каждого объекта
    }
}



void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (int i = 0; i < size; ++i) {
        int value = objects[i]->getValue();
        file.write(reinterpret_cast<const char*>(&value), sizeof(value));
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    int newSize;
    file.read(reinterpret_cast<char*>(&newSize), sizeof(newSize));
    for (int i = 0; i < newSize; ++i) {
        int value;
        file.read(reinterpret_cast<char*>(&value), sizeof(value));
        Base* obj = new Queue(10);
        obj->setValue(value);
        addObject(obj);
    }
}

size_t Keeper::getSize() const {
    return size;
}
