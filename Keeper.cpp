#include "Keeper.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <string>

Keeper::Keeper() {}

Keeper::~Keeper() {
    for (auto obj : objects) delete obj;
}

void Keeper::addObject(Base* obj) {
    objects.push_back(obj);
}

void Keeper::removeObject(int index) {
    if (index < 0 || index >= objects.size()) {
        throw std::out_of_range("Неверный индекс!");
    }
    delete objects[index];
    objects.erase(objects.begin() + index);
}

void Keeper::displayObjects() const {
    for (size_t i = 0; i < objects.size(); ++i) {
        std::cout << "Объект " << i + 1 << ": ";
        objects[i]->display();
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) throw std::ios_base::failure("Не удалось открыть файл для записи");
    // Запись данных
    file.close();
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) throw std::ios_base::failure("Не удалось открыть файл для чтения");
    // Загрузка данных
    file.close();
}
