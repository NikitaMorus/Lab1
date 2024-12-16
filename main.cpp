#include "Keeper.h"
#include "Queue.h"
#include "Stack.h"
#include "Deque.h"
#include <iostream>

void showMenu() {
    std::cout << "\n============== МЕНЮ ==============\n";
    std::cout << "1. Добавить новый объект\n";
    std::cout << "2. Удалить объект по индексу\n";
    std::cout << "3. Показать все объекты\n";
    std::cout << "4. Сохранить объекты в файл\n";
    std::cout << "5. Загрузить объекты из файла\n";
    std::cout << "6. Выйти из программы\n";
    std::cout << "==================================\n";
    std::cout << "Введите ваш выбор: ";
}

void addObject(Keeper& keeper) {
    int type;
    std::cout << "\nВыберите тип объекта:\n";
    std::cout << "1. Очередь (Queue)\n";
    std::cout << "2. Стек (Stack)\n";
    std::cout << "3. Дек (Deque)\n";
    std::cout << "Введите ваш выбор: ";
    std::cin >> type;

    int value;
    std::cout << "Введите значение для объекта: ";
    std::cin >> value;

    Base* obj = nullptr;

    switch (type) {
    case 1:
        obj = new Queue(10);
        break;
    case 2:
        obj = new Stack(10);
        break;
    case 3:
        obj = new Deque(10);
        break;
    default:
        std::cout << "Ошибка: Неверный выбор типа объекта.\n";
        return;
    }

    if (obj) {
        obj->setValue(value);  // Это добавит один элемент
        keeper.addObject(obj);
        std::cout << "Объект успешно добавлен!\n";
    }
}


void removeObject(Keeper& keeper) {
    keeper.displayObjects();

    if (keeper.getSize() == 0) {
        std::cout << "Удаление невозможно: список объектов пуст.\n";
        return;
    }

    int index;
    std::cout << "Введите индекс объекта для удаления (1..." << keeper.getSize() << "): ";
    std::cin >> index;

    try {
        keeper.removeObject(index - 1);
        std::cout << "Объект успешно удален!\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }
}

void saveObjects(Keeper& keeper) {
    std::string filename;
    std::cout << "Введите имя файла для сохранения: ";
    std::cin >> filename;

    try {
        keeper.saveToFile(filename);
        std::cout << "Объекты успешно сохранены в файл \"" << filename << "\".\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка при сохранении: " << e.what() << "\n";
    }
}

void loadObjects(Keeper& keeper) {
    std::string filename;
    std::cout << "Введите имя файла для загрузки: ";
    std::cin >> filename;

    try {
        keeper.loadFromFile(filename);
        std::cout << "Объекты успешно загружены из файла \"" << filename << "\".\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка при загрузке: " << e.what() << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    Keeper keeper;
    int choice;

    std::cout << "Добро пожаловать в программу управления структурами данных!\n";

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            addObject(keeper);
            break;
        case 2:
            removeObject(keeper);
            break;
        case 3:
            keeper.displayObjects();
            break;
        case 4:
            saveObjects(keeper);
            break;
        case 5:
            loadObjects(keeper);
            break;
        case 6:
            std::cout << "Выход из программы...\n";
            break;
        default:
            std::cout << "Ошибка: Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 6);

    return 0;
}
