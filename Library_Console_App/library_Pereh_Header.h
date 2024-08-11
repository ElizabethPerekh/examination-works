#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace std;

struct Books {
    char title[100];  // Название книги
    char author[100]; // Автор книги
    char genre[100];  // Жанр книги
    int year;         // Год публикации
    int rating;       // Оценка книги
    char review[500]; // Отзыв о книге
};

// Формирование массива из элементов файла
int fillArrayLibrary(FILE* fileLibrary, Books library[]) {
    char line[100];
    char* buffer;
    int indexBook = 0;

    while (fgets(line, sizeof(line), fileLibrary)) {
        buffer = strtok(line, "|");
        strcpy(library[indexBook].title, buffer);

        buffer = strtok(NULL, "|");
        strcpy(library[indexBook].author, buffer);

        buffer = strtok(NULL, "|");
        strcpy(library[indexBook].genre, buffer);

        buffer = strtok(NULL, "|");
        library[indexBook].year = atoi(buffer);

        indexBook++;
    }

    return indexBook;
}

// Вывод на экран массива из списка книг
void showFileContent(int size, Books library[]) {
    cout << "----- The current contents of the file -----" << endl << endl;
    for (int i = 0; i < size; i++) {
        if (library[i].rating == 0 || library[i].review == 0) {
            printf("%i. \"%s\" %s, %s, %i\n", (i + 1), library[i].title,
                library[i].author, library[i].genre, library[i].year);
        }
        else {
            printf("%i. \"%s\" %s, %s, %i\nRating: %i\nReview: %s\n", (i + 1), library[i].title,
                library[i].author, library[i].genre, library[i].year, library[i].rating, library[i].review);
        }
    }
}

// Выбор действия со списком книг
int chooseAction() {
    int menuAction;

    cout << "----- Menu -----" << endl << endl;
    cout << "1. Add, delete, or edit a book" << endl;
    cout << "2. Search by parameters" << endl;
    cout << "3. Sort the file content" << endl;
    cout << "4. Show a list of books by genre" << endl;
    cout << "5. Rate the book" << endl << endl;

    cout << "Enter the menu code: ";
    cin >> menuAction;

    return menuAction;
}

// Выбор действия в меню редактирования
int chooseEdit() {
    int menuEdit;

    cout << endl << "----- Edit Menu -----" << endl << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Delete a book" << endl;
    cout << "3. Edit a book" << endl << endl;

    cout << "Enter the menu code: ";
    cin >> menuEdit;

    return menuEdit;
}

// Выбор действия в меню поиска
int chooseSearch() {
    int menuSearch;

    cout << endl << "----- Search Menu -----" << endl << endl;
    cout << "1. By title" << endl;
    cout << "2. By the author" << endl;
    cout << "3. By genre" << endl;
    cout << "4. By year of publication" << endl << endl;

    cout << "Enter the menu code: ";
    cin >> menuSearch;

    return menuSearch;
}

// Вывод на экран одной книги (для поиска)
void showSearchBook(Books* library, int index) {
    printf("%i. \"%s\" %s, %s, %i\n", (index + 1), library[index].title, library[index].author,
        library[index].genre, library[index].year);
}

// Перевод символов в нижний регистр
void lowercase(char stroke[]) {
    for (int i = 0; i < strlen(stroke); i++) {
        stroke[i] = tolower(stroke[i]);
    }
}

// Поиск по параметрам типа char
bool searchByParameters(int size, Books* library, char unknown[], int actionSearch) {
    bool check = false;
    char lower[100]; // Для хранения симвволов в нижнем регистре
    lowercase(unknown);

    for (int i = 0; i < size; i++) {
        if (actionSearch == 1) {
            strcpy(lower, library[i].title);
            lowercase(lower);
            if (strstr(lower, unknown) != NULL) {
                check = true;
                showSearchBook(library, i);
            }
        }
        else if (actionSearch == 2) {
            strcpy(lower, library[i].author);
            lowercase(lower);
            if (strstr(lower, unknown) != NULL) {
                check = true;
                showSearchBook(library, i);
            }
        }
        else if (actionSearch == 3) {
            strcpy(lower, library[i].genre);
            lowercase(lower);
            if (strstr(lower, unknown) != NULL) {
                check = true;
                showSearchBook(library, i);
            }
        }
    }

    if (check == false) cout << "The book was not found!" << endl << endl;

    return check;
}

