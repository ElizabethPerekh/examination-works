#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "library_Pereh_Header.h"

using namespace std;

int main() {
    
    // Массив функций, которые возвращают int и не имеют параметров
    const int sizeArrayChoose = 4;
    int (*arrayChoose[sizeArrayChoose])() = { chooseAction, chooseEdit, chooseSearch, chooseSort };

    FILE* fileLibrary;
    const char* pathFileLibrary = "D:\\library.txt";
    FILE* fileLibraryNew;
    const char* pathFileLibraryNew = "D:\\libraryNew.txt";

    const int MAX_BOOKS = 10;
    Books library[MAX_BOOKS] = {};
    int currentSize = 0;

    if ((fopen_s(&fileLibrary, pathFileLibrary, "r")) == 0 &&
        ((fopen_s(&fileLibraryNew, pathFileLibraryNew, "w")) == 0)) {

        fseek(fileLibrary, 0, SEEK_END);
        if (ftell(fileLibrary) == 0) cout << "File is empty" << endl; // Проверка на наличие контента в файле
        else {
            fseek(fileLibrary, 0, SEEK_SET);
            currentSize = fillArrayLibrary(fileLibrary, library);
            showFileContent(currentSize, library);

            cout << endl << endl;
        }
        fclose(fileLibrary); // Закрытие файла library.txt

        int continuation = 0;

        do {
            int action = 0;

            do {
                action = arrayChoose[0]();
                if (action < 1 || action > 5) cout << "The wrong code was entered. Try again" << endl;
            } while (action < 1 || action > 5);

            if (action == 1) { // Изменения в списке книг
                int actionEdit = 0;

                do {
                    actionEdit = arrayChoose[1]();
                    if (actionEdit < 1 || actionEdit > 3) cout << "The wrong code was entered. Try again" << endl;
                    cout << endl;
                } while (actionEdit < 1 || actionEdit > 3);

                if (actionEdit == 1) { // Добавление книги
                    if (currentSize >= MAX_BOOKS - 1) cout << "Library is full, cannot add more books" << endl;
                    else {
                        addBook(library, currentSize);
                        cout << endl << endl;
                        showFileContent(currentSize, library);
                    }
                }
                else if (actionEdit == 2) { // Удаление книги
                    int index = 0;

                    do {
                        cout << "Enter the number of the book to delete: ";
                        cin >> index;
                        if (index < 1 || index > currentSize) cout << "The wrong code was entered. Try again" << endl;
                        cout << endl;
                    } while (index < 1 || index > currentSize);

                    deleteBook(library, index - 1, currentSize);
                    cout << endl;
                    currentSize--;
                    showFileContent(currentSize, library);
                }
                else if (actionEdit == 3) { // Редактирование книги
                    int index = 0;

                    do {
                        cout << "Enter the number of the book to edit: ";
                        cin >> index;
                        if (index < 1 || index > currentSize) cout << "The wrong code was entered. Try again" << endl;
                        cout << endl;
                    } while (index < 1 || index > currentSize);

                    cout << endl;
                    editBook(library, index - 1);
                    cout << endl << endl;
                    showFileContent(currentSize, library);
                }
            }
            else if (action == 2) { // Поиск по параметрам
                int actionSearch = 0;

                do {
                    actionSearch = arrayChoose[2]();
                    if (actionSearch < 1 || actionSearch > 4) cout << "The wrong code was entered. Try again" << endl;
                } while (actionSearch < 1 || actionSearch > 4);

                char unknown[100];
                int unknownYear;
                bool check = false;

                do {

                    if (actionSearch >= 1 && actionSearch <= 3) {
                        if (actionSearch == 1) cout << "Enter the title: ";
                        else if (actionSearch == 2) cout << "Enter the author: ";
                        else if (actionSearch == 3) cout << "Enter a genre: ";
                        cin.ignore();
                        cin.getline(unknown, 100);
                        cout << endl;
                        check = searchByParameters(currentSize, library, unknown, actionSearch);
                    }
                    else {
                        cout << "Enter the year of publication: ";
                        cin >> unknownYear;
                        cout << endl;
                        check = searchByYear(currentSize, library, unknownYear);
                    }
                } while (check == false);
            }
            else if (action == 3) { // Сортировка по параметру
                int actionSort = 0;

                do {
                    actionSort = arrayChoose[3]();
                    if (actionSort < 1 || actionSort > 3) cout << "The wrong code was entered. Try again" << endl;
                    cout << endl;
                } while (actionSort < 1 || actionSort > 3);
                cout << endl;
                sortByParameters(currentSize, library, actionSort);
                showFileContent(currentSize, library);
            }
            else if (action == 4) { // Вывод списка книг по жанру
                char unknownGenre[100];
                bool check = false;

                do {
                    cout << "Enter a genre: ";
                    cin.ignore();
                    cin.getline(unknownGenre, 100);
                    cout << endl;
                    check = searchByParameters(currentSize, library, unknownGenre, 3);
                } while (check == false);
            }
            else { // Оценка книги
                int index = 0;

                do {
                    cout << "Enter the number of the book for which you want to add a rating: ";
                    cin >> index;
                    if (index < 1 || index > currentSize) cout << "The wrong code was entered. Try again" << endl;
                } while (index < 1 || index > currentSize);
                cout << endl;
                addReview(library, index - 1);
                cout << endl << endl;
                showFileContent(currentSize, library);
            }

            do {
                cout << endl << endl << "Start over?" << endl << endl;
                cout << "1 - No" << endl;
                cout << "2 - Yes" << endl << endl;

                cout << "Enter the menu code: ";
                cin >> continuation;

                if (continuation != 1 && continuation != 2) cout << "The wrong code was entered. Try again" << endl;
                cout << endl << endl;
            } while (continuation != 1 && continuation != 2); // Для исключения некорректного выбора

        } while (continuation != 1);

        addToFile(library, currentSize, fileLibraryNew);
        fclose(fileLibraryNew);
    }
    else {
        cout << "File opening error" << endl;
    }

    return 0;
}