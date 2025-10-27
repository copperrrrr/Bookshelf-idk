#include "Keeper.h"
#include "Book.h"
#include "Textbook.h"
#include "Stationery.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <limits>

Keeper::Keeper() : items(nullptr), size(0), capacity(0) {
    std::cout << ">>> Вызван конструктор по умолчанию." << std::endl;
    std::cout << "   Контейнер создан: size = " << size << ", capacity = " << capacity << std::endl;
}

Keeper::Keeper(int cap) : size(0), capacity(cap) {
    std::cout << ">>> Вызван конструктор с параметром." << std::endl;

    if (cap <= 0) {
        throw std::invalid_argument(
            "Ёмкость должна быть положительной."
            "Передано значение: " + std::to_string(cap)
        );
    }

    items = new Base*[capacity];
    std::cout << " Контейнер создал: size = " << size << ", capacity = " << capacity << std::endl;
}

Keeper::Keeper(const Keeper& other) : size(other.size), capacity(other.capacity) {
    std::cout << ">>> Вызван конструктор копирования." << std::endl;
    items = new Base*[capacity];

    for (int i = 0; i < size; ++i) {
        std::string type = other.items[i]->getType();

        if (type == "Book") {
            items[i] = new Book(*dynamic_cast<Book*>(other.items[i]));

        }
        else if (type == "Textbook") {
            items[i] = new Textbook(*dynamic_cast<Textbook*>(other.items[i]));
        }
        else if (type == "Stationery") {
            items[i] = new Stationery(*dynamic_cast<Stationery*>(other.items[i]));
        }
        else {
            throw std::runtime_error("Неизвестный тип при копировании.");
        }
    }

    std::cout << "   Скопировано товаров: " << size << " из " << other.size << std::endl;
}

Keeper::~Keeper() {
    std::cout << ">>> Вызван деструктор." << std::endl;
    for (int i = 0; i < size; ++i) {
        delete items[i];
    }

    delete[] items;

    std::cout << "   Контейнер удален из памяти. (удалено " << size << " товаров)" << std::endl;
}

void Keeper::resize() {
    std::cout << ">>> Вызов метода resize." << std::endl;
    std::cout << "  Текущая емкость: " << capacity << std::endl;

    int newCapacity = (capacity == 0) ? 1 : capacity * 2;

    Base** newItems = new Base*[newCapacity];

    for (int i = 0; i < size; ++i) {
        newItems[i] = items[i];
    }
    delete[] items;

    items = newItems;
    capacity = newCapacity;

    std::cout << "  Новая емкость: " << capacity << std::endl;
}

void Keeper::add(Base* item) {
    if (item == nullptr) {
        throw std::invalid_argument(
            "Попытка добавить нулевой указатель."
        );
    };
    std::cout << ">>> Добавление товара типа: " << item->getType() << std::endl;

    if (size >= capacity) {
        std::cout << "   Контейнер полный (size = capacity = " << size << ")" << std::endl;
        resize();
    }

    items[size] = item;
    size++;

    std::cout << "   Товар добавлен успешно." << std::endl;
    std::cout << "   Текущее количество товаров: " << size << " из " << capacity << std::endl;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range(
            "Индекс вне диапазона."
            "Индекс: " + std::to_string(index) +
            ", размер контейнера: " + std::to_string(size)
        );
    }
    std::cout << ">>> Удаление товара с индексом: " << index << std::endl;

    delete items[index];
    std::cout << "   Товар удален из памяти" << std::endl;

    for (int i = index; i < size - 1; ++i) {
        items[i] = items[i + 1];
    }

    size--;

    std::cout << "  Товар успешно удален." << std::endl;
    std::cout << "  Осталось товаров: " << size << std::endl;
}


void Keeper::display() const {
    if (size == 0) {
        std::cout << "Контейнер пуст. Выводить нечего." << std::endl;
        return;
    }

    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║      ВСЕ ТОВАРЫ В МАГАЗИНЕ (" << size << " шт)          ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;

    for (int i = 0; i < size; ++i) {
        std::cout << "\n───────────────────────────────────────────" << std::endl;
        std::cout << "Товар [" << i << "]:" << std::endl;
        std::cout << "───────────────────────────────────────────" << std::endl;
        items[i]->display();
    }

    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║ Всего товаров: " << size << " / " << capacity << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
}

void Keeper::displayByIndex(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range(
            "Индекс вне диапазона."
            "Индекс: " + std::to_string(index) +
            ", размер контейнера: " + std::to_string(size)
        );
    }
    std::cout << "\n───────────────────────────────────────────" << std::endl;
    std::cout << "Товар [" << index << "]:" << std::endl;
    std::cout << "───────────────────────────────────────────" << std::endl;
    items[index]->display();
}

