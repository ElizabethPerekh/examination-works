#pragma once

#include <iostream>
#include <time.h>

using namespace std;

// ����� ��������� ����
int chooseStrategy() {
    int strategy;

    cout << "----- ��������� ���� -----" << endl << endl;
    cout << "1 - ���� ������ ����������" << endl;
    cout << "2 - ���� ������ ��������" << endl << endl;

    cout << "������� ��� ���������: ";
    cin >> strategy;

    return strategy;
}

// ����� ������ ��������� ����
int chooseComplexity() {
    int complexity;

    cout << "----- ������ ��������� -----" << endl << endl;
    cout << "1 - Easy. ���� 3 � 3" << endl;
    cout << "2 - Normal. ���� 5 � 5" << endl;
    cout << "3 - Hard. ���� 10 � 10" << endl << endl;

    cout << "������� ��� ������ ���������: ";
    cin >> complexity;

    return complexity;
}

// �������� � ���������� ������������� ���������� ������� board
char** createBoard(int size) {
    char** board = new char* [size];
    for (int i = 0; i < size; i++) board[i] = new char[size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) board[i][j] = ' ';
    }
    return board;
}

// ����������� �������� ����
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

// ���������� ���
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

// ����������� ����������
bool checkWinner(char** board, char player, int size) {
    // �������� �����
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

    // �������� ��������
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

    // �������� ����������
    bool win1 = true;
    bool win2 = true;
    for (int i = 0; i < size; i++) {
        if (board[i][i] != player) win1 = false;
        if (board[i][size - 1 - i] != player) win2 = false;
    }
    if (win1 || win2) return true;

    return false;
}

// ���� ������� - �������
void gamePerson(char** board, int size) {
    char currentPlayer = 'x';

    while (true) {
        displayBoard(board, size);
        cout << endl;

        int row, col;
        cout << "����� " << currentPlayer << ", ������� ��� ���" << endl;
        cout << "������: ";
        cin >> row;
        cout << "�������: ";
        cin >> col;
        cout << endl;

        if (row <= 0 || row > size || col <= 0 || col > size || board[row - 1][col - 1] != ' ') {
            cout << "������������ ���! ���������� �����." << endl << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWinner(board, currentPlayer, size)) {
            displayBoard(board, size);
            cout << endl;
            cout << "����� " << currentPlayer << " �������!" << endl;
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
            cout << "�����!" << endl;
            counter.drawPerson++;
            break;
        }
        currentPlayer = (currentPlayer == 'x') ? 'o' : 'x';
    }
}

// ��� ����������
void computerMove(char** board, int size) {
    int row, col;
    do {
        row = rand() % size;
        col = rand() % size;
    } while (board[row][col] != ' ');

    cout << "��������� ������ ���: " << (row + 1) << ", " << (col + 1) << endl << endl;
    board[row][col] = 'o';
}

// ���� ������� - ���������
void gameComputer(char** board, int size) {
    char currentPlayer = 'x';

    while (true) {
        displayBoard(board, size);
        cout << endl;

        if (currentPlayer == 'x') {
            int row, col;
            cout << "����� " << currentPlayer << ", ������� ��� ���" << endl;
            cout << "������: ";
            cin >> row;
            cout << "�������: ";
            cin >> col;
            cout << endl;

            if (row <= 0 || row > size || col <= 0 || col > size || board[row - 1][col - 1] != ' ') {
                cout << "������������ ���! ���������� �����." << endl << endl;
                continue;
            }

            board[row - 1][col - 1] = currentPlayer;

            if (checkWinner(board, currentPlayer, size)) {
                displayBoard(board, size);
                cout << endl;
                cout << "����� " << currentPlayer << " �������!" << endl;
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
                cout << "�����!" << endl;
                counter.drawComputer++;
                break;
            }
        }
        else {
            computerMove(board, size);

            if (checkWinner(board, 'o', size)) {
                displayBoard(board, size);
                cout << endl;
                cout << "��������� �������!" << endl;
                counter.winsComputer++;
                break;
            }
        }
        currentPlayer = (currentPlayer == 'x') ? 'o' : 'x';
    }
}