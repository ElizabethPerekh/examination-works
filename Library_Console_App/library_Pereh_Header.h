#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace std;

struct Books {
    char title[100];  // �������� �����
    char author[100]; // ����� �����
    char genre[100];  // ���� �����
    int year;         // ��� ����������
    int rating;       // ������ �����
    char review[500]; // ����� � �����
};

// ������������ ������� �� ��������� �����
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

// ����� �� ����� ������� �� ������ ����
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

// ����� �������� �� ������� ����
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

// ����� �������� � ���� ��������������
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

// ����� �������� � ���� ������
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

// ����� �� ����� ����� ����� (��� ������)
void showSearchBook(Books* library, int index) {
    printf("%i. \"%s\" %s, %s, %i\n", (index + 1), library[index].title, library[index].author,
        library[index].genre, library[index].year);
}

// ������� �������� � ������ �������
void lowercase(char stroke[]) {
    for (int i = 0; i < strlen(stroke); i++) {
        stroke[i] = tolower(stroke[i]);
    }
}

// ����� �� ���������� ���� char
bool searchByParameters(int size, Books* library, char unknown[], int actionSearch) {
    bool check = false;
    char lower[100]; // ��� �������� ��������� � ������ ��������
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

// ����� �� ��������� ���� int (��� ����������)
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

// ����� �������� � ���� ����������
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

// ������� ��� ����� ��������� ��� ����������
void moving(Books& book1, Books& book2) {
    Books temp = book1;
    book1 = book2;
    book2 = temp;
}

// ����������� ���������� ������� �� ��������� ���������
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

// ���������� �����
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

// ������ ��������� � ����
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

// �������� �����
void deleteBook(Books library[], int indexBook, int size) {
    for (int i = indexBook; i < size - 1; i++) {
        library[i] = library[i + 1];
    }
}

// �������������� �����
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

// ���������� ������ � ������ ��� �����
void addReview(Books library[], int indexBook) {
    library[indexBook].rating = 0;
    do {
        cout << "Enter rating for the book (1-5): ";
        cin >> library[indexBook].rating;
        if (library[indexBook].rating < 1 || library[indexBook].rating > 5) cout << "The wrong rating was entered. Try again" << endl;
        cout << endl;
    } while (library[indexBook].rating < 1 || library[indexBook].rating > 5); // �������� �� ������������ ������� ������

    cin.ignore();
    cout << "Enter a short review for the book: ";
    cin.getline(library[indexBook].review, 500);
}