#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include <fstream>
#include <string>


class Keeper {
private:
    Base** items;
    int size;
    int capacity;

    void resize();

public:
    Keeper();

    explicit Keeper(int cap);
    Keeper(const Keeper& other);
    ~Keeper();

    void add(Base *item);
    void remove(int index);
    void display() const;
    void displayByIndex(int index) const;
    void displayByType(const std::string& itemType) const;
    void editByIndex(int index);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    int getSize() const;
    int getCapacity() const;

    Base* getItem(int index) const;

    int countByType(const std::string& itemType) const;

    Keeper& operator=(const Keeper& other);
    Base* operator[](int index) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Keeper& keeper);
};

#endif

