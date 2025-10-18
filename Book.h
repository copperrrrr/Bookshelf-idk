#ifndef BOOK_H
#define BOOK_H

#include "Base.h"
#include <fstream>
#include <string>

class Book : public Base {
private:
    std::string title;
    std::string author;
    int year;
    std::string annotation;
    std::string genre;
    int pages;
public:
    Book();

    Book(const std::string& t, const std::string& a, int y, const std::string& ann, const std::string& g, int p, double price);

    Book(const Book& other);

    ~Book() override;

    void display() const override;

    std::string getType() const override;

    void saveToFile(std::ofstream& out) const override;

    void loadFromFile(std::ifstream& in) override;

    void edit() override;


    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getAnnotation() const;
    std::string getGenre() const;
    int getPages() const;

    void setTitle(const std::string& t);
    void setAuthor(const std::string& a);
    void setYear(int y);
    void setAnnotation(const std::string& ann);
    void setGenre(const std::string& g);
    void setPages(int p);

    Book& operator=(const Book& other);
       
};

#endif