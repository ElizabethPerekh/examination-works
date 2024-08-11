#include "Menu.h"

void Menu::setAttemptCounter() {
    attemptCounter++;
}

int Menu::getAttemptCounter() {
    return attemptCounter;
}

void Menu::setRoundCounter() {
    roundCounter++;
}

int Menu::getRoundCounter() {
    return roundCounter;
}

int Menu::showStartMenu() {
    int topicChoice;

    do {
        cout << "----- Меню игры -----" << endl << endl;
        cout << "Выбор темы:" << endl;
        cout << "1 - Природа" << endl;
        cout << "2 - Животные" << endl;
        cout << "3 - Еда" << endl << endl;

        cout << "Введите код выбранной темы: ";
        cin >> topicChoice;

        if (topicChoice < 1 || topicChoice > 3)
            cout << "Некорректный ввод. Повторите попытку" << endl << endl;

    } while (topicChoice < 1 || topicChoice > 3);

    return topicChoice;
}

void Menu::showOutcome(bool checkUnderline) {
    if (checkUnderline)
        cout << "Вы выиграли!" << endl << endl;
    else
        cout << "Вы проиграли!" << endl << endl;
}

void Menu::showGameStatisticsMenu(string hiddenWord, UserWords& letters) {
    cout << "----- Статистика " << roundCounter << " раунда игры -----" << endl << endl;
    cout << "Количество времени: " << clock() / 1000.0 << endl;
    cout << "Количество попыток: " << attemptCounter << endl;
    cout << "Искомое слово: " << hiddenWord << endl;
    cout << "Введённые буквы: ";
    letters.printLetters();
    cout << endl;
}

int Menu::showRoundMenu() {
    int roundChoice;

    do {
        cout << endl << "Начать новый раунд?" << endl;
        cout << "1 - Да" << endl;
        cout << "2 - Нет" << endl << endl;

        cout << "Введите код меню: ";
        cin >> roundChoice;

        if (roundChoice < 1 || roundChoice > 2)
            cout << "Некорректный ввод. Повторите попытку" << endl << endl;
        else
            cout << endl << endl;

    } while (roundChoice < 1 || roundChoice > 2);

    return roundChoice;
}