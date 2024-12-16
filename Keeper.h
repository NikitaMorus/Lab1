#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include <iostream>
#include <fstream>

class Keeper {
private:
    Base** objects;
    int size;
    int capacity;

    void resize();

public:
    Keeper(int initialCapacity = 10);
    ~Keeper();

    void addObject(Base* obj);
    void removeObject(int index);
    void displayObjects() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    size_t getSize() const;
};

#endif
