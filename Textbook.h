#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include "Base.h"
#include <fstream>
#include <string>

class Textbook : public Base {
private:
    std::string title;
    std::string author;
    int year;
    std::string institution;
    int studyYear;
    int pages;
public:
    Textbook();
    Textbook(const std::string& t, const std::string& a, int y, const std::string& inst, int sy, int p, double price);
    Textbook(const Textbook& other);
    ~Textbook() override;

    void display() const override;
    std::string getType() const override;
    void saveToFile(std::ofstream& out) const override;
    void loadFromFile(std::ifstream& in) override;
    void edit() override;

    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getInstitution() const;
    int getStudyYear() const;
    int getPages() const;

    void setTitle(const std::string& t);
    void setAuthor(const std::string& a);
    void setYear(int y);
    void setInstituion(const std::string& inst);
    void setStudyYear(int sy);
    void setPages(int p);

    Textbook& operator=(const Textbook& other);
};
#endif