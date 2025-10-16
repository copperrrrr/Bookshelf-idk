# Книжный магазин - Система управления товарами

## Описание
Программа для управления товарами книжного магазина с использованием контейнера Keeper.

## Возможности
- Хранение книг, учебников и канцелярии
- Добавление и удаление товаров
- Редактирование данных
- Сохранение и загрузка из файла
- Обработка исключений

## Компиляция

### Linux/macOS:
g++ -std=c++11 Base.cpp Book.cpp Textbook.cpp Stationery.cpp Keeper.cpp main.cpp -o bookstore
### Windows (MinGW):
g++ -std=c++11 Base.cpp Book.cpp Textbook.cpp Stationery.cpp Keeper.cpp main.cpp -o bookstore.exe
## Запуск
./bookstore
## Структура классов
- Base - базовый абстрактный класс
- Book - класс для книг
- Textbook - класс для учебников
- Stationery - класс для канцелярии
- Keeper - контейнер для управления объектами

## Автор
[Nick]

## Лицензия
MIT
