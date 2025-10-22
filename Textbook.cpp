#include "Textbook.h"
#include <iostream>
#include <limits>


Textbook::Textbook() : Base(), title(""), author(""), year(0), institution(""), studyYear(0), pages(0) {
    std::cout << ">>> Вызван конструктор по умолчанию" << std::endl;
    std::cout << "    Учебник создан с пустыми значениями" << std::endl;
}


Textbook::Textbook(const std::string& t, const std::string& a, int y, 
                   const std::string& inst, int sy, int p, double price)
    : Base(price), title(t), author(a), year(y), institution(inst), studyYear(sy), pages(p) {
    std::cout << ">>> Вызван конструктор с параметрами" << std::endl;
    std::cout << "    Создан учебник: \"" << title << "\" для " << institution << std::endl;
}

Textbook::Textbook(const Textbook& other) 
    : Base(other), title(other.title), author(other.author), year(other.year),
      institution(other.institution), studyYear(other.studyYear), pages(other.pages) {
    std::cout << ">>> Вызван конструктор копирования" << std::endl;
    std::cout << "    Скопирован учебник: \"" << title << "\"" << std::endl;
}

Textbook::~Textbook() {
    std::cout << ">>> Вызван деструктор для учебника \"" << title << "\"" << std::endl;
}


void Textbook::display() const {
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║              📖 УЧЕБНИК                    ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Название:           " << title << std::endl;
    std::cout << "║ Автор:              " << author << std::endl;
    std::cout << "║ Год выпуска:        " << year << std::endl;
    std::cout << "║ Учебное заведение:  " << institution << std::endl;
    std::cout << "║ Год обучения:       " << studyYear << " класс/курс" << std::endl;
    std::cout << "║ Страниц:            " << pages << std::endl;
    std::cout << "║ Цена:               " << price << " руб." << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
}

std::string Textbook::getType() const {
    return "Textbook";
}

void Textbook::saveToFile(std::ofstream& out) const {
    out << "Textbook\n";
    out << title << "\n" 
        << author << "\n" 
        << year << "\n" 
        << institution << "\n" 
        << studyYear << "\n" 
        << pages << "\n" 
        << price << "\n";
}

void Textbook::loadFromFile(std::ifstream& in) {
    std::getline(in, title);
    std::getline(in, author);
    in >> year;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(in, institution);
    in >> studyYear >> pages >> price;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Textbook::edit() {
    int choice;
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║        ЧТО ИЗМЕНИТЬ В УЧЕБНИКЕ?            ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════╣" << std::endl;
    std::cout << "║ 1. Название                                ║" << std::endl;
    std::cout << "║ 2. Автор                                   ║" << std::endl;
    std::cout << "║ 3. Год выпуска                             ║" << std::endl;
    std::cout << "║ 4. Учебное заведение                       ║" << std::endl;
    std::cout << "║ 5. Год обучения (класс/курс)               ║" << std::endl;
    std::cout << "║ 6. Количество страниц                      ║" << std::endl;
    std::cout << "║ 7. Цена                                    ║" << std::endl;
    std::cout << "║ 0. Отмена                                  ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    try {
        switch(choice) {
            case 1:
                std::cout << "Текущее название: " << title << std::endl;
                std::cout << "Новое название: ";
                std::getline(std::cin, title);
                break;
            case 2:
                std::cout << "Текущий автор: " << author << std::endl;
                std::cout << "Новый автор: ";
                std::getline(std::cin, author);
                break;
            case 3:
                std::cout << "Текущий год: " << year << std::endl;
                std::cout << "Новый год: ";
                std::cin >> year;
                if (year < 0 || year > 2025) {
                    throw std::invalid_argument("Год должен быть в диапазоне 0-2025!");
                }
                break;
            case 4:
                std::cout << "Текущее учебное заведение: " << institution << std::endl;
                std::cout << "Новое учебное заведение: ";
                std::getline(std::cin, institution);
                break;
            case 5:
                std::cout << "Текущий год обучения: " << studyYear << std::endl;
                std::cout << "Новый год обучения: ";
                std::cin >> studyYear;
                if (studyYear <= 0) {
                    throw std::invalid_argument("Год обучения должен быть больше 0!");
                }
                break;
            case 6:
                std::cout << "Текущее количество страниц: " << pages << std::endl;
                std::cout << "Новое количество страниц: ";
                std::cin >> pages;
                if (pages <= 0) {
                    throw std::invalid_argument("Страниц должно быть больше 0!");
                }
                break;
            case 7:
                double newPrice;
                std::cout << "Текущая цена: " << price << " руб." << std::endl;
                std::cout << "Новая цена: ";
                std::cin >> newPrice;
                setPrice(newPrice);
                break;
            case 0:
                std::cout << "Редактирование отменено." << std::endl;
                return;
            default:
                throw std::out_of_range("Неверный выбор");
        }
        std::cout << "Данные успешно обновлены" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Произошла ошибка: " << e.what() << std::endl;
    }
}


std::string Textbook::getTitle() const { return title; }
std::string Textbook::getAuthor() const { return author; }
int Textbook::getYear() const { return year; }
std::string Textbook::getInstitution() const { return institution; }
int Textbook::getStudyYear() const { return studyYear; }
int Textbook::getPages() const { return pages; }

void Textbook::setTitle(const std::string& t) { title = t; }
void Textbook::setAuthor(const std::string& a) { author = a; }

void Textbook::setYear(int y) { 
    if (y < 0 || y > 2025) {
        throw std::invalid_argument("Год должен быть в диапазоне 0-2025");
    }
    year = y; 
}

void Textbook::setInstitution(const std::string& inst) { institution = inst; }

void Textbook::setStudyYear(int sy) { 
    if (sy <= 0) {
        throw std::invalid_argument("Год обучения должен быть больше 0");
    }
    studyYear = sy; 
}

void Textbook::setPages(int p) { 
    if (p <= 0) {
        throw std::invalid_argument("Страниц должно быть больше 0");
    }
    pages = p; 
}


Textbook& Textbook::operator=(const Textbook& other) {
    if (this != &other) {
        Base::operator=(other);
        title = other.title;
        author = other.author;
        year = other.year;
        institution = other.institution;
        studyYear = other.studyYear;
        pages = other.pages;
        
        std::cout << ">>> Вызван оператор присваивания " << std::endl;
        std::cout << "    Скопирован учебник: \"" << title << "\"" << std::endl;
    } else {
        std::cout << "Самоприсваивание учебника" << std::endl;
    }
    return *this;
}