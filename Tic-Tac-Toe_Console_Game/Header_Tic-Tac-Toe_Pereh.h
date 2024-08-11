#pragma once

#include <iostream>
#include <time.h>

using namespace std;

// Выбор стратегии игры
int chooseStrategy() {
    int strategy;

    cout << "----- Стратегия игры -----" << endl << endl;
    cout << "1 - Игра против компьютера" << endl;
    cout << "2 - Игра против человека" << endl << endl;

    cout << "Введите код стратегии: ";
    cin >> strategy;

    return strategy;
}

// Выбор уровня сложности игры
int chooseComplexity() {
    int complexity;

    cout << "----- Уровни сложности -----" << endl << endl;
    cout << "1 - Easy. Поле 3 х 3" << endl;
    cout << "2 - Normal. Поле 5 х 5" << endl;
    cout << "3 - Hard. Поле 10 х 10" << endl << endl;

    cout << "Введите код уровня сложности: ";
    cin >> complexity;

    return complexity;
}

// Создание и заполнение динамического двумерного массива board
char** createBoard(int size) {
    char** board = new char* [size];
    for (int i = 0; i < size; i++) board[i] = new char[size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) board[i][j] = ' ';
    }
    return board;
}

// Отображение игрового поля
void displayBoard(char** board, int size) {
    cout << "     ";
    for (int k = 1; k <= size; k++) {
        cout << k;
        if (k < size) cout << "   ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << " " << i + 1 << "   ";
        for (int j = 0; j < size; j++) {
            cout << board[i][j];
            if (j < size - 1) cout << " | ";
        }
        cout << endl;
        if (i < size - 1) {
            cout << "   ";
            for (int l = 0; l <= size * 2 - 1; l++) cout << "--";
            cout << endl;
        }
    }
}

// Статистика игр
struct statistics {
    int gamesPerson = 0;
    int gamesComputer = 0;
    int winsPersonX = 0;
    int winsPersonO = 0;
    int winsComputer = 0;
    int winsPerson = 0;
    int drawPerson = 0;
    int drawComputer = 0;
} counter;

// Определение победителя
bool checkWinner(char** board, char player, int size) {
    // Проверка строк
    for (int i = 0; i < size; i++) {
        bool win = true;
        for (int j = 0; j < size; j++) {
            if (board[i][j] != player) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    // Проверка столбцов
    for (int i = 0; i < size; i++) {
        bool win = true;
        for (int j = 0; j < size; j++) {
            if (board[j][i] != player) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    // Проверка диагоналей
    bool win1 = true;
    bool win2 = true;
    for (int i = 0; i < size; i++) {
        if (board[i][i] != player) win1 = false;
        if (board[i][size - 1 - i] != player) win2 = false;
    }
    if (win1 || win2) return true;

    return false;
}

// Игра человек - человек
void gamePerson(char** board, int size) {
    char currentPlayer = 'x';

    while (true) {
        displayBoard(board, size);
        cout << endl;

        int row, col;
        cout << "Игрок " << currentPlayer << ", введите ваш ход" << endl;
        cout << "Строка: ";
        cin >> row;
        cout << "Столбец: ";
        cin >> col;
        cout << endl;

        if (row <= 0 || row > size || col <= 0 || col > size || board[row - 1][col - 1] != ' ') {
            cout << "Недопустимый ход! Попробуйте снова." << endl << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWinner(board, currentPlayer, size)) {
            displayBoard(board, size);
            cout << endl;
            cout << "Игрок " << currentPlayer << " победил!" << endl;
            if (currentPlayer == 'x') counter.winsPersonX++;
            else counter.winsPersonO++;
            break;
        }

        bool isBoardFull = true;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == ' ') {
                    isBoardFull = false;
                    break;
                }
            }
        }

        if (isBoardFull) {
            displayBoard(board, size);
            cout << endl;
            cout << "Ничья!" << endl;
            counter.drawPerson++;
            break;
        }
        currentPlayer = (currentPlayer == 'x') ? 'o' : 'x';
    }
}

// Ход компьютера
void computerMove(char** board, int size) {
    int row, col;
    do {
        row = rand() % size;
        col = rand() % size;
    } while (board[row][col] != ' ');

    cout << "Компьютер сделал ход: " << (row + 1) << ", " << (col + 1) << endl << endl;
    board[row][col] = 'o';
}

// Игра человек - компьютер
void gameComputer(char** board, int size) {
    char currentPlayer = 'x';

    while (true) {
        displayBoard(board, size);
        cout << endl;

        if (currentPlayer == 'x') {
            int row, col;
            cout << "Игрок " << currentPlayer << ", введите ваш ход" << endl;
            cout << "Строка: ";
            cin >> row;
            cout << "Столбец: ";
            cin >> col;
            cout << endl;

            if (row <= 0 || row > size || col <= 0 || col > size || board[row - 1][col - 1] != ' ') {
                cout << "Недопустимый ход! Попробуйте снова." << endl << endl;
                continue;
            }

            board[row - 1][col - 1] = currentPlayer;

            if (checkWinner(board, currentPlayer, size)) {
                displayBoard(board, size);
                cout << endl;
                cout << "Игрок " << currentPlayer << " победил!" << endl;
                counter.winsPerson++;
                break;
            }

            bool isBoardFull = true;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (board[i][j] == ' ') {
                        isBoardFull = false;
                        break;
                    }
                }
            }

            if (isBoardFull) {
                displayBoard(board, size);
                cout << endl;
                cout << "Ничья!" << endl;
                counter.drawComputer++;
                break;
            }
        }
        else {
            computerMove(board, size);

            if (checkWinner(board, 'o', size)) {
                displayBoard(board, size);
                cout << endl;
                cout << "Компьютер победил!" << endl;
                counter.winsComputer++;
                break;
            }
        }
        currentPlayer = (currentPlayer == 'x') ? 'o' : 'x';
    }
}