#include <iostream>
#include "Header_Tic-Tac-Toe_Pereh.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    // Массив функций, которые возвращают int и не имеют параметров
    const int sizeArrayChoose = 2;
    int (*arrayChoose[sizeArrayChoose])() = { chooseStrategy, chooseComplexity };

    int size = 0;
    int continuation = 0;

    do {
        int strategy = 0;
        do {
            strategy = arrayChoose[0]();
            if (strategy != 1 && strategy != 2) cout << "Введён неверный код. Попробуйте снова." << endl;
            cout << endl << endl;
        } while (strategy != 1 && strategy != 2); // Для исключения некорректного выбора

        int complexity = 0;

        do {
            complexity = arrayChoose[1]();
            if (complexity != 1 && complexity != 2 && complexity != 3) cout << "Введён неверный код. Попробуйте снова." << endl;
            cout << endl << endl;
        } while (complexity != 1 && complexity != 2 && complexity != 3); // Для исключения некорректного выбора

        if (complexity == 1) size = 3;
        else if (complexity == 2) size = 5;
        else size = 10;

        char** board = createBoard(size);

        // Массив функций, которые возвращают void и имеют 2 параметра: char**, int
        const int sizeArrayTypeGame = 2;
        void (*arrayTypeGame[sizeArrayTypeGame])(char**, int) = { gameComputer, gamePerson };

        if (strategy == 1) {
            arrayTypeGame[0](board, size);
            counter.gamesComputer++;
        }
        else {
            arrayTypeGame[1](board, size);
            counter.gamesPerson++;
        }

        for (int i = 0; i < size; i++) delete[] board[i];
        delete[] board;
        cout << endl << endl;

        do {
            cout << "Начать заново?" << endl << endl;
            cout << "1 - Нет" << endl;
            cout << "2 - Да" << endl << endl;

            cout << "Введите код меню: ";
            cin >> continuation;

            if (continuation != 1 && continuation != 2) cout << "Введён неверный код. Попробуйте снова." << endl;
            cout << endl << endl;
        } while (continuation != 1 && continuation != 2); // Для исключения некорректного выбора

    } while (continuation != 1);

    cout << "----- Статистика игры -----" << endl << endl;
    if (counter.gamesPerson != 0) {
        cout << "Количество игр с человеком: " << counter.gamesPerson << endl;
        cout << "Количество побед игрока X: " << counter.winsPersonX << endl;
        cout << "Количество побед игрока O: " << counter.winsPersonO << endl;
        cout << "Количество ничьих: " << counter.drawPerson << endl << endl;
    }
    if (counter.gamesComputer != 0) {
        cout << "Количество игр с компьютером: " << counter.gamesComputer << endl;
        cout << "Количество побед человека: " << counter.winsPerson << endl;
        cout << "Количество побед компьюетра: " << counter.winsComputer << endl;
        cout << "Количество ничьих: " << counter.drawComputer << endl;
    }

    return 0;
}