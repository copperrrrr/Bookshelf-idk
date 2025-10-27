#include "Book.h"
#include <iostream>
#include <limits>

Book::Book() : Base(), title(""), author(""), year(0), annotation(""), genre(""), pages(0) {
    std::cout << ">>> Вызван конструктор по умолчанию Book()" << std::endl;
    std::cout << "  Книга создана с пустыми значениями" << std::endl;
}

Book::Book(const std::string& t, const std::string& a, int y, const std::string& ann, const std::string& g, int p, double price)
: Base(price), title(t), author(a), year(y), annotation(ann), genre(g), pages(p) {
    std::cout << ">>> Вызван конструктор с параметрами Book(...)" << std::endl;
    std::cout << "   Создана книга: \"" << title << "\" автор " << author << std::endl;
}

Book::Book(const Book& other) : Base(other), title(other.title), author(other.author), year(other.year),
                                annotation(other.annotation), genre(other.genre), pages(other.pages) {
    std::cout << "Вызван конструктор копирования книги" << std::endl;
    std::cout << "   Скопирована книга: \"" << title << "\"" << std::endl;
}

Book::~Book() {
    std::cout << ">>> Вызван деструктор для книги \"" << title << "\"" << std::endl;

}


void Book::display() const {
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║              📚 КНИГА                      ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Название:    " << title << std::endl;
    std::cout << "║ Автор:       " << author << std::endl;
    std::cout << "║ Год выпуска: " << year << std::endl;
    std::cout << "║ Жанр:        " << genre << std::endl;
    std::cout << "║ Страниц:     " << pages << std::endl;
    std::cout << "║ Аннотация:   " << annotation << std::endl;
    std::cout << "║ Цена:        " << price << " руб." << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
}


std::string Book::getType() const {
    return "Book";
}

void Book::saveToFile(std::ofstream& out) const {
    out << "Book\n";
    out << title << "\n"
        << author << "\n"
        << year << "\n"
        << annotation << "\n"
        << genre << "\n"
        << pages << "\n"
        << price << "\n";
}

void Book::loadFromFile(std::ifstream& in) {
    std::getline(in, title);
    std::getline(in, author);
    in >> year;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(in, annotation);
    std::getline(in, genre);
    in >> pages >> price;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

void Book::edit() {
    int choice;
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║        ЧТО ИЗМЕНИТЬ В КНИГЕ?               ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════╣" << std::endl;
    std::cout << "║ 1. Название                                ║" << std::endl;
    std::cout << "║ 2. Автор                                   ║" << std::endl;
    std::cout << "║ 3. Год выпуска                             ║" << std::endl;
    std::cout << "║ 4. Аннотация                               ║" << std::endl;
    std::cout << "║ 5. Жанр                                    ║" << std::endl;
    std::cout << "║ 6. Количество страниц                      ║" << std::endl;
    std::cout << "║ 7. Цена                                    ║" << std::endl;
    std::cout << "║ 0. Отмена                                  ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    std::cout << " Ваш выбор:  ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    try {
        switch(choice) {
            case 1:
                std::cout << "Текущее название:  " << title << std::endl;
                std::cout << "Новое название: ";
                std::getline(std::cin, title);
                break;
            case 2:
                std::cout << "Текущий автор:  " << author << std::endl;
                std::cout << "Новый автор:  ";
                std::getline(std::cin, author);
                break;
            case 3:
                std::cout << "Текущий год:  " << year << std::endl;
                std::cout << "Новое значение:  " << year << std::endl;
                std::cin >> year;
                if (year < 0 || year > 2025) {
                    throw std::invalid_argument("Год должен быть в диапазоне 0-2025");
                }
                break;
            case 4:
                std::cout << "Текущая аннотация: " << annotation << std::endl;
                std::cout << "Новая аннотация: ";
                std::getline(std::cin, annotation);
                break;
            case 5:
                std::cout << "Текущий жанр: " << genre << std::endl;
                std::cout << "Новый жанр: ";
                std::getline(std::cin, genre);
                break;
            case 6:
                std::cout << "Текущее кол-во страниц: " << pages << std::endl;
                std::cout << "Новое кол-во страниц: ";
                std::cin >> pages;
                if (pages <= 0) {
                    throw std::invalid_argument("Страниц должно быть больше 0");
                }
                break;
            case 7:
                double newPrice;
                std::cout << "Текущая цена: " << price << " руб." << std::endl;
                std::cout << "Новое значение: ";
                std::cin >> newPrice;
                setPrice(newPrice);
                break;
            case 0:
                std::cout << "Редактирование отменено." << std::endl;
                return;
            default:
                throw std::out_of_range("Неверный выбор.");
            
        }
        std::cout << "Данные успешно обновлены." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Произошла ошибка: " << e.what() << std::endl;
    }
}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
std::string Book::getAnnotation() const { return annotation; }
std::string Book::getGenre() const { return genre; }
int Book::getPages() const { return pages; }


void Book::setTitle(const std::string& t) { title = t; }
void Book::setAuthor(const std::string& a) { author = a; }
void Book::setYear(int y) {
    if (y < 0 || y > 2025) {
        throw std::invalid_argument("Год должен быть в диапазоне 0-2025.");
    }
    year = y;
}
void Book::setAnnotation(const std::string& ann) { annotation = ann; }
void Book::setGenre(const std::string& g) { genre = g; }
void Book::setPages(int p) {
    if (p <= 0) {
        throw std::invalid_argument("Страниц должно быть больше 0.");
    }
    pages = p;
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        Base::operator=(other);
        title = other.title;
        author = other.author;
        year = other.year;
        annotation = other.annotation;
        genre = other.genre;
        pages = other.pages;
        std::cout << ">>> Вызван оператор присваивания " << std::endl;
        std::cout << "   Скопирована книга: \"" << title << "\"" << std::endl;
    } else {
        std::cout << "Самоприсваивание книги." << std::endl;
    }
    return *this;
}