#include <iostream>
#include <string>
#include "Queue.h"
#include "Stack.h"
#include "Deque.h"
#include "Base.h"
#include "Keeper.h"

void showMenu() {
    std::cout << "1. Операции с очередью\n";
    std::cout << "2. Операции с стеком\n";
    std::cout << "3. Операции с деком\n";
    std::cout << "4. Сохранить контейнер в файл\n";
    std::cout << "5. Загрузить контейнер из файла\n";
    std::cout << "6. Выход\n";
    std::cout << "Введите ваш выбор: ";
}

void queueOperations() {
    Queue queue;
    int choice, value;

    do {
        std::cout << "\nОперации с очередью:\n";
        std::cout << "1. Добавить в очередь\n";
        std::cout << "2. Удалить из очереди\n";
        std::cout << "3. Показать передний элемент\n";
        std::cout << "4. Показать все элементы очереди\n";
        std::cout << "5. Вернуться в главное меню\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            try {
                std::cout << "Удалено значение: " << queue.dequeue() << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 3:
            try {
                std::cout << "Передний элемент: " << queue.front() << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 4:
            std::cout << "Очередь: ";
            queue.display();
            break;
        }
    } while (choice != 5);
}

void stackOperations() {
    Stack stack;
    int choice, value;

    do {
        std::cout << "\nОперации с стеком:\n";
        std::cout << "1. Добавить в стек\n";
        std::cout << "2. Удалить из стека\n";
        std::cout << "3. Показать верхний элемент\n";
        std::cout << "4. Показать все элементы стека\n";
        std::cout << "5. Вернуться в главное меню\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            stack.push(value);
            break;
        case 2:
            try {
                std::cout << "Удалено значение: " << stack.pop() << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 3:
            try {
                std::cout << "Верхний элемент: " << stack.top() << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 4:
            std::cout << "Стек: ";
            stack.display();
            break;
        }
    } while (choice != 5);
}

void dequeOperations() {
    Deque deque;
    int choice, value;

    do {
        std::cout << "\nОперации с деком:\n";
        std::cout << "1. Добавить в начало\n";
        std::cout << "2. Добавить в конец\n";
        std::cout << "3. Удалить с начала\n";
        std::cout << "4. Удалить с конца\n";
        std::cout << "5. Показать все элементы дека\n";
        std::cout << "6. Вернуться в главное меню\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите значение для добавления в начало: ";
            std::cin >> value;
            deque.addFront(value);
            break;
        case 2:
            std::cout << "Введите значение для добавления в конец: ";
            std::cin >> value;
            deque.addRear(value);
            break;
        case 3:
            try {
                std::cout << "Удалено с начала: " << deque.removeFront() << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 4:
            try {
                std::cout << "Удалено с конца: " << deque.removeRear() << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 5:
            std::cout << "Дек: ";
            deque.display();
            break;
        }
    } while (choice != 6);
}

void saveToFile(Keeper& keeper) {
    std::string filename;
    std::cout << "Введите имя файла для сохранения: ";
    std::cin >> filename;
    keeper.saveToFile(filename);
    std::cout << "Сохранение прошло успешно.\n";
}

void loadFromFile(Keeper& keeper) {
    std::string filename;
    std::cout << "Введите имя файла для загрузки: ";
    std::cin >> filename;
    keeper.loadFromFile(filename);
    std::cout << "Загрузка прошла успешно.\n";
}

int main() {
    setlocale(LC_ALL, "RUS");
    Keeper keeper; // Хранитель всех контейнеров
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            queueOperations();
            break;
        case 2:
            stackOperations();
            break;
        case 3:
            dequeOperations();
            break;
        case 4:
            saveToFile(keeper);
            break;
        case 5:
            loadFromFile(keeper);
            break;
        case 6:
            std::cout << "Выход...\n";
            break;
        default:
            std::cerr << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 6);

    return 0;
}