// Поиск по параметру типа int (год публикации)
bool searchByYear(int size, Books* library, int unknownYear) {
    bool check = false;

    for (int i = 0; i < size; i++) {
        if (unknownYear == library[i].year) {
            check = true;
            showSearchBook(library, i);
        }
    }

    if (check == false) cout << "The book was not found!" << endl << endl;

    return check;
}

// Выбор действия в меню сортировки
int chooseSort() {
    int menuSort;

    cout << endl << "----- Sort Menu -----" << endl << endl;
    cout << "1. By title" << endl;
    cout << "2. By the author" << endl;
    cout << "3. By year of publication" << endl << endl;

    cout << "Enter the menu code: ";
    cin >> menuSort;

    return menuSort;
}

// Функция для смены элементов при сортировке
void moving(Books& book1, Books& book2) {
    Books temp = book1;
    book1 = book2;
    book2 = temp;
}

// Пузырьковая сортировка массива по заданному параметру
void sortByParameters(int size, Books library[], int actionSort) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            if (actionSort == 1 && strcmp(library[j].title, library[j + 1].title) > 0) {
                moving(library[j], library[j + 1]);
            }
            else if (actionSort == 2 && strcmp(library[j].author, library[j + 1].author) > 0) {
                moving(library[j], library[j + 1]);
            }
            else if (actionSort == 3 && library[j].year > library[j + 1].year) {
                moving(library[j], library[j + 1]);
            }
        }
    }
}

// Добавление книги
void addBook(Books library[], int& indexBook) {
    cout << "----- Adding a book -----" << endl << endl;
    cout << "Enter title: ";
    cin.ignore();
    cin.getline(library[indexBook].title, 100);

    cout << "Enter author: ";
    cin.getline(library[indexBook].author, 100);

    cout << "Enter genre: ";
    cin.getline(library[indexBook].genre, 100);

    cout << "Enter year: ";
    cin >> library[indexBook].year;

    indexBook++;
}

// Запись изменений в файл
void addToFile(Books library[], int size, FILE* fileLibrary) {
    for (int i = 0; i < size; i++) {
        if (library[i].rating == 0 || library[i].review == 0) {
            fprintf(fileLibrary, "%i. \"%s\" %s, %s, %i\n", (i + 1), library[i].title,
                library[i].author, library[i].genre, library[i].year);
        }
        else {
            fprintf(fileLibrary, "%i. \"%s\" %s, %s, %i\nRating: %i\nReview: %s\n", (i + 1), library[i].title,
                library[i].author, library[i].genre, library[i].year, library[i].rating, library[i].review);
        }
    }
}

// Удаление книги
void deleteBook(Books library[], int indexBook, int size) {
    for (int i = indexBook; i < size - 1; i++) {
        library[i] = library[i + 1];
    }
}

// Редактирование книги
void editBook(Books library[], int indexBook) {
    cout << "----- Adding a book -----" << endl << endl;
    cout << "Enter title: ";
    cin.ignore();
    cin.getline(library[indexBook].title, 100);

    cout << "Enter author: ";
    cin.getline(library[indexBook].author, 100);

    cout << "Enter genre: ";
    cin.getline(library[indexBook].genre, 100);

    cout << "Enter year: ";
    cin >> library[indexBook].year;
}

// Добавление оценки и отзыва для книги
void addReview(Books library[], int indexBook) {
    library[indexBook].rating = 0;
    do {
        cout << "Enter rating for the book (1-5): ";
        cin >> library[indexBook].rating;
        if (library[indexBook].rating < 1 || library[indexBook].rating > 5) cout << "The wrong rating was entered. Try again" << endl;
        cout << endl;
    } while (library[indexBook].rating < 1 || library[indexBook].rating > 5); // Проверка на корректность введёной оценки

    cin.ignore();
    cout << "Enter a short review for the book: ";
    cin.getline(library[indexBook].review, 500);
}