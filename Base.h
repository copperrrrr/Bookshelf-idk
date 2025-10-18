#ifndef BASE_H
#define BASE_H
#include <string>
#include <iostream>
class Base {
protected:
    double price;

public: 
    Base();
    Base(double p);
    Base(const Base& other);

    virtual ~Base();

    virtual void display() const = 0;
    virtual std::string getType() const = 0;
    virtual void saveToFile(std::ofstream& out) const = 0;
    virtual void loadFromFile(std::ifstream& in) = 0;
    virtual void edit() const = 0;

    double getPrice() const;
    void setPrice(double p);

    Base& operator=(const Base& other);
    friend std::ostream& operator<<(std::ostream& os, const Base& obj);
};

#endif

