#include <iostream>
#include <limits>
#include "Keeper.h"
#include "Book.h"
#include "Textbook.h"
#include "Stationery.h"


void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addBook(Keeper& keeper) {
    std::string title, author, annotation, genre;
    int year, pages;
    double price;
    
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║           ДОБАВЛЕНИЕ КНИГИ                 ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    std::cout << "Название книги: ";
    std::getline(std::cin, title);
    
    std::cout << "Автор: ";
    std::getline(std::cin, author);
    
    std::cout << "Год выпуска: ";
    std::cin >> year;
    clearInput();
    
    std::cout << "Аннотация (краткое описание): ";
    std::getline(std::cin, annotation);
    
    std::cout << "Жанр (фантастика, роман, детектив и т.д.): ";
    std::getline(std::cin, genre);
    
    std::cout << "Количество страниц: ";
    std::cin >> pages;
    
    std::cout << "Цена (руб.): ";
    std::cin >> price;
    clearInput();
    
    try {
        Book* book = new Book(title, author, year, annotation, genre, pages, price);
        keeper.add(book);
        std::cout << "\n Книга успешно добавлена в магазин!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\n Ошибка при добавлении книги: " << e.what() << std::endl;
    }
}


void addTextbook(Keeper& keeper) {
    std::string title, author, institution;
    int year, studyYear, pages;
    double price;
    
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║        📖 ДОБАВЛЕНИЕ УЧЕБНИКА              ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    std::cout << "Название учебника: ";
    std::getline(std::cin, title);
    
    std::cout << "Автор: ";
    std::getline(std::cin, author);
    
    std::cout << "Год выпуска: ";
    std::cin >> year;
    clearInput();
    
    std::cout << "Учебное заведение (СШ №5, МГУ и т.д.): ";
    std::getline(std::cin, institution);
    
    std::cout << "Год обучения (класс/курс): ";
    std::cin >> studyYear;
    
    std::cout << "Количество страниц: ";
    std::cin >> pages;
    
    std::cout << "Цена (руб.): ";
    std::cin >> price;
    clearInput();
    
    try {
        Textbook* textbook = new Textbook(title, author, year, institution, studyYear, pages, price);
        keeper.add(textbook);
        std::cout << "\n✓ Учебник успешно добавлен в магазин!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\n Ошибка при добавлении учебника: " << e.what() << std::endl;
    }
}

void addStationery(Keeper& keeper) {
    std::string type, color, purpose;
    double price;
    
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║        ✏️  ДОБАВЛЕНИЕ КАНЦЕЛЯРИИ           ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    std::cout << "Тип товара (ручка, карандаш, тетрадь и т.д.): ";
    std::getline(std::cin, type);
    
    std::cout << "Цвет: ";
    std::getline(std::cin, color);
    
    std::cout << "Назначение (письмо, рисование, черчение и т.д.): ";
    std::getline(std::cin, purpose);
    
    std::cout << "Цена (руб.): ";
    std::cin >> price;
    clearInput();
    
    try {
        Stationery* stationery = new Stationery(type, color, purpose, price);
        keeper.add(stationery);
        std::cout << "\n✓ Канцелярский товар успешно добавлен в магазин!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\n❌ Ошибка при добавлении канцелярии: " << e.what() << std::endl;
    }
}


void addMenu(Keeper& keeper) {
    int choice;
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║        ЧТО ВЫ ХОТИТЕ ДОБАВИТЬ?             ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════╣" << std::endl;
    std::cout << "║ 1. 📚 Книгу                                ║" << std::endl;
    std::cout << "║ 2. 📖 Учебник                              ║" << std::endl;
    std::cout << "║ 3. ✏️  Канцелярию                          ║" << std::endl;
    std::cout << "║ 0. ⬅️  Назад                               ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    clearInput();
    
    switch(choice) {
        case 1:
            addBook(keeper);
            break;
        case 2:
            addTextbook(keeper);
            break;
        case 3:
            addStationery(keeper);
            break;
        case 0:
            std::cout << "↩️  Возврат в главное меню..." << std::endl;
            break;
        default:
            std::cout << "❌ Неверный выбор! Попробуйте снова." << std::endl;
    }
}


void removeItem(Keeper& keeper) {
    if (keeper.getSize() == 0) {
        std::cout << "\n⚠️  Магазин пуст! Нечего удалять." << std::endl;
        return;
    }
    
    keeper.display();
    std::cout << "\nВведите индекс товара для удаления (0-" << keeper.getSize()-1 << "): ";
    int index;
    std::cin >> index;
    clearInput();
    
    try {
        keeper.remove(index);
    } catch (const std::exception& e) {
        std::cout << "\n❌ Ошибка при удалении: " << e.what() << std::endl;
    }
}


