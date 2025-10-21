#ifndef STATIONERY_H
#define STATIONERY_H
#include "Base.h"
#include <fstream>
#include <string>

class Stationery : public Base {
private:
    std::string type;
    std::string color;
    std::string purpose;
public:
    Stationery();

    Stationery(const std::string& t, const std::string& c, const std::string& p, double price);

    Stationery(const Stationery& other);

    ~Stationery() override;


    void display() const override;
    std::string getType() const override;

    void saveToFile(std::ofstream& out) const override;
    void loadFromFile(std::ifstream& in) override;
    void edit() override;

    std::string getStationType() const;
    std::string getColor() const;
    std::string getPurpose() const;

    void setStationType(const std::string& t);
    void setColor(const std::string& c);
    void setPurpose(const std::string& p);

    Stationery& operator=(const Stationery& other);

};
#endif