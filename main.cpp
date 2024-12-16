#include "Keeper.h"
#include "Queue.h"
#include "Stack.h"
#include "Deque.h"
#include <iostream>

void showMenu() {
    std::cout << "\n============== ���� ==============\n";
    std::cout << "1. �������� ����� ������\n";
    std::cout << "2. ������� ������ �� �������\n";
    std::cout << "3. �������� ��� �������\n";
    std::cout << "4. ��������� ������� � ����\n";
    std::cout << "5. ��������� ������� �� �����\n";
    std::cout << "6. ����� �� ���������\n";
    std::cout << "==================================\n";
    std::cout << "������� ��� �����: ";
}

void addObject(Keeper& keeper) {
    int type;
    std::cout << "\n�������� ��� �������:\n";
    std::cout << "1. ������� (Queue)\n";
    std::cout << "2. ���� (Stack)\n";
    std::cout << "3. ��� (Deque)\n";
    std::cout << "������� ��� �����: ";
    std::cin >> type;

    int value;
    std::cout << "������� �������� ��� �������: ";
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
        std::cout << "������: �������� ����� ���� �������.\n";
        return;
    }

    if (obj) {
        obj->setValue(value);  // ��� ������� ���� �������
        keeper.addObject(obj);
        std::cout << "������ ������� ��������!\n";
    }
}


void removeObject(Keeper& keeper) {
    keeper.displayObjects();

    if (keeper.getSize() == 0) {
        std::cout << "�������� ����������: ������ �������� ����.\n";
        return;
    }

    int index;
    std::cout << "������� ������ ������� ��� �������� (1..." << keeper.getSize() << "): ";
    std::cin >> index;

    try {
        keeper.removeObject(index - 1);
        std::cout << "������ ������� ������!\n";
    }
    catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << "\n";
    }
}

void saveObjects(Keeper& keeper) {
    std::string filename;
    std::cout << "������� ��� ����� ��� ����������: ";
    std::cin >> filename;

    try {
        keeper.saveToFile(filename);
        std::cout << "������� ������� ��������� � ���� \"" << filename << "\".\n";
    }
    catch (const std::exception& e) {
        std::cerr << "������ ��� ����������: " << e.what() << "\n";
    }
}

void loadObjects(Keeper& keeper) {
    std::string filename;
    std::cout << "������� ��� ����� ��� ��������: ";
    std::cin >> filename;

    try {
        keeper.loadFromFile(filename);
        std::cout << "������� ������� ��������� �� ����� \"" << filename << "\".\n";
    }
    catch (const std::exception& e) {
        std::cerr << "������ ��� ��������: " << e.what() << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    Keeper keeper;
    int choice;

    std::cout << "����� ���������� � ��������� ���������� ����������� ������!\n";

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
            std::cout << "����� �� ���������...\n";
            break;
        default:
            std::cout << "������: �������� �����. ���������� �����.\n";
        }
    } while (choice != 6);

    return 0;
}