void editItem(Keeper& keeper) {
    if (keeper.getSize() == 0) {
        std::cout << "\n⚠️  Магазин пуст! Нечего редактировать." << std::endl;
        return;
    }
    
    keeper.display();
    std::cout << "\nВведите индекс товара для редактирования (0-" << keeper.getSize()-1 << "): ";
    int index;
    std::cin >> index;
    clearInput();
    
    try {
        keeper.editByIndex(index);
    } catch (const std::exception& e) {
        std::cout << "\n❌ Ошибка при редактировании: " << e.what() << std::endl;
    }
}

void viewMenu(Keeper& keeper) {
    if (keeper.getSize() == 0) {
        std::cout << "\n⚠️  Магазин пуст! Добавьте товары сначала." << std::endl;
        return;
    }
    
    int choice;
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║        КАК ПРОСМОТРЕТЬ ТОВАРЫ?             ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════╣" << std::endl;
    std::cout << "║ 1. 📋 Показать все товары                  ║" << std::endl;
    std::cout << "║ 2. 🔍 Показать один товар по индексу       ║" << std::endl;
    std::cout << "║ 3. 📚 Показать только книги                ║" << std::endl;
    std::cout << "║ 4. 📖 Показать только учебники             ║" << std::endl;
    std::cout << "║ 5. ✏️  Показать только канцелярию          ║" << std::endl;
    std::cout << "║ 6. 📊 Показать статистику                  ║" << std::endl;
    std::cout << "║ 0. ⬅️  Назад                               ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    clearInput();
    
    try {
        switch(choice) {
            case 1:
                keeper.display();
                break;
            case 2: {
                std::cout << "Введите индекс товара (0-" << keeper.getSize()-1 << "): ";
                int index;
                std::cin >> index;
                clearInput();
                keeper.displayByIndex(index);
                break;
            }
            case 3:
                keeper.displayByType("Book");
                break;
            case 4:
                keeper.displayByType("Textbook");
                break;
            case 5:
                keeper.displayByType("Stationery");
                break;
            case 6:
                std::cout << keeper << std::endl;
                break;
            case 0:
                std::cout << "↩️  Возврат в главное меню..." << std::endl;
                break;
            default:
                std::cout << "❌ Неверный выбор!" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "\n❌ Ошибка: " << e.what() << std::endl;
    }
}


void saveToFile(Keeper& keeper) {
    std::string filename;
    std::cout << "\nВведите имя файла для сохранения (например: shop.dat): ";
    std::getline(std::cin, filename);
    
    try {
        keeper.saveToFile(filename);
    } catch (const std::exception& e) {
        std::cout << "\n❌ Ошибка при сохранении: " << e.what() << std::endl;
    }
}


void loadFromFile(Keeper& keeper) {
    std::string filename;
    std::cout << "\n⚠️  ВНИМАНИЕ: Текущие данные будут заменены данными из файла!" << std::endl;
    std::cout << "Введите имя файла для загрузки (например: shop.dat): ";
    std::getline(std::cin, filename);
    
    try {
        keeper.loadFromFile(filename);
    } catch (const std::exception& e) {
        std::cout << "\n❌ Ошибка при загрузке: " << e.what() << std::endl;
    }
}


void printMainMenu() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║     🏪 КНИЖНЫЙ МАГАЗИН - ГЛАВНОЕ МЕНЮ      ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════╣" << std::endl;
    std::cout << "║ 1. Добавить товар                       ║" << std::endl;
    std::cout << "║ 2. Удалить товар                        ║" << std::endl;
    std::cout << "║ 3. Просмотреть товары                  ║" << std::endl;
    std::cout << "║ 4. Редактировать товар                 ║" << std::endl;
    std::cout << "║ 5. Сохранить в файл                     ║" << std::endl;
    std::cout << "║ 6. Загрузить из файла                   ║" << std::endl;
    std::cout << "║ 0. Выход                                ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    std::cout << "Ваш выбор: ";
}


int main() {

    setlocale(LC_ALL, "Russian");
    
    std::cout << "╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   Добро пожаловать в книжный магазин!      ║" << std::endl;
    std::cout << "║   Система управления товарами              ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    

    Keeper keeper;
    
    int choice;
    bool running = true;
    

    while (running) {
        printMainMenu();
        std::cin >> choice;
        clearInput();
        
        try {
            switch(choice) {
                case 1:
                    addMenu(keeper);
                    break;
                case 2:
                    removeItem(keeper);
                    break;
                case 3:
                    viewMenu(keeper);
                    break;
                case 4:
                    editItem(keeper);
                    break;
                case 5:
                    saveToFile(keeper);
                    break;
                case 6:
                    loadFromFile(keeper);
                    break;
                case 0:
                    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
                    std::cout << "║   Спасибо за использование программы!      ║" << std::endl;
                    std::cout << "║   До свидания! 👋                          ║" << std::endl;
                    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
                    running = false;
                    break;
                default:
                    std::cout << "❌ Неверный выбор! Попробуйте снова." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "\n❌ Произошла ошибка: " << e.what() << std::endl;
        }
        
        if (running && choice != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.get();
        }
    }
    
    return 0;
}