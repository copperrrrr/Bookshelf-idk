#include "Base.h"

Base::Base() : price(0.0) {
    std::cout << ">>> Вызван конструктор по умолчанию Base()" << std::endl;
    std::cout << "Цена инициализирована: " << price << ".руб" << std::endl;

}

Base::Base(double p) : price(p) {
    std::cout << ">>> Вызван конструктор с параметром Base(double)" << std::endl;
    std::cout << "Цена установлена: " << price << ".руб" << std::endl;
}

Base::Base(const Base& other) : price(other.price) {
    std::cout << ">>> Вызван конструктор копирования Base(const Base&)" << std::endl;
    std::cout << "Скопирована цена: " << price << ".руб" << std::endl;
}

Base::~Base() {
    std::cout << ">>> Вызван деструктор ~Base()" << std::endl;
    std::cout << "  Объект Base удален из памяти" << std::endl;
    
}

double Base::getPrice() const {
    return price;
}

void Base::setPrice(double p) {
    if (p < 0) {
        throw std::invalid_argument{
            "Цена не может быть отрицательной "
            "Введена цена: " + std::to_string(p)
        };
    }

    if (p > 1000000) {
        throw std::invalid_argument{
            "Цена слишком высокая "
            "Максимум 1000000 руб., Введено: " + std::to_string(p)
        };
    }
    price = p;
    std::cout << "Цена успешно установлена: " << price << ".руб" << std::endl;

}

Base& Base::operator(const Base& other) {
    if (this != &other) {
        std::cout << ">>> Вызван оператор присваивания Base::operator=()" << std::endl;
        price = other.price;
        std::cout << "   Объект скопирован. Новая цена:" << price << ".руб" << std::endl;
    } else {
        std::cout << "Самоприсваивание оператора Base" << std::endl;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const &Base obj) {
    os << "Цена: " << obj.price << ".руб";
    return os
}