void Keeper::displayByType(const std::string& itemType) const {
    if (size == 0) {
        std::cout << "Контейнер пуст." << std::endl;
        return;
    }

    bool found = false;
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║      ТОВАРЫ ТИПА: " << itemType << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    
    for (int i = 0; i < size; ++i) {
        if (items[i]->getType() == itemType) {
            std::cout << "\n───────────────────────────────────────────" << std::endl;
            std::cout << "Товар [" << i << "]:" << std::endl;
            std::cout << "───────────────────────────────────────────" << std::endl;
            items[i]->display();
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "\n Товары типа '" << itemType << "' не найдены." << std::endl;
    }
}


void Keeper::editByIndex(int index) {
    
    if (index < 0 || index >= size) {
        throw std::out_of_range(
            "Индекс вне диапазона. "
            "Индекс: " + std::to_string(index) + 
            ", размер контейнера: " + std::to_string(size)
        );
    }
    
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║      РЕДАКТИРОВАНИЕ ТОВАРА [" << index << "]" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    items[index]->edit();
}

void Keeper::saveToFile(const std::string& filename) const {

    std::ofstream out(filename);
    
    if (!out.is_open()) {
        throw std::runtime_error(
            "Не удалось открыть файл для записи. " + filename
        );
    }
    
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║      СОХРАНЕНИЕ В ФАЙЛ: " << filename << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    out << size << "\n";
    std::cout << "    Записано товаров: " << size << std::endl;
    
    for (int i = 0; i < size; ++i) {
        std::cout << "    [" << i << "] Сохранение товара типа " << items[i]->getType() << "..." << std::endl;
        items[i]->saveToFile(out);
    }
    
    out.close();
    
    std::cout << "    Данные успешно сохранены в файл: " << filename << std::endl;
}


void Keeper::loadFromFile(const std::string& filename) {
    
    std::ifstream in(filename);
    
    if (!in.is_open()) {
        throw std::runtime_error(
            "Не удалось открыть файл для чтения: " + filename
        );
    }

    std::cout << "╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║      ЗАГРУЗКА ИЗ ФАЙЛА: " << filename << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    
    std::cout << "    Очистка текущих данных..." << std::endl;
    for (int i = 0; i < size; ++i) {
        delete items[i];
    }
    delete[] items;
    
  
    int newSize;
    in >> newSize;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "    Количество товаров в файле: " << newSize << std::endl;
    

    if (newSize < 0) {
        throw std::runtime_error(
            "Некорректное количество товаров в файле: " + 
            std::to_string(newSize)
        );
    }
    
  
    size = 0;
    capacity = (newSize > 0) ? newSize : 1;
    items = new Base*[capacity];
    
    
    for (int i = 0; i < newSize; ++i) {
        
        std::string type;
        std::getline(in, type);
        
        std::cout << "    [" << i << "] Загрузка товара типа " << type << "..." << std::endl;
        
        Base* newItem = nullptr;
        
        
        if (type == "Book") {
            newItem = new Book();
        } 
        else if (type == "Textbook") {
            newItem = new Textbook();
        } 
        else if (type == "Stationery") {
            newItem = new Stationery();
        } 
        else {
            throw std::runtime_error(
                "Неизвестный тип объекта в файле: " + type
            );
        }
        
     
        newItem->loadFromFile(in);
        
       
        items[size] = newItem;
        size++;
    }
    

    in.close();
    
    std::cout << "    Данные успешно загружены из файла: " << filename << std::endl;
    std::cout << "    Загружено товаров: " << size << std::endl;
}



int Keeper::getSize() const {
    return size;
}


int Keeper::getCapacity() const {
    return capacity;
}

Base* Keeper::getItem(int index) const {
  
    if (index < 0 || index >= size) {
        throw std::out_of_range(
            "Индекс вне диапазона"
            "Индекс: " + std::to_string(index) + 
            ", размер контейнера: " + std::to_string(size)
        );
    }
    
    return items[index];
}

// Подсчитывает количество товаров определенного типа
int Keeper::countByType(const std::string& itemType) const {
    int count = 0;
    
    for (int i = 0; i < size; ++i) {
        if (items[i]->getType() == itemType) {
            count++;
        }
    }
    
    return count;
}



Keeper& Keeper::operator=(const Keeper& other) {
    
    if (this != &other) {
        std::cout << ">>> Вызван оператор присваивания." << std::endl;
        
        
        for (int i = 0; i < size; ++i) {
            delete items[i];
        }
        delete[] items;
        
    
        size = other.size;
        capacity = other.capacity;
        
        
        items = new Base*[capacity];
        
        for (int i = 0; i < size; ++i) {
            std::string type = other.items[i]->getType();
            
            if (type == "Book") {
                items[i] = new Book(*dynamic_cast<Book*>(other.items[i]));
            } 
            else if (type == "Textbook") {
                items[i] = new Textbook(*dynamic_cast<Textbook*>(other.items[i]));
            } 
            else if (type == "Stationery") {
                items[i] = new Stationery(*dynamic_cast<Stationery*>(other.items[i]));
            }
        }
        
        std::cout << "    Контейнеры успешно скопированы" << std::endl;
        std::cout << "    Скопировано товаров: " << size << std::endl;
    } 
    else {
        std::cout << "Самоприсваивание контейнера Keeper." << std::endl;
    }
    
    return *this;
}


Base* Keeper::operator[](int index) const {
    return getItem(index);
}


std::ostream& operator<<(std::ostream& os, const Keeper& keeper) {
    if (keeper.size == 0) {
        os << "Контейнер пуст (size = 0)";
        return os;
    }
    
    os << "╔════════════════════════════════════════╗\n";
    os << "║  Информация о контейнере Keeper\n";
    os << "╠════════════════════════════════════════╣\n";
    os << "║  Количество товаров: " << keeper.size << "\n";
    os << "║  Емкость контейнера: " << keeper.capacity << "\n";
    
    // Подсчитываем количество каждого типа
    int books = 0, textbooks = 0, stationery = 0;
    for (int i = 0; i < keeper.size; ++i) {
        if (keeper.items[i]->getType() == "Book") books++;
        else if (keeper.items[i]->getType() == "Textbook") textbooks++;
        else if (keeper.items[i]->getType() == "Stationery") stationery++;
    }
    
    os << "║  - Книг: " << books << "\n";
    os << "║  - Учебников: " << textbooks << "\n";
    os << "║  - Канцелярии: " << stationery << "\n";
    os << "╚════════════════════════════════════════╝";
    
    return os;
}