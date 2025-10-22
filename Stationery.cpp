#include "Stationery.h"
#include <iostream>
#include <limits>

Stationery::Stationery() : Base(), type(""), color(""), purpose("") {
    std::cout << ">>> Вызван конструктор по умолчанию Stationery()" << std::endl;
    std::cout << "    Канцелярский товар создан с пустыми значениями" << std::endl;
}

Stationery::Stationery(const std::string& t, const std::string& c, 
                       const std::string& p, double price)
    : Base(price), type(t), color(c), purpose(p) {
    std::cout << ">>> Вызван конструктор с параметрами Stationery(...)" << std::endl;
    std::cout << "    Создан товар: " << type << " (" << color << ")" << std::endl;
}

Stationery::Stationery(const Stationery& other) 
    : Base(other), type(other.type), color(other.color), purpose(other.purpose) {
    std::cout << ">>> Вызван конструктор копирования Stationery(const Stationery&)" << std::endl;
    std::cout << "    Скопирован товар: " << type << std::endl;
}

Stationery::~Stationery() {
    std::cout << ">>> Вызван деструктор ~Stationery() для товара \"" << type << "\"" << std::endl;
}

void Stationery::display() const {
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║              ✏️  КАНЦЕЛЯРИЯ                ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Тип товара:  " << type << std::endl;
    std::cout << "║ Цвет:        " << color << std::endl;
    std::cout << "║ Назначение:  " << purpose << std::endl;
    std::cout << "║ Цена:        " << price << " руб." << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
}

std::string Stationery::getType() const {
    return "Stationery";
}

void Stationery::saveToFile(std::ofstream& out) const {
    out << "Stationery\n";
    out << type << "\n" 
        << color << "\n" 
        << purpose << "\n" 
        << price << "\n";
}

void Stationery::loadFromFile(std::ifstream& in) {
    std::getline(in, type);
    std::getline(in, color);
    std::getline(in, purpose);
    in >> price;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Stationery::edit() {
    int choice;
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║        ЧТО ИЗМЕНИТЬ В ТОВАРЕ?              ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════╣" << std::endl;
    std::cout << "║ 1. Тип товара                              ║" << std::endl;
    std::cout << "║ 2. Цвет                                    ║" << std::endl;
    std::cout << "║ 3. Назначение                              ║" << std::endl;
    std::cout << "║ 4. Цена                                    ║" << std::endl;
    std::cout << "║ 0. Отмена                                  ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    try {
        switch(choice) {
            case 1:
                std::cout << "Текущий тип: " << type << std::endl;
                std::cout << "Новый тип (ручка, карандаш, тетрадь и т.д.): ";
                std::getline(std::cin, type);
                break;
            case 2:
                std::cout << "Текущий цвет: " << color << std::endl;
                std::cout << "Новый цвет: ";
                std::getline(std::cin, color);
                break;
            case 3:
                std::cout << "Текущее назначение: " << purpose << std::endl;
                std::cout << "Новое назначение: ";
                std::getline(std::cin, purpose);
                break;
            case 4:
                double newPrice;
                std::cout << "Текущая цена: " << price << " руб." << std::endl;
                std::cout << "Новая цена: ";
                std::cin >> newPrice;
                setPrice(newPrice);
                break;
            case 0:
                std::cout << "⚠ Редактирование отменено." << std::endl;
                return;
            default:
                throw std::out_of_range("Неверный выбор");
        }
        std::cout << "Данные успешно обновлены" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Произошла ошибка: " << e.what() << std::endl;
    }
}

std::string Stationery::getStationType() const { return type; }
std::string Stationery::getColor() const { return color; }
std::string Stationery::getPurpose() const { return purpose; }

void Stationery::setStationType(const std::string& t) { type = t; }
void Stationery::setColor(const std::string& c) { color = c; }
void Stationery::setPurpose(const std::string& p) { purpose = p; }


Stationery& Stationery::operator=(const Stationery& other) {
    if (this != &other) {
        Base::operator=(other);
        type = other.type;
        color = other.color;
        purpose = other.purpose;
        
        std::cout << ">>> Вызван оператор присваивания Stationery::operator=()" << std::endl;
        std::cout << "    Скопирован товар: " << type << std::endl;
    } else {
        std::cout << "⚠ Предупреждение: Самоприсваивание канцелярского товара" << std::endl;
    }
    return *this;
}