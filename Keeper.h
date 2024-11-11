#ifndef KEEPER_H
#define KEEPER_H

#include <vector>
#include "Base.h"
#include <iostream>
#include <string>

class Keeper {
private:
    std::vector<Base*> objects;

public:
    Keeper();
    ~Keeper();
    void addObject(Base* obj);
    void removeObject(int index);
    void displayObjects() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
